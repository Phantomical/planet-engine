#include "patch_pipeline.h"

#include "defs.h"
#include "shader.h"
#include "load_file.h"
#include "findutils.h"
#include "templateutils.h"
#include "spaced_buffer.h"

#include <iostream>
#include <algorithm>
#include <iterator>

namespace planet_engine
{
	template<typename T>
	constexpr T rounddown(T a, T b)
	{
		return (a / b) * b;
	}
	template<typename T>
	constexpr T roundup(T a, T b)
	{
		return ((a + b - 1) / b) * b;
	}


	GLenum patch_pipeline::gen_meshes_state::execute_next(update_state& ustate)
	{
		static constexpr size_t NUM_RESULT_ELEMS = SIDE_LEN * SIDE_LEN;
		static constexpr size_t NUM_COMPUTE_GROUPS = (NUM_RESULT_ELEMS + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;

#define vertices  buffers[0]
#define infos     buffers[1]
#define positions buffers[2]
#define lengths   buffers[3]
#define offsetbuf buffers[4]
#define downloads buffers[5]

		switch (state)
		{
		case INITIAL:
			glGenBuffers(6, buffers);

			static_assert(sizeof(buffers) / sizeof(GLuint) == 6, "execute_next has additional buffers and needs to be updated.");

			glBindBuffer(GL_SHADER_STORAGE_BUFFER, vertices);
			glBufferData(GL_SHADER_STORAGE_BUFFER, VERTEX_BUFFER_SIZE * size, nullptr, GL_STATIC_DRAW);
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, downloads);
			glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(float) * size, nullptr, GL_STREAM_COPY);
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, positions);
			glBufferStorage(GL_SHADER_STORAGE_BUFFER, sizeof(glm::vec4) * 256, nullptr, GL_MAP_READ_BIT);
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, lengths);
			glBufferData(GL_SHADER_STORAGE_BUFFER, NUM_RESULT_ELEMS * sizeof(float) * size, nullptr, GL_STATIC_DRAW);

			glBindBuffer(GL_UNIFORM_BUFFER, infos);
			glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info) * 256, nullptr, GL_STATIC_DRAW);

			offsets = new GLuint[256];

			{
				mesh_info* infoptr = (mesh_info*)glMapBufferRange(GL_UNIFORM_BUFFER, 0, sizeof(mesh_info) * 256, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);

				for (size_t i = 0; i < size; ++i)
				{
					auto patch = patches[i];

					mesh_info info = {
						patch->pos,
						patch->data->planet_radius,
						patch->nwc,
						patch->data->skirt_depth,
						patch->nec,
						patch->data->scale,
						patch->swc,
						0.0, // Padding
						patch->sec
					};

					infoptr[i] = info;
					offsets[i] = pipeline->manager().alloc_block();
					pipeline->_offsets.insert(std::make_pair(patches[i], offsets[i]));
					pipeline->_manager.lock(offsets[i]);
				}

				glUnmapBuffer(GL_UNIFORM_BUFFER);

				glBindBuffer(GL_SHADER_STORAGE_BUFFER, offsetbuf);
				glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(GLuint) * 256, offsets, GL_STATIC_DRAW);
			}

			state = DISPATCH_VERTEX_GEN;
			return 0;
		case DISPATCH_VERTEX_GEN:
			// Generate the vertices
			pipeline->dispatch_vertex_gen(size, vertices, infos);
			// Get all the positions for the patches (This is the only other
			// shader that doesn't depend on vertex_gen)
			pipeline->dispatch_get_pos(size, infos, positions);

			state = DISPATCH_GEN_MESHES;
			return GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT;
		case DISPATCH_GEN_MESHES:
			pipeline->dispatch_gen_meshes(size, infos, vertices, offsetbuf);

			{
				glBindBuffer(GL_SHADER_STORAGE_BUFFER, positions);
				const glm::vec4* vals = (glm::vec4*)glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_ONLY);

				if (vals)
				{
					for (size_t i = 0; i < size; ++i)
					{
						patches[i]->actual_pos = patches[i]->pos + glm::dvec3(vals[i]);
					}
					glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
				}
			}

			state = DISPATCH_LENGTH_CALC;
			return GL_SHADER_STORAGE_BARRIER_BIT | GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT;
		case DISPATCH_LENGTH_CALC:
			// Indicate that there are new meshes
			for (size_t i = 0; i < size; ++i)
			{
				MoveCommand mvcmd;
				mvcmd.is_new = GL_TRUE;
				mvcmd.source = (GLuint)ustate.commands.size();
				mvcmd.dest = offsets[i];

				DrawElementsIndirectCommand cmd;
				cmd.count = NUM_ELEMENTS;
				cmd.instanceCount = 1;
				cmd.firstIndex = 0;
				cmd.baseVertex = pipeline->manager().block_size() / VERTEX_SIZE * offsets[i];
				cmd.baseInstance = 0;

				ustate.movecommands.push_back(mvcmd);
				ustate.commands.push_back(cmd);

				pipeline->_manager.unlock(offsets[i]);
			}
			delete[] offsets;
			offsets = nullptr;
			// Currently these steps are skipped

			///* Calculate lengths from the position */
			//glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
			//dispatch_length_calc(size, offsetbuf, lengths, positions);
			//state = DISPATCH_MAX_CALC;
			//return GL_SHADER_STORAGE_BARRIER_BIT;
		case DISPATCH_MAX_CALC:
			///* Compact and send the results to a CPU buffer */
			//glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
			//dispatch_compact(size, lengths, downloads);

			//state = DISPATCH_COMPACT;
			//return GL_SHADER_STORAGE_BARRIER_BIT;
		case DISPATCH_COMPACT:
			///* Calculate the maximum */
			//glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
			//dispatch_max_calc(size, lengths);
			//
			//state = RETRIEVE_RESULTS;
			//return GL_SHADER_STORAGE_BARRIER_BIT;
		case RETRIEVE_RESULTS:
			glDeleteBuffers(6, buffers);

			{
				//glBindBuffer(GL_COPY_WRITE_BUFFER, downloads);
				//float* distances = (float*)glMapBuffer(GL_COPY_WRITE_BUFFER, GL_READ_ONLY);
				//
				//for (size_t i = 0; i < size; ++i)
				//{
				//	patches[i]->farthest_vertex = distances[i];
				//}
				//
				//glUnmapBuffer(GL_COPY_WRITE_BUFFER);
			}

			state = DONE;
			return 0;
		case DONE:
			return 0;
		}

		state = DONE;
		return 0;
#undef vertices
#undef positions
#undef infos
#undef lengths
#undef offsetbuf
#undef downloads
	}
	bool patch_pipeline::gen_meshes_state::is_done() const
	{
		return state == DONE;
	}

	patch_pipeline::gen_meshes_state::gen_meshes_state(const std::shared_ptr<patch>* patches, GLuint size, patch_pipeline* pipeline) :
		patches(patches, patches + size),
		pipeline(pipeline),
		offsets(nullptr),
		state(INITIAL),
		size(size)
	{
		std::memset(buffers, 0, sizeof(buffers));
	}
	patch_pipeline::gen_meshes_state::~gen_meshes_state()
	{
		if (buffers[0] != 0)
			glDeleteBuffers(sizeof(buffers) / sizeof(GLuint), buffers);
		if (offsets != nullptr)
			delete[] offsets;
	}

	void patch_pipeline::remove_state::execute_next(update_state& ustate)
	{
		if (state++ != 6)
			return;

		for (size_t i = 0; i < patches.size(); ++i)
		{
			auto it = pipeline->_offsets.find(patches[i]);
			if (it == pipeline->_offsets.end())
				continue;

			GLuint offset = it->second;

			MoveCommand mvcmd;
			mvcmd.is_new = GL_FALSE;
			mvcmd.source = 0;
			mvcmd.dest = offset;

			ustate.movecommands.push_back(mvcmd);

			pipeline->_offsets.erase(it);
			pipeline->_manager.dealloc_block(offset);
		}
	}
	bool patch_pipeline::remove_state::is_done() const
	{
		return state > 6;
	}

	patch_pipeline::remove_state::remove_state(const std::shared_ptr<patch>* patches, size_t size, patch_pipeline* pipeline) :
		pipeline(pipeline),
		patches(patches, patches + size),
		state(0)
	{

	}

	/* Patch Pipeline */

	void patch_pipeline::dispatch_vertex_gen(GLuint size, GLuint vertices, GLuint infos)
	{
		glUseProgram(_vertex_gen);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertices);
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, infos);

		glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, size);
	}
	void patch_pipeline::dispatch_get_pos(GLuint size, GLuint infos, GLuint positions)
	{
		glUseProgram(_get_pos);

		glBindBufferBase(GL_UNIFORM_BUFFER, 0, infos);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, positions);

		glDispatchCompute(1, size, 1);
	}
	void patch_pipeline::dispatch_gen_meshes(GLuint size, GLuint infos, GLuint vertices, GLuint offsets)
	{
		glUseProgram(_meshgen);

		glBindBufferBase(GL_UNIFORM_BUFFER, 0, infos);
		glBindBufferBase(GL_UNIFORM_BUFFER, 1, offsets);
		// Bind input buffer range
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertices);
		// Bind output buffer range
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, _manager.buffer());

		glUniform1ui(1, _manager.block_size() / sizeof(float));

		glDispatchCompute(NUM_INVOCATIONS, size, 1);
	}
	void patch_pipeline::dispatch_length_calc(GLuint size, GLuint offsets, GLuint lengths, GLuint positions)
	{
		static constexpr size_t NUM_RESULT_ELEMS = SIDE_LEN * SIDE_LEN;
		static constexpr size_t NUM_COMPUTE_GROUPS = (NUM_RESULT_ELEMS + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;

		glUseProgram(_length_calc);

		glUniform1ui(0, NUM_RESULT_ELEMS);
		glUniform1ui(1, _manager.block_size());

		glBindBufferBase(GL_UNIFORM_BUFFER, 0, positions);
		glBindBufferBase(GL_UNIFORM_BUFFER, 1, offsets);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, _manager.buffer());
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, lengths);

		glDispatchCompute(NUM_COMPUTE_GROUPS, (GLuint)size, 1);
	}
	void patch_pipeline::dispatch_max_calc(GLuint size, GLuint lengths)
	{
		static constexpr size_t NUM_RESULT_ELEMS = SIDE_LEN * SIDE_LEN;

		glUseProgram(_max_calc);
		glUniform1ui(1, sizeof(float) * NUM_RESULT_ELEMS);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, lengths);

		for (GLuint s = SIDE_LEN * SIDE_LEN; s > 1; s = (s + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE)
		{
			glUniform1ui(0, s);

			GLuint compute_size = (GLuint)((s + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE);

			glDispatchCompute(compute_size, size, 1);

			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
		}
	}
	void patch_pipeline::dispatch_compact(GLuint size, GLuint lengths, GLuint target)
	{
		static constexpr size_t NUM_RESULT_ELEMS = SIDE_LEN * SIDE_LEN;
		static constexpr size_t COMPACT_SHADER_GROUP_SIZE = 16;

		glUseProgram(_compact);

		glUniform1ui(0, (GLuint)size);
		glUniform1ui(1, NUM_RESULT_ELEMS);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, lengths);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, target);

		glDispatchCompute(((size + COMPACT_SHADER_GROUP_SIZE - 1) / COMPACT_SHADER_GROUP_SIZE), 1, 1);

	}

	void patch_pipeline::gen_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, GLuint size)
	{
		if (size != 0)
		{
			assert(size <= 256);

			_gen_states.emplace_back(patches, size, this);
		}

		GLuint barrier = 0;

		for (auto& state : _gen_states)
		{
			barrier |= state.execute_next(ustate);
		}

		if (!_gen_states.empty())
			if (_gen_states.front().is_done())
				_gen_states.pop_front();

		glMemoryBarrier(barrier);
	}
	void patch_pipeline::remove_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, GLuint size)
	{
		if (size != 0)
		{
			assert(size <= 256);

			_remove_states.emplace_back(patches, size, this);
		}

		for (auto& state : _remove_states)
		{
			state.execute_next(ustate);
		}

		if (!_remove_states.empty())
			if (_remove_states.front().is_done())
				_remove_states.pop_front();
	}

	void patch_pipeline::generate(std::shared_ptr<patch> patch)
	{
		auto it = std::find(std::begin(_remove), std::end(_remove), patch);
		if (it != std::end(_remove))
			_remove.erase(it);
		else
			_generate.push_back(patch);
	}
	void patch_pipeline::remove(std::shared_ptr<patch> patch)
	{
		auto it = std::find(std::begin(_generate), std::end(_generate), patch);
		if (it != std::end(_generate))
			_generate.erase(it);
		else
			_remove.push_back(patch);
	}

	update_state patch_pipeline::process()
	{
		static constexpr size_t MAX_UPDATES_PER_FRAME = 128;

		update_state ustate;

		size_t gensz = std::min(_generate.size(), MAX_UPDATES_PER_FRAME);
		size_t remsz = std::min(_remove.size(), MAX_UPDATES_PER_FRAME);

		std::vector<std::shared_ptr<patch>> to_generate, to_remove;
		std::copy_n(std::begin(_generate), gensz, std::back_inserter(to_generate));
		std::copy_n(std::begin(_remove), remsz, std::back_inserter(to_remove));

		_generate.erase(_generate.begin(), _generate.begin() + gensz);
		_remove.erase(_remove.begin(), _remove.begin() + remsz);

		gen_meshes(ustate, to_generate.data(), (GLuint)to_generate.size());
		remove_meshes(ustate, to_remove.data(), (GLuint)to_remove.size());

		return ustate;
	}

	void patch_pipeline::cull()
	{
		std::vector<std::shared_ptr<patch>> to_cull;

		for (auto& p : _offsets)
		{
			if (p.first->parent.expired() && p.first->level != 0)
				to_cull.push_back(p.first);
		}

		for (auto& p : to_cull)
			remove(p);
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
		shader length_calc(false);
		shader max_calc(false);
		shader get_pos(false);
		shader compact(false);

		meshgen.compute(read_file("mesh_gen.glsl"));
		meshgen.link();

		vertex_gen.compute(read_file("vertex_gen.glsl"));
		vertex_gen.link();

		length_calc.compute(read_file("length.glsl"));
		length_calc.link();

		max_calc.compute(read_file("max.glsl"));
		max_calc.link();

		get_pos.compute(read_file("get_pos.glsl"));
		get_pos.link();

		compact.compute(read_file("compact.glsl"));
		compact.link();

		meshgen.check_errors({ GL_COMPUTE_SHADER });
		vertex_gen.check_errors({ GL_COMPUTE_SHADER });
		length_calc.check_errors({ GL_COMPUTE_SHADER });
		max_calc.check_errors({ GL_COMPUTE_SHADER });
		get_pos.check_errors({ GL_COMPUTE_SHADER });
		compact.check_errors({ GL_COMPUTE_SHADER });

		_meshgen = meshgen.program();
		_vertex_gen = vertex_gen.program();
		_length_calc = length_calc.program();
		_max_calc = max_calc.program();
		_get_pos = get_pos.program();
		_compact = compact.program();

		glProgramUniform1ui(_meshgen, 0, SIDE_LEN);
		glProgramUniform1ui(_vertex_gen, 0, SIDE_LEN);

		glGenBuffers(1, &_lengths);
		glBindBuffer(GL_COPY_WRITE_BUFFER, _lengths);
		glBufferData(GL_COPY_WRITE_BUFFER, LENGTH_CACHE_SIZE * sizeof(float), nullptr, GL_STREAM_READ);

		GLint ssbo_alignment;
		glGetIntegerv(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, &ssbo_alignment);
		_ssbo_alignment = (GLuint)ssbo_alignment;
		GLint ubo_alignment;
		glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &ubo_alignment);
		_ubo_alignment = (GLuint)ubo_alignment;
	}
	patch_pipeline::~patch_pipeline()
	{
		glDeleteProgram(_meshgen);
		glDeleteProgram(_vertex_gen);
	}
}
