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

#define any_of_switch(exec, func) do { \
	switch (exec.active_index()) { \
		case 0: func(0); break; \
		case 1: func(1); break; \
		case 2: func(2); break; \
		case 3: func(3); break; \
	}} while(0)

	void patch_pipeline::_upsample_state::step()
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
	void patch_pipeline::_remove_state::step()
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
	
	patch_pipeline::_upsample_state::_upsample_state(std::shared_ptr<patch> p, patch_pipeline* pipeline) :
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
	patch_pipeline::_remove_state::_remove_state(std::shared_ptr<patch> p, patch_pipeline* pipeline) :
		state(START),
		pipeline(pipeline),
		target_patch(p),
		ctr(0)
	{

	}

	void patch_pipeline::subdivide_state::gen_vertices(size_t idx)
	{
		glGenBuffers(1, &vertex_buffers[idx]);
		glGenBuffers(1, &uniforms[idx]);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, vertex_buffers[idx]);
		glBufferStorage(GL_SHADER_STORAGE_BUFFER, VERTEX_BUFFER_SIZE, nullptr, 0);

		mesh_info info =
		{
			children[idx]->pos,
			children[idx]->data->planet_radius,
			children[idx]->nwc,
			SKIRT_DEPTH,
			children[idx]->nec,
			1.0, // Scale
			children[idx]->swc,
			0.0, //Padding
			children[idx]->sec
		};

		glBindBuffer(GL_UNIFORM_BUFFER, uniforms[idx]);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info), &info, GL_STATIC_DRAW);

		offsets[idx] = pipeline->manager().alloc_block();

		glUseProgram(pipeline->_vertex_gen);
		// Bind output buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertex_buffers[idx]);
		// Bind uniforms
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniforms[idx]);
		// Dispatch compute shader to fill the output buffer
		glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, 1);
		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

		++counter;
	}
	void patch_pipeline::subdivide_state::gen_mesh(size_t idx)
	{
		glUseProgram(pipeline->_meshgen);
		// Bind input buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertex_buffers[idx]);
		// Bind output buffer range
		glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, pipeline->manager().buffer(),
			offsets[idx] * pipeline->manager().block_size(), pipeline->manager().block_size());
		// Bind uniforms
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniforms[idx]);
		// Dispatch compute shader to fill the output buffer range
		glDispatchCompute(NUM_INVOCATIONS, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

		// Delete buffers
		glDeleteBuffers(1, &uniforms[idx]);
		glDeleteBuffers(1, &vertex_buffers[idx]);

		++counter;
	}

	bool patch_pipeline::subdivide_state::can_finalize()
	{
		return counter == 8;
	}
	void patch_pipeline::subdivide_state::get_state(update_state& ustate)
	{
		for (size_t i = 0; i < 4; ++i)
		{
			MoveCommand mvcmd;
			mvcmd.is_new = GL_TRUE;
			mvcmd.source = ustate.commands.size();
			mvcmd.dest = offsets[i];

			DrawElementsIndirectCommand cmd;
			cmd.count = NUM_ELEMENTS;
			cmd.instanceCount = 1;
			cmd.firstIndex = 0;
			cmd.baseVertex = pipeline->manager().block_size() / VERTEX_SIZE * offsets[i];
			cmd.baseInstance = 0;

			ustate.movecommands.push_back(mvcmd);
			ustate.commands.push_back(cmd);

			pipeline->_offsets.insert(std::make_pair(children[i], offsets[i]));

		}

		{
			pipeline->manager().dealloc_block(offset);

			MoveCommand mvcmd;
			mvcmd.is_new = GL_FALSE;
			mvcmd.source = 0;
			mvcmd.dest = offset;

			auto it = pipeline->_offsets.find(parent);
			if (it == pipeline->_offsets.end())
				assert(false);
			pipeline->_offsets.erase(it);

			ustate.movecommands.push_back(mvcmd);
		}
	}

	void patch_pipeline::merge_state::gen_vertices()
	{
		glGenBuffers(1, &vertex_buffer);
		glGenBuffers(1, &uniforms);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, vertex_buffer);
		glBufferStorage(GL_SHADER_STORAGE_BUFFER, VERTEX_BUFFER_SIZE, nullptr, 0);

		mesh_info info =
		{
			parent->pos,
			parent->data->planet_radius,
			parent->nwc,
			SKIRT_DEPTH,
			parent->nec,
			1.0, // Scale
			parent->swc,
			0.0, //Padding
			parent->sec
		};

		glBindBuffer(GL_UNIFORM_BUFFER, uniforms);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info), &info, GL_STATIC_DRAW);

		offset = pipeline->manager().alloc_block();

		glUseProgram(pipeline->_vertex_gen);
		// Bind output buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertex_buffer);
		// Bind uniforms
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniforms);
		// Dispatch compute shader to fill the output buffer
		glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, 1);
		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

		++counter;
	}
	void patch_pipeline::merge_state::gen_mesh()
	{
		glUseProgram(pipeline->_meshgen);
		// Bind input buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertex_buffer);
		// Bind output buffer range
		glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, pipeline->manager().buffer(),
			offset * pipeline->manager().block_size(), pipeline->manager().block_size());
		// Bind uniforms
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniforms);
		// Dispatch compute shader to fill the output buffer range
		glDispatchCompute(NUM_INVOCATIONS, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

		// Delete buffers
		glDeleteBuffers(1, &uniforms);
		glDeleteBuffers(1, &vertex_buffer);

		++counter;
	}

	bool patch_pipeline::merge_state::can_finalize()
	{
		return counter == 2;
	}
	void patch_pipeline::merge_state::get_state(update_state& ustate)
	{
		for (size_t i = 0; i < 4; ++i)
		{
			MoveCommand mvcmd;
			mvcmd.is_new = GL_FALSE;
			mvcmd.source = 0;
			mvcmd.dest = offsets[i];

			ustate.movecommands.push_back(mvcmd);

			auto it = pipeline->_offsets.find(children[i]);
			if (it == pipeline->_offsets.end())
				assert(false);
			pipeline->_offsets.erase(it);

			pipeline->manager().dealloc_block(offsets[i]);
		}

		{
			MoveCommand mvcmd;
			mvcmd.is_new = GL_TRUE;
			mvcmd.source = ustate.commands.size();
			mvcmd.dest = offset;

			DrawElementsIndirectCommand cmd;
			cmd.count = NUM_ELEMENTS;
			cmd.instanceCount = 1;
			cmd.firstIndex = 0;
			cmd.baseVertex = pipeline->manager().block_size() / VERTEX_SIZE * offset;
			cmd.baseInstance = 0;

			ustate.movecommands.push_back(mvcmd);
			ustate.commands.push_back(cmd);

			pipeline->_offsets.insert(std::make_pair(parent, offset));
		}
	}

	void patch_pipeline::subdivide(std::shared_ptr<patch> patch)
	{
		std::shared_ptr<subdivide_state> ptr = std::make_shared<subdivide_state>(patch, this);

		for (size_t i = 0; i < 4; ++i)
		{
			_job_queue.push([=]() {
				ptr->gen_vertices(i);
			});
			_job_queue.push([=]() {
				ptr->gen_mesh(i);
			});
		}
	}

	update_state patch_pipeline::process(size_t n)
	{
#define finalize(idx) \
	finalizable = exec.get<exec_type::type_at<idx>>()->can_finalize(); 
#define get_state(idx) exec.get<exec_type::type_at<idx>>()->get_state(ustate)

		for (size_t i = 0; i < n && !_job_queue.empty(); ++i)
		{
			_job_queue.front()();
			_job_queue.pop();
		}

		update_state ustate;

		bool finalizable = true;

		while (finalizable && !_exec_queue.empty())
		{
			auto& exec = _exec_queue.front();

			any_of_switch(exec, finalize);

			if (finalizable)
			{
				any_of_switch(exec, get_state);

				_exec_queue.pop();
			}
		}

		return ustate;

#undef finalize
#undef get_state
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
