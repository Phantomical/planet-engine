#include "renderer.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iterator>
#include <utility>
#include <tuple>
#include <stack>

#pragma warning(disable : 4267)

namespace planet_engine
{
#define vOffset(size) ((void*)(size))

	template<typename T, typename Container>
	bool contains(const Container& c, const T& val)
	{
		return std::find(std::begin(c), std::end(c), val) != std::end(c);
	}
	template<typename T, typename Container>
	auto find(Container& c, const T& val)
	{
		return std::find(std::begin(c), std::end(c), val);
	}
	template<typename T, typename Container, typename Pred>
	auto find_if(Container& c, const Pred& p)
	{
		return std::find_if(std::begin(c), std::end(c), p);
	}


	/* Mesh Manipulation and Calculation Functions */
	renderer::compute_state renderer::compute_bounds(std::initializer_list<std::shared_ptr<patch>> _meshes)
	{
		static constexpr size_t NUM_RESULT_ELEMS = compute_state::NUM_RESULT_ELEMS;
		static constexpr size_t NUM_COMPUTE_GROUPS = compute_state::NUM_COMPUTE_GROUPS;

		compute_state state;

		state.parent = this;
		state.size = NUM_RESULT_ELEMS;

		glUseProgram(length_calc);
		glGenBuffers(1, &state.result_buffer);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, state.result_buffer);
		glBufferData(GL_SHADER_STORAGE_BUFFER, NUM_RESULT_ELEMS * sizeof(float) * _meshes.size(), nullptr, GL_STATIC_DRAW);

		glUniform1ui(0, NUM_RESULT_ELEMS);

		for (auto patch : _meshes)
		{
			auto it = patches.find(patch);
			if (it != patches.end())
				continue;

			GLuint offset = std::get<0>(it->second);
			meshes.lock(offset);
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, meshes.buffer(), MESH_SIZE * offset, NUM_RESULT_ELEMS * VERTEX_SIZE);
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, state.result_buffer, NUM_RESULT_ELEMS * sizeof(float) * state.offsets.size(), NUM_RESULT_ELEMS * sizeof(float));

			glDispatchCompute(NUM_COMPUTE_GROUPS, 1, 1);

			state.offsets.push_back(offset);
		}

		state.patches.insert(state.patches.end(), _meshes.begin(), _meshes.end());

		return state;
	}

	void renderer::update_state::concat(const update_state& ust)
	{
		commands.insert(commands.end(), ust.commands.begin(), ust.commands.end());
		movecommands.insert(movecommands.end(), ust.movecommands.begin(), ust.movecommands.end());
	}

	void renderer::compute_state::compute_next()
	{
		if (size > 1)
		{
			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

			glUseProgram(parent->max_calc);

			glUniform1ui(0, size);

			size = (size + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE;

			for (size_t i = 0; i < offsets.size(); ++i)
			{
				glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, result_buffer, NUM_RESULT_ELEMS * sizeof(float) * i, NUM_RESULT_ELEMS * sizeof(float));

				glDispatchCompute(size, 1, 1);
			}
		}
	}
	bool renderer::compute_state::is_done() const
	{
		return size <= 1;
	}
	void renderer::compute_state::update_patches()
	{
		while (!is_done())
			compute_next();

		/* Get Results */
		float temp[1];

		std::vector<std::pair<GLuint, float>> result;

		glBindBuffer(GL_COPY_READ_BUFFER, result_buffer);
		glMemoryBarrier(GL_BUFFER_UPDATE_BARRIER_BIT);

		for (size_t i = 0; i < offsets.size(); ++i)
		{
			glGetBufferSubData(GL_COPY_READ_BUFFER, NUM_RESULT_ELEMS * sizeof(float), sizeof(float), temp);
			parent->meshes.unlock(offsets[i]);

			if (!patches[i].expired())
			{
				auto patch = patches[i].lock();
				patch->farthest_vertex = *temp;
			}
		}

		/* Cleanup */
		glDeleteBuffers(1, &result_buffer);
		offsets.clear();
		size = 0;
	}

	/* Mesh Management Functions */
	renderer::update_state renderer::add_meshes(std::initializer_list<std::shared_ptr<patch>> _meshes)
	{
		if (_meshes.size() == 0)
			return update_state();

		std::vector<std::shared_ptr<patch>> meshes(_meshes.begin(), _meshes.end());
		std::vector<mesh_info> infos;
		std::vector<offset_type> offsets;
		infos.reserve(meshes.size());
		offsets.reserve(meshes.size());
		std::vector<std::shared_ptr<patch>> compute_targets;

		for (auto patch : meshes)
		{
			mesh_info info;
			info.pos = patch->pos;
			info.nwc = patch->nwc;
			info.nec = patch->nec;
			info.swc = patch->swc;
			info.sec = patch->sec;
			info.planet_radius = data->planet_radius;
			info.skirt_depth = patch::SKIRT_DEPTH;
			info.scale = 1.0;

			offset_type offset = this->meshes.alloc_block();

			infos.push_back(info);
			offsets.push_back(offset);

			if (patch->farthest_vertex == std::numeric_limits<float>::max())
				compute_targets.push_back(patch);
		}

		GLuint buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_UNIFORM_BUFFER, buffer);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info) * infos.size(), infos.data(), GL_STATIC_DRAW);

		glUseProgram(meshgen);

		glUniform1ui(0, NUM_VERTICES);

		for (size_t i = 0; i < offsets.size(); ++i)
		{
			glBindBufferRange(GL_UNIFORM_BUFFER, 0, buffer, sizeof(mesh_info) * i, sizeof(mesh_info));
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, this->meshes.buffer(), offsets[i] * MESH_SIZE, MESH_SIZE);

			glDispatchCompute((NUM_VERTICES + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);
		}

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

		update_state ustate;

		for (size_t i = 0; i < meshes.size(); ++i)
		{
			DrawElementsIndirectCommand cmd;
			cmd.baseInstance = 0;
			cmd.baseVertex = NUM_VERTICES * offsets[i];
			cmd.count = NUM_INDICES;
			cmd.firstIndex = 0;
			cmd.instanceCount = 0;

			GLuint offset = drawcommands.alloc_block();

			MoveCommand mvcmd;
			mvcmd.dest = offset;
			mvcmd.source = i;
			mvcmd.is_new = true;

			patches.insert(std::make_pair(meshes[i], std::make_tuple(offsets[i], offset)));

			ustate.commands.push_back(cmd);
			ustate.movecommands.push_back(mvcmd);
		}

		compute_states.push_back(compute_bounds(
			std::initializer_list<std::shared_ptr<patch>>(compute_targets.data(),
				compute_targets.data() + compute_targets.size())));

		return ustate;
	}
	renderer::update_state renderer::remove_meshes(std::initializer_list<std::shared_ptr<patch>> _meshes)
	{
		update_state ustate;

		for (auto patch : _meshes)
		{
			auto it = patches.find(patch);
			auto offsets = it->second;

			GLuint offset = std::get<0>(offsets);
			GLuint cmdoffset = std::get<1>(offsets);

			patches.erase(it);
			drawcommands.dealloc_block(cmdoffset);
			meshes.dealloc_block(offset);

			MoveCommand mvcmd;
			mvcmd.source = 0;
			mvcmd.dest = cmdoffset;
			mvcmd.is_new = false;

			ustate.movecommands.push_back(mvcmd);
		}

		return ustate;
	}

	void renderer::step_compute_states()
	{
		for (auto& state : compute_states)
		{
			state.compute_next();
		}

		if (!compute_states.empty())
		{
			if (compute_states.front().is_done())
			{
				compute_states.front().update_patches();
				compute_states.pop_front();
			}
		}
	}
	void renderer::update_meshes()
	{
		update_state ustate;

		{
			std::vector<std::shared_ptr<patch>> to_add, to_remove;

			for (auto p : data->to_subdivide)
			{
				p->split();

				to_add.push_back(p->nw);
				to_add.push_back(p->ne);
				to_add.push_back(p->sw);
				to_add.push_back(p->se);

				to_remove.push_back(p);
			}

			for (auto p : data->to_merge)
			{
				std::stack<std::shared_ptr<patch>> stack;

				if (contains(to_remove, p))
					assert(false);
				to_remove.push_back(p);

				if (p->subdivided())
				{
					stack.push(p->nw);
					stack.push(p->ne);
					stack.push(p->sw);
					stack.push(p->se);
				}

				while (!stack.empty())
				{
					auto patch = stack.top();
					stack.pop();

					if (patch->subdivided())
					{
						stack.push(patch->nw);
						stack.push(patch->ne);
						stack.push(patch->sw);
						stack.push(patch->se);
					}

					if (contains(to_remove, patch))
						assert(false);

					to_remove.push_back(patch);
				}
			}

			ustate = add_meshes(std::initializer_list<std::shared_ptr<patch>>(
				to_add.data(), to_add.data() + to_add.size()));
			ustate.concat(remove_meshes(std::initializer_list<std::shared_ptr<patch>>(
				to_remove.data(), to_remove.data() + to_remove.size())));
		}

		glUseProgram(command_update);
		glUniform1ui(0, ustate.movecommands.size());

		GLuint buffers[2];
		glCreateBuffers(2, buffers);

		glNamedBufferData(buffers[0], ustate.movecommands.size() * sizeof(MoveCommand), ustate.movecommands.data(), GL_STATIC_DRAW);
		glNamedBufferData(buffers[1], ustate.commands.size() * sizeof(DrawElementsIndirectCommand), ustate.commands.data(), GL_STATIC_DRAW);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, buffers[1]);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, drawcommands.buffer());

		glDispatchCompute((ustate.movecommands.size() + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT | GL_COMMAND_BARRIER_BIT);

		glDeleteBuffers(2, buffers);
	}

	/* Public Functions */
	void renderer::update(const glm::dvec3& cam_pos)
	{
		planet.update(cam_pos);

		// Update compute shaders
		step_compute_states();
		// Add and remove meshes
		update_meshes();
	}
	void renderer::render(const glm::dmat4& mvp_mat)
	{
		glm::mat4* matrices = new glm::mat4[drawcommands.size()];

		GLuint buffer;
		glCreateBuffers(1, &buffer);

		for (auto& p : patches)
		{
			GLuint idx = std::get<1>(p.second);

			glm::dmat4 mat = glm::translate(glm::dmat4(1.0), p.first->pos);
			matrices[idx] = mvp_mat * mat;
		}

		glUseProgram(planet_shader);

		glNamedBufferData(GL_UNIFORM_BUFFER, drawcommands.size() * sizeof(glm::mat4), matrices, GL_STATIC_DRAW);

		delete[] matrices;

		glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffer);

		glBindBuffer(GL_DRAW_INDIRECT_BUFFER, drawcommands.buffer());
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);
		glBindBuffer(GL_ARRAY_BUFFER, meshes.buffer());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(0));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(sizeof(float) * 3));
		glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(sizeof(float) * 6));

		glMultiDrawElementsIndirect(GL_TRIANGLES, GL_UNSIGNED_INT, nullptr, drawcommands.size(), 0);
	}
}
