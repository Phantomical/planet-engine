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

	/* Patch Pipeline */

	void patch_pipeline::gen_vertices(GLuint buffers[3], std::shared_ptr<patch> patch, GLuint* offset)
	{
		glGenBuffers(3, buffers);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffers[0]);
		glBufferStorage(GL_SHADER_STORAGE_BUFFER, VERTEX_BUFFER_SIZE, nullptr, 0);

		mesh_info info = {
			patch->pos,
			patch->data->planet_radius,
			patch->nwc,
			SKIRT_DEPTH,
			patch->nec,
			patch->data->scale,
			patch->swc,
			0.0, // Padding
			patch->sec
		};

		glBindBuffer(GL_UNIFORM_BUFFER, buffers[1]);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info), &info, GL_STATIC_DRAW);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffers[2]);
		glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(double) * 4, nullptr, GL_STREAM_READ);

		*offset = _manager.alloc_block();

		glUseProgram(_vertex_gen);
		// Bind output buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
		// Bind uniforms
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffers[1]);
		// Dispatch compute shader to fill the output buffer
		glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, 1);

		glUseProgram(_get_pos);
		// Bind position readback buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[2]);
		// Dispatch position calculation shader
		glDispatchCompute(1, 1, 1);

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
	}
	void patch_pipeline::gen_mesh(GLuint buffers[3], std::shared_ptr<patch> patch, const GLuint* offset)
	{
		GLuint actual_offset = rounddown(*offset * _manager.block_size(), _ssbo_alignment);
		GLuint offset_param = (*offset * _manager.block_size() - actual_offset) / sizeof(float);

		glUseProgram(_meshgen);
		// Bind input buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
		// Bind output buffer range
		glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, _manager.buffer(),
			actual_offset, _manager.block_size() + offset_param * sizeof(float));

		glUniform1ui(1, offset_param);

		// Dispatch compute shader to fill the output buffer range
		glDispatchCompute(NUM_INVOCATIONS, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

		glBindBuffer(GL_COPY_READ_BUFFER, buffers[2]);
		glGetBufferSubData(GL_COPY_READ_BUFFER, 0, sizeof(glm::dvec3), &patch->actual_pos);

		// Delete buffers
		glDeleteBuffers(3, buffers);

		buffers[0] = 0;
		buffers[1] = 0;
		buffers[2] = 0;
	}

	void patch_pipeline::gen_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, size_t size)
	{
		static constexpr size_t NUM_RESULT_ELEMS = SIDE_LEN * SIDE_LEN;
		static constexpr size_t NUM_COMPUTE_GROUPS = (NUM_RESULT_ELEMS + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;

		if (size == 0)
			return;
		assert(size <= 256);

		GLuint buffers[3];
		GLuint offsetbuf;
		GLuint* offsets = new GLuint[size];

		GLuint vbo_stride = VERTEX_BUFFER_SIZE;
		GLuint pos_stride = sizeof(double) * 4;

		glGenBuffers(3, buffers);
		glGenBuffers(1, &offsetbuf);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffers[0]);
		glBufferStorage(GL_SHADER_STORAGE_BUFFER, vbo_stride * size, nullptr, 0);

		glBindBuffer(GL_UNIFORM_BUFFER, buffers[1]);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info) * 256, nullptr, GL_STATIC_DRAW);

		{
			mesh_info* infos = (mesh_info*)glMapBufferRange(GL_UNIFORM_BUFFER, 0, sizeof(mesh_info) * 256, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
			for (size_t i = 0; i < size; ++i)
			{
				mesh_info info = {
					patches[i]->pos,
					patches[i]->data->planet_radius,
					patches[i]->nwc,
					patches[i]->data->skirt_depth,
					patches[i]->nec,
					patches[i]->data->scale,
					patches[i]->swc,
					0.0, // Padding
					patches[i]->sec
				};

				infos[i] = info;
				offsets[i] = _manager.alloc_block();
			}
			glUnmapBuffer(GL_UNIFORM_BUFFER);
		}

		glBindBuffer(GL_UNIFORM_BUFFER, offsetbuf);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(GLuint) * 256, offsets, GL_STATIC_DRAW);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffers[2]);
		glBufferData(GL_SHADER_STORAGE_BUFFER, pos_stride * size, nullptr, GL_STREAM_READ);

		/* Generate Vertices */
		glUseProgram(_vertex_gen);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffers[1]);

		glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, (GLuint)size);

		/* Calculate patch positions */
		glUseProgram(_get_pos);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[2]);
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffers[1]);

		glDispatchCompute(1, (GLuint)size, 1);

		glMemoryBarrier(GL_BUFFER_UPDATE_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

		/* Generate Meshes */
		glUseProgram(_meshgen);

		glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffers[1]);

		for (GLuint i = 0; i < size; ++i)
		{
			GLuint actual_offset = rounddown(offsets[i] * _manager.block_size(), _ssbo_alignment);
			GLuint offset_param = (offsets[i] * _manager.block_size() - actual_offset) / sizeof(float);

			glUniform1ui(1, offset_param);
			// InvocationIndex
			glUniform1ui(2, i);

			// Bind input buffer range
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
			// Bind output buffer range
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, _manager.buffer(),
				actual_offset, _manager.block_size() + offset_param * sizeof(float));

			glDispatchCompute(NUM_INVOCATIONS, 1, 1);
		}

		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

		GLuint tmpbuf;
		GLuint tmp_stride = roundup<GLuint>(sizeof(float) * NUM_RESULT_ELEMS, _ssbo_alignment);

		glGenBuffers(1, &tmpbuf);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, tmpbuf);
		glBufferData(GL_SHADER_STORAGE_BUFFER, tmp_stride * size, nullptr, GL_STATIC_DRAW);

		glBindBuffer(GL_COPY_WRITE_BUFFER, buffers[2]);

		/* Calculate lengths from the position */
		glUseProgram(_length_calc);

		glUniform1ui(0, NUM_RESULT_ELEMS);
		glUniform1ui(1, _manager.block_size());

		glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffers[2]);
		glBindBufferBase(GL_UNIFORM_BUFFER, 1, offsetbuf);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, _manager.buffer());
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, tmpbuf);

		glDispatchCompute(NUM_COMPUTE_GROUPS, (GLuint)size, 1);

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

		/* Calculate the maximum */
		glUseProgram(_max_calc);
		glUniform1ui(1, tmp_stride);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, tmpbuf);

		for (size_t s = SIDE_LEN * SIDE_LEN; s > 1; s = (s + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE)
		{
			glUniform1ui(0, (GLuint)s);

			GLuint compute_size = (GLuint)((s + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE);

			glDispatchCompute(compute_size, (GLuint)size, 1);

			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
		}

		void* mem = glMapBufferRange(GL_COPY_WRITE_BUFFER, 0, pos_stride * size, GL_MAP_READ_BIT);
		util::spaced_buffer<glm::vec3> vals(pos_stride, mem);

		for (size_t i = 0; i < size; ++i)
		{
			glm::dvec3 offset = (glm::dvec3)vals[i];
			patches[i]->actual_pos = patches[i]->pos + offset;
		}

		glUnmapBuffer(GL_COPY_WRITE_BUFFER);

		GLuint download_buf;
		glGenBuffers(1, &download_buf);
		glBindBuffer(GL_COPY_WRITE_BUFFER, download_buf);
		glBufferData(GL_COPY_WRITE_BUFFER, sizeof(float) * size, nullptr, GL_STREAM_READ);

		/* Compact and send the results to a CPU buffer */
		glUseProgram(_compact);

		glUniform1ui(0, (GLuint)size);
		glUniform1ui(1, tmp_stride / sizeof(float));

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, tmpbuf);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, download_buf);

		glDispatchCompute((GLuint)((size + 15) / 16), 1, 1);

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
			cmd.baseVertex = _manager.block_size() / VERTEX_SIZE * offsets[i];
			cmd.baseInstance = 0;

			ustate.movecommands.push_back(mvcmd);
			ustate.commands.push_back(cmd);

			_offsets.insert(std::make_pair(patches[i], offsets[i]));
		}

		//glMemoryBarrier(GL_BUFFER_UPDATE_BARRIER_BIT);
		//float* distances = (float*)glMapBuffer(GL_COPY_WRITE_BUFFER, GL_READ_ONLY);
		//
		//for (size_t i = 0; i < size; ++i)
		//{
		//	patches[i]->farthest_vertex = distances[i];
		//}
		//
		//glUnmapBuffer(GL_COPY_WRITE_BUFFER);

		//glDeleteBuffers(1, &tmpbuf);
		//glDeleteBuffers(1, &download_buf);

		std::cout << tmpbuf << ' ' << download_buf << ' ' << buffers[2] << std::endl;

		glDeleteBuffers(2, buffers);
	}
	void patch_pipeline::remove_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			auto it = _offsets.find(patches[i]);
			if (it == _offsets.end())
				continue;

			GLuint offset = it->second;

			MoveCommand mvcmd;
			mvcmd.is_new = GL_FALSE;
			mvcmd.source = 0;
			mvcmd.dest = offset;

			ustate.movecommands.push_back(mvcmd);

			_offsets.erase(it);
			_manager.dealloc_block(offset);
		}
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
		static constexpr size_t MAX_UPDATES_PER_FRAME = 256;

		update_state ustate;

		size_t gensz = std::min(_generate.size(), MAX_UPDATES_PER_FRAME);
		size_t remsz = std::min(_remove.size(), MAX_UPDATES_PER_FRAME);

		std::vector<std::shared_ptr<patch>> to_generate, to_remove;
		std::copy_n(std::begin(_generate), gensz, std::back_inserter(to_generate));
		std::copy_n(std::begin(_remove), remsz, std::back_inserter(to_remove));

		_generate.erase(_generate.begin(), _generate.begin() + gensz);
		_remove.erase(_remove.begin(), _remove.begin() + remsz);

		gen_meshes(ustate, to_generate.data(), to_generate.size());
		remove_meshes(ustate, to_remove.data(), to_remove.size());

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
