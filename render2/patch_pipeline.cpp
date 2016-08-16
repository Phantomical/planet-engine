#include "patch_pipeline.h"

#include "shader.h"
#include "load_file.h"

#include <iostream>
#include <algorithm>

namespace planet_engine
{
	/* Patch Pipeline */
	void patch_pipeline::gen_vertices(GLuint buffers[2], std::shared_ptr<patch> patch, GLuint* offset)
	{
		glGenBuffers(2, buffers);

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

		*offset = _manager.alloc_block();

		glUseProgram(_vertex_gen);
		// Bind output buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
		// Bind uniforms
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffers[1]);
		// Dispatch compute shader to fill the output buffer
		glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, 1);
		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
	}
	void patch_pipeline::gen_mesh(GLuint buffers[2], std::shared_ptr<patch> patch, const GLuint* offset)
	{
		glUseProgram(_meshgen);
		// Bind input buffer
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
		// Bind output buffer range
		glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, _manager.buffer(),
			*offset * _manager.block_size(), _manager.block_size());
		// Dispatch compute shader to fill the output buffer range
		glDispatchCompute(NUM_INVOCATIONS, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);

		// Delete buffers
		glDeleteBuffers(2, buffers);

		buffers[0] = 0;
		buffers[1] = 0;
	}

	void patch_pipeline::generate(std::shared_ptr<patch> patch)
	{
		bool canceled = false;

		if (!_exec_queue.empty())
		{
			for (size_t i = _exec_queue.size() - 1, j = 0; i != 0 && j < MAX_SCAN_DEPTH; --i, ++j)
			{
				size_t index = _exec_queue[i].active_index();
				if (index == 0)
				{
					auto& val = _exec_queue[i].get<std::shared_ptr<remove_state>>();
					if (val->target == patch)
					{
						val->cancel();
						canceled = true;
						break;
					}
				}
				else if (index == 1)
				{
					auto& val = _exec_queue[i].get<std::shared_ptr<generate_state>>();
					//if (val->target == patch)
					//	OutputDebug("[PIPELINE] Patch ", patch.get(), " generated twice in a row\n");
				}
				else
					assert(false);
			}
		}

		if (canceled)
			return;

		auto ptr = std::make_shared<generate_state>(patch, this);

		_job_queue.push([ptr = ptr, pipeline = this]() {
			if (ptr->counter == CANCELLED_COUNTER_VALUE)
				return false;

			pipeline->gen_vertices(ptr->buffers, ptr->target, &ptr->offset);
			++ptr->counter;

			return true;
		});

		_job_queue.push([ptr = ptr, pipeline = this]() {
			if (ptr->counter == CANCELLED_COUNTER_VALUE)
				return false;

			pipeline->gen_mesh(ptr->buffers, ptr->target, &ptr->offset);
			++ptr->counter;

			return true;
		});

		_exec_queue.push_back(ptr);
	}
	void patch_pipeline::remove(std::shared_ptr<patch> patch)
	{
		bool canceled = false;

		if (!_exec_queue.empty())
		{
			for (size_t i = _exec_queue.size() - 1, j = 0; i != 0 && j < MAX_SCAN_DEPTH; --i, ++j)
			{
				size_t index = _exec_queue[i].active_index();
				if (index == 0)
				{
					auto& val = _exec_queue[i].get<std::shared_ptr<remove_state>>();
					//if (val->target == patch)
					//	OutputDebug("[PIPELINE] Patch ", patch.get(), " removed twice in a row\n");
				}
				else if (index == 1)
				{
					auto& val = _exec_queue[i].get<std::shared_ptr<generate_state>>();
					if (val->target == patch)
					{
						val->cancel();
						canceled = true;
						break;
					}
				}
				else
					assert(false);
			}
		}

		if (canceled)
			return;

		auto ptr = std::make_shared<remove_state>(patch, this);

		_exec_queue.push_back(ptr);
	}

	update_state patch_pipeline::process(size_t n)
	{
		for (size_t i = 0; i < n && !_job_queue.empty();)
		{
			if (_job_queue.front()())
				++i;

			_job_queue.pop();
		}

		update_state ustate;

		bool cond = true;
		while (!_exec_queue.empty() && cond)
		{
			auto& exec = _exec_queue.front();

			switch (exec.active_index())
			{
			case 0:
			{
				auto& val = *exec.get<exec_type::type_at<0>>();
				if (val.counter == CANCELLED_COUNTER_VALUE)
					_exec_queue.pop_front();
				else if (val.can_finalize())
				{
					val.finalize(ustate);
					_exec_queue.pop_front();
				}
				else
					cond = false;
				break;
			}
			case 1:
			{
				auto& val = *exec.get<exec_type::type_at<1>>();
				if (val.counter == CANCELLED_COUNTER_VALUE)
					_exec_queue.pop_front();
				else if (val.can_finalize())
				{
					val.finalize(ustate);
					_exec_queue.pop_front();
				}
				else
					cond = false;
				break;
			}
			default:
				assert(false);
			}
		}

		if (_manager.current_max() * 2 < _manager.max_index())
			_manager.uncommit_unused();

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

		meshgen.compute(read_file("mesh_gen.glsl"));
		meshgen.link();

		vertex_gen.compute(read_file("vertex_gen.glsl"));
		vertex_gen.link();

		meshgen.check_errors({ GL_COMPUTE_SHADER });
		vertex_gen.check_errors({ GL_COMPUTE_SHADER });

		_meshgen = meshgen.program();
		_vertex_gen = vertex_gen.program();

		glProgramUniform1ui(_meshgen, 0, SIDE_LEN);
		glProgramUniform1ui(_vertex_gen, 0, SIDE_LEN);
	}
	patch_pipeline::~patch_pipeline()
	{
		glDeleteProgram(_meshgen);
		glDeleteProgram(_vertex_gen);
	}

	void patch_pipeline::generate_state::cancel()
	{
		counter = CANCELLED_COUNTER_VALUE;

		if (buffers[0] != 0)
			glDeleteBuffers(2, buffers);
		if (offset != 0)
			pipeline->manager().dealloc_block(offset);
	}
	void patch_pipeline::remove_state::cancel()
	{
		counter = CANCELLED_COUNTER_VALUE;
	}

	bool patch_pipeline::generate_state::can_finalize() const
	{
		return counter == 2;
	}
	bool patch_pipeline::remove_state::can_finalize() const
	{
		return true;
	}

	void patch_pipeline::generate_state::finalize(update_state& ustate)
	{
		MoveCommand mvcmd;
		mvcmd.is_new = GL_TRUE;
		mvcmd.source = (GLuint)ustate.commands.size();
		mvcmd.dest = offset;

		DrawElementsIndirectCommand cmd;
		cmd.count = NUM_ELEMENTS;
		cmd.instanceCount = 1;
		cmd.firstIndex = 0;
		cmd.baseVertex = pipeline->manager().block_size() / VERTEX_SIZE * offset;
		cmd.baseInstance = 0;

		ustate.movecommands.push_back(mvcmd);
		ustate.commands.push_back(cmd);

		pipeline->_offsets.insert(std::make_pair(target, offset));
	}
	void patch_pipeline::remove_state::finalize(update_state& ustate)
	{
		auto it = pipeline->_offsets.find(target);
		if (it == pipeline->_offsets.end())
		{
			OutputDebug("[PIPELINE] Attempted to remove patch ", target.get(), ". Patch wasn't present.\n");
			return;//assert(false);
		}
		OutputDebug("[PIPELINE] Removed patch ", target.get(), ".\n");

		GLuint offset = it->second;

		MoveCommand mvcmd;
		mvcmd.is_new = GL_FALSE;
		mvcmd.source = 0;
		mvcmd.dest = offset;

		ustate.movecommands.push_back(mvcmd);

		pipeline->_offsets.erase(it);
		pipeline->manager().dealloc_block(offset);
	}

	patch_pipeline::generate_state::generate_state(std::shared_ptr<patch> tgt, patch_pipeline* pipeline) :
		target(tgt),
		counter(0),
		pipeline(pipeline),
		offset(0)
	{
		buffers[0] = 0;
		buffers[1] = 0;
	}
	patch_pipeline::remove_state::remove_state(std::shared_ptr<patch> tgt, patch_pipeline* pipeline) :
		target(tgt),
		counter(0),
		pipeline(pipeline)
	{

	}
}
