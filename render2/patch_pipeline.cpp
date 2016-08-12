#include "patch_pipeline.h"

#include "shader.h"
#include "load_file.h"

namespace planet_engine
{
	static size_t n = 0;

	template<typename T>
	bool is_failed(const T& v)
	{
		return v.state == T::ERROR_STATE;
	}

	void patch_pipeline::upsample(std::shared_ptr<patch> patch)
	{
		if (!can_upsample(patch))
		{
			assert(false);
			return;
		}

		_waiting.emplace(upsample_state(patch, this));
	}
	void patch_pipeline::generate(std::shared_ptr<patch> patch)
	{
		_waiting.emplace(generate_state(patch, this));
	}
	void patch_pipeline::remove(std::shared_ptr<patch> patch)
	{
		_waiting.emplace(remove_state(patch, this));
	}

	void patch_pipeline::cull()
	{
		std::vector<std::shared_ptr<patch>> tr;

		for (const auto& p : _offsets)
		{
			if (p.first->parent.expired() && p.first->level != 0)
				tr.push_back(p.first);
		}

		for (const auto& p : tr)
			remove(p);
	}

	bool patch_pipeline::generate_state::is_done() const
	{
		return state == DONE;
	}
	bool patch_pipeline::upsample_state::is_done() const
	{
		return state == DONE;
	}
	bool patch_pipeline::remove_state::is_done() const
	{
		return state == DONE;
	}

	void patch_pipeline::generate_state::step()
	{
		static constexpr size_t VERTEX_BUFFER_SIZE = (SIDE_LEN + 2) * (SIDE_LEN + 2) * sizeof(float) * 4;
		static constexpr size_t NUM_INVOCATIONS = ((SIDE_LEN + 2) * (SIDE_LEN + 2) + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;
		static constexpr size_t GEN_VERTEX_INVOCATIONS = (SIDE_LEN + 2 + 7) / 7;

		switch (state)
		{
		case planet_engine::patch_pipeline::generate_state::START:
		{
			glGenBuffers(1, &vertex_buffer);
			glGenBuffers(1, &uniform);

			glBindBuffer(GL_SHADER_STORAGE_BUFFER, vertex_buffer);
			glBufferStorage(GL_SHADER_STORAGE_BUFFER, VERTEX_BUFFER_SIZE, nullptr, 0);

			mesh_info info =
			{
				target_patch->pos,
				target_patch->data->planet_radius,
				target_patch->nwc,
				SKIRT_DEPTH,
				target_patch->nec,
				1.0, // Scale
				target_patch->swc,
				0.0, //Padding
				target_patch->sec
			};

			glBindBuffer(GL_UNIFORM_BUFFER, uniform);
			glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info), &info, GL_STATIC_DRAW);

			offset = pipeline->_manager.alloc_block();

			state = GEN_VERTEX_ARRAY;
			OutputDebug("[PIPELINE] Generated patch ", target_patch.get(), ". There are ", ++n, " patches.\n");
			break;
		}
		case planet_engine::patch_pipeline::generate_state::GEN_VERTEX_ARRAY:
			glUseProgram(pipeline->_vertex_gen);
			// Bind ouput buffer
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertex_buffer);
			// Bind uniforms
			glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniform);
			// Dispatch compute shader to fill the output buffer
			glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, 1);
			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

			state = GEN_MESH;
			break;
		case planet_engine::patch_pipeline::generate_state::GEN_MESH:
			glUseProgram(pipeline->_meshgen);
			// Bind input buffer
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertex_buffer);
			// Bind output buffer range
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, pipeline->_manager.buffer(),
				offset * pipeline->_manager.block_size(), pipeline->_manager.block_size());
			// Bind Uniforms
			glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniform);
			// Dispatch compute shader to fill the output buffer
			glDispatchCompute(NUM_INVOCATIONS, 1, 1);
			glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

			// Generate buffers
			glDeleteBuffers(1, &uniform);
			glDeleteBuffers(1, &vertex_buffer);

			pipeline->_offsets.insert(std::make_pair(target_patch, offset));

			state = DONE;
			break;
		default:
			break;
		}
	}
	void patch_pipeline::upsample_state::step()
	{
		static constexpr size_t NUM_INVOCATIONS = (NUM_VERTICES + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;

		switch (state)
		{
		case START:
		{
			// Get offset for new patch
			offset = pipeline->_manager.alloc_block();

			glUseProgram(pipeline->_upsampler);
			// Uniform values
			glm::dvec3 positions[] = {
				children[0]->pos,
				children[1]->pos,
				children[2]->pos,
				children[3]->pos
			};
			GLuint _offsets[4];

			for (size_t i = 0; i < 4; ++i)
			{
				auto it = pipeline->_offsets.find(children[i]);
				if (it == pipeline->_offsets.end())
				{
					assert(false);
					state = ERROR_STATE;
					return;
				}

				_offsets[i] = it->second;
			}

			// Bind and fill uniform buffer
			GLuint uniforms;
			glGenBuffers(1, &uniforms);
			glBindBuffer(GL_UNIFORM_BUFFER, uniforms);
			glBufferData(GL_UNIFORM_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

			// Bind output
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, pipeline->_manager.buffer(),
				offset * pipeline->_manager.block_size(), pipeline->_manager.block_size());

			// Bind inputs
			for (GLuint i = 0; i < 4; ++i)
			{
				glBindBufferRange(GL_SHADER_STORAGE_BUFFER, i + 1, pipeline->_manager.buffer(),
					_offsets[i] * pipeline->_manager.block_size(), pipeline->_manager.block_size());
			}

			// Dispatch upsample shader 
			glDispatchCompute(NUM_INVOCATIONS, 1, 1);
			// Make effects visible to other shaders down the pipeline
			glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

			glDeleteBuffers(1, &uniforms);

			state = DONE;

			OutputDebug("[PIPELINE] Upsampling patch ", target_patch.get(), '\n');

			OutputDebug("[PIPELINE] Removing patch ", children[0].get(), '\n');
			OutputDebug("[PIPELINE] Removing patch ", children[1].get(), '\n');
			OutputDebug("[PIPELINE] Removing patch ", children[2].get(), '\n');
			OutputDebug("[PIPELINE] Removing patch ", children[3].get(), '\n');
			break;
		}
		case DONE:
			break;
		case ERROR_STATE:
			break;
		default:
			break;
		}
	}
	void patch_pipeline::remove_state::step()
	{
		switch (state)
		{
		case START:
		{
			auto it = pipeline->_offsets.find(target_patch);
			if (it == pipeline->_offsets.end())
			{
				if (ctr++ < 16)
					state = START;
				else
				{
					state = ERROR_STATE;
					OutputDebug("[PIPELINE][ERROR] Unable to find offset for patch ", target_patch.get(), ".\n");
				}
				return;
			}

			offset = it->second;
			pipeline->_offsets.erase(it);

			state = DONE;

			OutputDebug("[PIPELINE] Removed patch ", target_patch.get(), ". There are ", --n, " patches.\n");
			break;
		}
		case DONE:
			break;
		case ERROR_STATE:
			break;
		default:
			break;
		}
	}

	patch_pipeline::generate_state::generate_state(std::shared_ptr<patch> p, patch_pipeline* pipeline) :
		state(START),
		pipeline(pipeline),
		target_patch(p)
	{

	}
	patch_pipeline::upsample_state::upsample_state(std::shared_ptr<patch> p, patch_pipeline* pipeline) :
		state(START),
		pipeline(pipeline),
		target_patch(p)
	{
		if (!p->subdivided())
		{
			state = ERROR_STATE;
		}
		else
		{
			if (p->nw->subdivided() ||
				p->ne->subdivided() ||
				p->sw->subdivided() ||
				p->se->subdivided())
			{
				state = ERROR_STATE;
			}
			else
			{
				children[0] = p->nw;
				children[1] = p->ne;
				children[2] = p->sw;
				children[3] = p->se;
			}
		}
	}
	patch_pipeline::remove_state::remove_state(std::shared_ptr<patch> p, patch_pipeline* pipeline) :
		state(START),
		pipeline(pipeline),
		target_patch(p),
		ctr(0)
	{

	}

	update_state patch_pipeline::process(size_t n)
	{
		for (size_t i = 0; i < n && !_waiting.empty();)
		{
			_executing.push_back(_waiting.front());

			// Removing costs next to nothing so we
			// can do many of them at once
			if (!_waiting.front().is<remove_state>())
				++i;

			_waiting.pop();
		}

		for (auto& exec : _executing)
		{
			switch (exec.active_index())
			{
			case 0:
				exec.get<exec_type::type_at<0>>().step();
				break;
			case 1:
				exec.get<exec_type::type_at<1>>().step();
				break;
			case 2:
				exec.get<exec_type::type_at<2>>().step();
				break;
			}
		}

		update_state ustate;

		bool cond = false;
		bool failed = false;
		do
		{
			if (_executing.empty())
				break;
			auto& exec = _executing.front();
			switch (exec.active_index())
			{
			case 0:
			{
				auto& var = exec.get<exec_type::type_at<0>>();
				cond = var.is_done();
				failed = is_failed(var);
				break;
			}
			case 1:
			{
				auto& var = exec.get<exec_type::type_at<1>>();
				cond = var.is_done();
				failed = is_failed(var);
				break;
			}
			case 2:
			{
				auto& var = exec.get<exec_type::type_at<2>>();
				cond = var.is_done();
				failed = is_failed(var);
				break;
			}
			default:
				assert(false);
			}

			if (cond)
			{
				switch (exec.active_index())
				{
				case exec_type::index_of<generate_state>::value:
				{
					auto& val = exec.get<generate_state>();

					MoveCommand mvcmd;
					mvcmd.is_new = GL_TRUE;
					mvcmd.dest = val.offset;
					mvcmd.source = (GLuint)ustate.commands.size();

					DrawElementsIndirectCommand cmd = {
						NUM_ELEMENTS,
						1, // Instance Count
						0, // First Index
						_manager.block_size() / VERTEX_SIZE * val.offset,
						0 // BaseInstance
					};

					ustate.movecommands.push_back(mvcmd);
					ustate.commands.push_back(cmd);
					break;
				}
				case exec_type::index_of<upsample_state>::value:
				{
					auto& val = exec.get<upsample_state>();

					MoveCommand mvcmd;
					mvcmd.is_new = GL_TRUE;
					mvcmd.dest = val.offset;
					mvcmd.source = (GLuint)ustate.commands.size();

					DrawElementsIndirectCommand cmd = {
						NUM_ELEMENTS,
						1, // Instance Count
						0, // First Index
						_manager.block_size() / VERTEX_SIZE * val.offset,
						0 // BaseInstance
					};

					ustate.movecommands.push_back(mvcmd);
					ustate.commands.push_back(cmd);
					break;
				}
				case exec_type::index_of<remove_state>::value:
				{
					auto& val = exec.get<remove_state>();

					_manager.dealloc_block(val.offset);

					MoveCommand mvcmd;
					mvcmd.is_new = GL_FALSE;
					mvcmd.dest = val.offset;
					mvcmd.source = 0;

					ustate.movecommands.push_back(mvcmd);
				}
				}

				_executing.pop_front();
			}

			if (failed)
			{
				OutputDebug("[PIPELINE][ERROR] A command failed!\n");
				_executing.pop_front();
			}
		} while (cond && !failed);


		return ustate;
	}

	buffer_manager& patch_pipeline::manager()
	{
		return _manager;
	}
	auto patch_pipeline::patches() const -> const decltype(_offsets)&
	{
		return _offsets;
	}

	patch_pipeline::patch_pipeline(size_t num_blocks) :
		_manager(MESH_SIZE, static_cast<GLuint>(num_blocks))
	{
		using namespace util;

		shader meshgen(false);
		shader vertex_gen(false);
		shader upsampler(false);

		meshgen.compute(read_file("mesh_gen.glsl"));
		meshgen.link();

		vertex_gen.compute(read_file("vertex_gen.glsl"));
		vertex_gen.link();

		upsampler.compute(read_file("upsample.glsl"));
		upsampler.link();

		meshgen.check_errors({ GL_COMPUTE_SHADER });
		vertex_gen.check_errors({ GL_COMPUTE_SHADER });
		upsampler.check_errors({ GL_COMPUTE_SHADER });

		_meshgen = meshgen.program();
		_vertex_gen = vertex_gen.program();
		_upsampler = upsampler.program();

		glProgramUniform1ui(_meshgen, 0, SIDE_LEN);
		glProgramUniform1ui(_vertex_gen, 0, SIDE_LEN);
		glProgramUniform1ui(_upsampler, 0, SIDE_LEN);
	}
	patch_pipeline::~patch_pipeline()
	{
		while (!_waiting.empty() && !_executing.empty())
		{
			process(64);
		}

		glDeleteProgram(_meshgen);
		glDeleteProgram(_vertex_gen);
		glDeleteProgram(_upsampler);
	}

	bool patch_pipeline::can_upsample(std::shared_ptr<patch> p)
	{
		if (!p->subdivided())
			return false;
		if (p->nw->subdivided() ||
			p->ne->subdivided() ||
			p->sw->subdivided() ||
			p->se->subdivided())
			return false;
		return true;
	}
}
