#include "patch_pipeline.h"

#include "shader.h"
#include "load_file.h"
#include "findutils.h"
#include "templateutils.h"

#include <iostream>
#include <algorithm>

namespace planet_engine
{
	template<typename T>
	T rounddown(T a, T b)
	{
		return (a / b) * b;
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

	void patch_pipeline::generate(std::shared_ptr<patch> patch)
	{
		bool canceled = false;

		if (!_exec_queue.empty())
		{
			for (size_t i = _exec_queue.size() - 1, j = 0; i != 0 && j < MAX_SCAN_DEPTH; --i, ++j)
			{
				size_t index = _exec_queue[i].active_index();
				if (index == exec_type::index_of<std::shared_ptr<remove_state>>::value)
				{
					auto& val = _exec_queue[i].get<std::shared_ptr<remove_state>>();
					if (val->target == patch)
					{
						val->cancel();
						canceled = true;
						break;
					}
				}
				else if (index == 1 || index == 2)
				{
					// Do Nothing
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

		if (patch->farthest_vertex == std::numeric_limits<float>::max())
			discalc(patch);
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
					// Do Nothing
				}
				else if (index == exec_type::index_of<std::shared_ptr<generate_state>>::value)
				{
					auto& val = _exec_queue[i].get<std::shared_ptr<generate_state>>();
					if (val->target == patch)
					{
						val->cancel();
						canceled = true;
						break;
					}
				}
				else if (index == exec_type::index_of<std::shared_ptr<discalc_state>>::value)
				{
					// Cancel unnecessary distance calculations
					auto& val = _exec_queue[i].get<std::shared_ptr<discalc_state>>();
					if (val->target == patch)
					{
						val->cancel();
						canceled = true;
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
	void patch_pipeline::discalc(std::shared_ptr<patch> patch)
	{
		auto ptr = std::make_shared<discalc_state>(patch, this);

		_job_queue.push([ptr = ptr]() {
			if (ptr->counter == CANCELLED_COUNTER_VALUE)
				return false;

			++ptr->counter;
			ptr->calc_lengths();

			if (ptr->counter == CANCELLED_COUNTER_VALUE)
				return false;

			return true;
		});

		for (size_t s = SIDE_LEN * SIDE_LEN; s > 1; s = (s + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE)
		{
			_job_queue.push([ptr = ptr, s = s]() {
				if (ptr->counter == CANCELLED_COUNTER_VALUE)
					return false;

				ptr->sum_result(s);
				++ptr->counter;

				return true;
			});
		}

		_job_queue.push([ptr = ptr]() {
			if (ptr->counter == CANCELLED_COUNTER_VALUE)
				return false;

			ptr->download_result();
			++ptr->counter;

			return true;
		});

		_exec_queue.push_back(exec_type(ptr));
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
			case 2:
			{
				auto& val = *exec.get<exec_type::type_at<2>>();
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

		if (_exec_queue.size() > n * 64 && cull_counter > 500)
			// If the queue is too big perform a lookahead and
			// try to remove unnecessary work
			mesh_lookahead(n);

		cull_counter++;

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
	void patch_pipeline::mesh_lookahead(size_t n)
	{
		for (size_t i = _exec_queue.size() - 1; i > n; --i)
		{
			auto& exec = _exec_queue[i];

			switch (exec.active_index())
			{
			case 0:
				if (exec.get<exec_type::type_at<0>>()->counter == CANCELLED_COUNTER_VALUE)
					continue;
				break;
			case 1:
				if (exec.get<exec_type::type_at<1>>()->counter == CANCELLED_COUNTER_VALUE)
					continue;
				break;
			case 2:
				continue;
			}

			for (size_t j = i - n; j != 0; --j)
			{
				auto& exec2 = _exec_queue[i];

				switch (exec.active_index())
				{
				case 0:
					if (exec2.get<exec_type::type_at<0>>()->counter == CANCELLED_COUNTER_VALUE)
						continue;
					break;
				case 1:
					if (exec2.get<exec_type::type_at<1>>()->counter == CANCELLED_COUNTER_VALUE)
						continue;
					break;
				case 2:
					if (exec2.get<exec_type::type_at<2>>()->counter == CANCELLED_COUNTER_VALUE)
						continue;
					break;
				}

				size_t st = exec.active_index() * 16 + exec2.active_index();

				switch (st)
				{
				case 0x01:
					if (exec.get<std::shared_ptr<remove_state>>()->target ==
						exec2.get<std::shared_ptr<generate_state>>()->target)
					{
						exec.get<exec_type::type_at<0>>()->cancel();
						exec.get<exec_type::type_at<1>>()->cancel();
					}
					break;
				case 0x02:
					if (exec.get<std::shared_ptr<remove_state>>()->target ==
						exec2.get<std::shared_ptr<discalc_state>>()->target)
					{
						exec.get<exec_type::type_at<0>>()->cancel();
						exec.get<exec_type::type_at<2>>()->cancel();
					}
					break;
				case 0x10:
					if (exec.get<std::shared_ptr<generate_state>>()->target ==
						exec2.get<std::shared_ptr<remove_state>>()->target)
					{
						exec.get<exec_type::type_at<1>>()->cancel();
						exec.get<exec_type::type_at<0>>()->cancel();
					}
					break;
				}
			}
		}

		cull_counter = 0;
		OutputDebug("[PIPELINE] Performed a full-pipe lookahead.\n");
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

		meshgen.check_errors({ GL_COMPUTE_SHADER });
		vertex_gen.check_errors({ GL_COMPUTE_SHADER });
		length_calc.check_errors({ GL_COMPUTE_SHADER });
		max_calc.check_errors({ GL_COMPUTE_SHADER });
		get_pos.check_errors({ GL_COMPUTE_SHADER });

		_meshgen = meshgen.program();
		_vertex_gen = vertex_gen.program();
		_length_calc = length_calc.program();
		_max_calc = max_calc.program();
		_get_pos = get_pos.program();

		glProgramUniform1ui(_meshgen, 0, SIDE_LEN);
		glProgramUniform1ui(_vertex_gen, 0, SIDE_LEN);

		glGenBuffers(1, &_lengths);
		glBindBuffer(GL_COPY_WRITE_BUFFER, _lengths);
		glBufferData(GL_COPY_WRITE_BUFFER, LENGTH_CACHE_SIZE * sizeof(float), nullptr, GL_STREAM_READ);

		GLint ssbo_alignment;
		glGetIntegerv(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, &ssbo_alignment);
		_ssbo_alignment = (GLuint)ssbo_alignment;
	}
	patch_pipeline::~patch_pipeline()
	{
		glDeleteProgram(_meshgen);
		glDeleteProgram(_vertex_gen);
	}

	void patch_pipeline::discalc_state::calc_lengths()
	{
		static constexpr size_t NUM_RESULT_ELEMS = SIDE_LEN * SIDE_LEN;
		static constexpr size_t NUM_COMPUTE_GROUPS = (NUM_RESULT_ELEMS + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;

		glUseProgram(pipeline->_length_calc);

		glGenBuffers(1, &tmpbuf);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, tmpbuf);
		glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(float) * NUM_RESULT_ELEMS, nullptr, GL_STATIC_DRAW);

		glm::vec3 pos = target->actual_pos - target->pos;

		glUniform1ui(0, NUM_RESULT_ELEMS);
		glUniform3f(1, pos[0], pos[1], pos[2]);

		auto it = util::find_if(pipeline->patches(), [&](const auto& p) { return p.first == target; });
		if (it == pipeline->patches().end())
		{
			counter = CANCELLED_COUNTER_VALUE;
			return;
		}

		GLuint offset = it->second;

		GLuint actual_offset = rounddown(pipeline->manager().block_size() * offset, pipeline->_ssbo_alignment);
		GLuint offset_param = (pipeline->manager().block_size() * offset - actual_offset) / sizeof(float);

		glUniform1ui(2, offset_param);

		glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, pipeline->manager().buffer(),
			actual_offset, pipeline->manager().block_size() + offset_param * sizeof(float));
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, tmpbuf);

		glDispatchCompute(NUM_COMPUTE_GROUPS, 1, 1);

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
	}
	void patch_pipeline::discalc_state::sum_result(size_t s)
	{
		glUseProgram(pipeline->_max_calc);

		glUniform1ui(0, (GLuint)s);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, tmpbuf);

		glDispatchCompute((s + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE, 1, 1);

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT);
	}
	void patch_pipeline::discalc_state::download_result()
	{
		glBindBuffer(GL_COPY_READ_BUFFER, tmpbuf);
		glBindBuffer(GL_COPY_WRITE_BUFFER, pipeline->_lengths);

		if (pipeline->_patches.size() == LENGTH_CACHE_SIZE)
		{
			glMemoryBarrier(GL_BUFFER_UPDATE_BARRIER_BIT);

			float bufvals[LENGTH_CACHE_SIZE];

			glGetBufferSubData(GL_COPY_WRITE_BUFFER, 0, LENGTH_CACHE_SIZE * sizeof(float), bufvals);

			for (size_t i = 0; i < LENGTH_CACHE_SIZE; ++i)
			{
				if (!pipeline->_patches[i].expired())
					pipeline->_patches[i].lock()->farthest_vertex = bufvals[i];
			}

			pipeline->_patches.clear();
		}

		glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, pipeline->_patches.size() * sizeof(float), sizeof(float));

		pipeline->_patches.push_back(target);

		glDeleteBuffers(1, &tmpbuf);
		tmpbuf = 0;
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
	void patch_pipeline::discalc_state::cancel()
	{
		counter = CANCELLED_COUNTER_VALUE;

		if (tmpbuf != 0)
			glDeleteBuffers(1, &tmpbuf);
	}

	bool patch_pipeline::generate_state::can_finalize() const
	{
		return counter == 2;
	}
	bool patch_pipeline::remove_state::can_finalize() const
	{
		return true;
	}
	bool patch_pipeline::discalc_state::can_finalize() const
	{
		return counter == util::log<SIDE_LEN * SIDE_LEN, SHADER_GROUP_SIZE>::value + 2;
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
			//OutputDebug("[PIPELINE] Attempted to remove patch ", target.get(), ". Patch wasn't present.\n");
			return;//assert(false);
		}
		//OutputDebug("[PIPELINE] Removed patch ", target.get(), ".\n");

		GLuint offset = it->second;

		MoveCommand mvcmd;
		mvcmd.is_new = GL_FALSE;
		mvcmd.source = 0;
		mvcmd.dest = offset;

		ustate.movecommands.push_back(mvcmd);

		pipeline->_offsets.erase(it);
		pipeline->manager().dealloc_block(offset);
	}
	void patch_pipeline::discalc_state::finalize(update_state& ustate)
	{

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
	patch_pipeline::discalc_state::discalc_state(std::shared_ptr<patch> tgt, patch_pipeline* pipeline) :
		target(tgt),
		counter(0),
		pipeline(pipeline),
		tmpbuf(0)
	{

	}
}
