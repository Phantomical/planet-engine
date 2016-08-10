#include "renderer.h"
#include "shader.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iterator>
#include <utility>
#include <tuple>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>

#pragma warning(disable : 4267)

#define TARGET_DIR "D:\\Projects\\Projects\\C++\\planet-engine\\x64\\Debug\\"

namespace
{
	std::string concat(const std::string& appendix)
	{
		return TARGET_DIR + appendix;
	}
}

namespace planet_engine
{
#define vOffset(size) ((void*)(size))

	template<typename T>
	// Stores elements padded to a certain alignment
	// within a buffer
	struct aligned_buffer
	{
	private:
		GLuint _stride;
		GLuint _size;
		char* _array;

	public:
		aligned_buffer(GLuint alignment, GLuint size) :
			_size(size)
		{
			_stride = ((sizeof(T) + alignment - 1) / alignment) * alignment;
			_array = (char*)malloc(_stride * _size);

			for (size_t i = 0; i < _size; ++i)
			{
				new (_array + i * _stride) T();
			}
		}
		~aligned_buffer()
		{
			for (size_t i = 0; i < _size; ++i)
			{
				(*this)[i].~T();
			}
			free(_array);
		}

		GLuint size()
		{
			return _size * _stride;
		}
		GLuint stride()
		{
			return _stride;
		}
		void* data()
		{
			return _array;
		}

		T& operator[](GLuint idx)
		{
			assert(idx < _size);
			return *((T*)(_array + _stride * idx));
		}

		aligned_buffer(const aligned_buffer&) = delete;
	};

	template<typename T>
	T roundup(T val, T mult)
	{
		return ((val + mult - 1) / mult) * mult;
	}

	using util::glsl_shader;

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

	std::string read_file(const std::string& path)
	{
		std::ifstream t(path);

		assert(t.is_open());

		std::stringstream buffer;
		buffer << t.rdbuf();
		return buffer.str();
	}

	/* Mesh Manipulation and Calculation Functions */
	renderer::compute_state renderer::compute_bounds(std::initializer_list<std::shared_ptr<patch>> _meshes)
	{
		static constexpr size_t NUM_RESULT_ELEMS = compute_state::NUM_RESULT_ELEMS;
		static constexpr size_t NUM_COMPUTE_GROUPS = compute_state::NUM_COMPUTE_GROUPS;

		size_t result_size = roundup<size_t>(NUM_RESULT_ELEMS * sizeof(float), ssbo_offset_alignment);

		compute_state state;

		state.parent = this;
		state.size = NUM_RESULT_ELEMS;

		glUseProgram(length_calc);
		glGenBuffers(1, &state.result_buffer);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, state.result_buffer);
		glBufferData(GL_SHADER_STORAGE_BUFFER, result_size * _meshes.size(), nullptr, GL_STATIC_DRAW);

		glUniform1ui(0, NUM_RESULT_ELEMS);

		for (auto patch : _meshes)
		{
			auto it = patches.find(patch);
			if (it == patches.end())
				continue;

			GLuint offset = std::get<0>(it->second);
			meshes.lock(offset);
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, meshes.buffer(), meshes.block_size() * offset, NUM_RESULT_ELEMS * VERTEX_SIZE);
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, state.result_buffer, result_size * state.offsets.size(), result_size);

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
			size_t result_size = roundup<size_t>(NUM_RESULT_ELEMS * sizeof(float), parent->ssbo_offset_alignment);

			glMemoryBarrier(/*GL_SHADER_STORAGE_BARRIER_BIT*/GL_ALL_BARRIER_BITS);

			glUseProgram(parent->max_calc);

			glUniform1ui(0, size);

			size = (size + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE;

			for (size_t i = 0; i < offsets.size(); ++i)
			{
				glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, result_buffer, result_size * i, result_size);

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
		glMemoryBarrier(/*GL_BUFFER_UPDATE_BARRIER_BIT*/GL_ALL_BARRIER_BITS);

		size_t result_size = roundup<size_t>(NUM_RESULT_ELEMS * sizeof(float), parent->ssbo_offset_alignment);

		for (size_t i = 0; i < offsets.size(); ++i)
		{
			glGetBufferSubData(GL_COPY_READ_BUFFER, result_size * i, sizeof(float), temp);
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
		aligned_buffer<mesh_info> infos(ubo_offset_alignment, meshes.size());
		std::vector<offset_type> offsets;
		offsets.reserve(meshes.size());
		std::vector<std::shared_ptr<patch>> compute_targets;

		for (size_t i = 0; i < meshes.size(); ++i)
		{
			auto patch = meshes[i];
			mesh_info info =
			{
				patch->pos,
				data->planet_radius,
				patch->nwc,
				patch::SKIRT_DEPTH,
				patch->nec,
				SCALE, // Scale value
				patch->swc,
				0.0, // Padding
				info.sec = patch->sec,
				0.0 // Padding
			};

			offset_type offset = this->meshes.alloc_block();

			infos[i] = info;
			offsets.push_back(offset);

			if (patch->farthest_vertex == std::numeric_limits<float>::max())
				compute_targets.push_back(patch);
		}


		glUseProgram(meshgen);

		glUniform1ui(0, NUM_VERTICES);

		for (size_t i = 0; i < offsets.size(); ++i)
		{
			//glUniform1ui(2, this->meshes.block_size() / VERTEX_SIZE * offsets[i]);

			GLuint buffer;
			glGenBuffers(1, &buffer);
			glBindBuffer(GL_UNIFORM_BUFFER, buffer);
			glBufferData(GL_UNIFORM_BUFFER, sizeof(mesh_info), &infos[i], GL_STATIC_DRAW);

			glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffer);
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, this->meshes.buffer(), offsets[i] * this->meshes.block_size(), this->meshes.block_size());

			glDispatchCompute(((NUM_VERTICES + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE), 1, 1);

			glDeleteBuffers(1, &buffer);
		}

		glMemoryBarrier(/*GL_SHADER_STORAGE_BARRIER_BIT*/GL_ALL_BARRIER_BITS);

		update_state ustate;

		for (size_t i = 0; i < meshes.size(); ++i)
		{
			DrawElementsIndirectCommand cmd;
			cmd.baseInstance = 0;
			cmd.baseVertex = (this->meshes.block_size() / VERTEX_SIZE) * offsets[i];
			cmd.count = NUM_INDICES;
			cmd.firstIndex = 0;
			cmd.instanceCount = 0;

			MoveCommand mvcmd;
			mvcmd.dest = offsets[i];
			mvcmd.source = i;
			mvcmd.is_new = true;

			patches.insert(std::make_pair(meshes[i], std::make_tuple(offsets[i])));

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
			if (it == patches.end())
				continue;
			auto offsets = it->second;

			GLuint offset = std::get<0>(offsets);

			patches.erase(it);
			meshes.dealloc_block(offset);

			MoveCommand mvcmd;
			mvcmd.source = 0;
			mvcmd.dest = offset;
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

			for (auto p : patches)
			{
				if (p.first->level != 0	&& p.first->parent.expired())
					to_remove.push_back(p.first);
			}

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

				if (!contains(to_add, p))
					to_add.push_back(p);

				{
					auto it = find(to_remove, p);
					if (it != to_remove.end())
						to_remove.erase(it);
				}

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

					{
						auto it = find(to_add, patch);
						if (it != to_add.end())
						{
							to_add.erase(it);
							continue;
						}
					}

					if (patch->subdivided())
					{
						stack.push(patch->nw);
						stack.push(patch->ne);
						stack.push(patch->sw);
						stack.push(patch->se);
					}

					if (!contains(to_remove, patch))
						to_remove.push_back(patch);
				}

				if (p->subdivided())
					p->merge();
			}

			data->to_subdivide.clear();
			data->to_merge.clear();

			ustate = add_meshes(std::initializer_list<std::shared_ptr<patch>>(
				to_add.data(), to_add.data() + to_add.size()));
			ustate.concat(remove_meshes(std::initializer_list<std::shared_ptr<patch>>(
				to_remove.data(), to_remove.data() + to_remove.size())));
		}

		if (ustate.movecommands.size() != 0)
		{
			//glUseProgram(command_update);
			//glUniform1ui(0, ustate.movecommands.size());
			//
			//GLuint buffers[2];
			//glCreateBuffers(2, buffers);
			//
			//glNamedBufferData(buffers[0], ustate.movecommands.size() * sizeof(MoveCommand), ustate.movecommands.data(), GL_STATIC_DRAW);
			//glNamedBufferData(buffers[1], ustate.commands.size() * sizeof(DrawElementsIndirectCommand), ustate.commands.data(), GL_STATIC_DRAW);
			//
			//glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
			//glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, buffers[1]);
			//glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, drawcommands);
			//
			//glDispatchCompute((ustate.movecommands.size() + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);
			//
			//glMemoryBarrier(/*GL_SHADER_STORAGE_BARRIER_BIT | GL_COMMAND_BARRIER_BIT*/ GL_ALL_BARRIER_BITS);
			//
			//glDeleteBuffers(2, buffers);

			DrawElementsIndirectCommand* commands = (DrawElementsIndirectCommand*)glMapNamedBufferRange(drawcommands, 0,
				sizeof(DrawElementsIndirectCommand) * meshes.max_index(), GL_MAP_READ_BIT | GL_MAP_WRITE_BIT);

			for (auto cmd : ustate.movecommands)
			{
				if (cmd.is_new)
				{
					commands[cmd.dest] = ustate.commands[cmd.source];
				}
				else
				{
					std::memset(commands + cmd.dest, 0, sizeof(DrawElementsIndirectCommand));
				}
			}

			glUnmapNamedBuffer(drawcommands);
		}
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
		size_t size = meshes.current_max();

		GLuint buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffer);
		glBufferData(GL_SHADER_STORAGE_BUFFER, size * sizeof(glm::mat4), nullptr, GL_STATIC_DRAW);

		glm::mat4* matrices = (glm::mat4*)glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);

		for (auto& p : patches)
		{
			GLuint idx = std::get<0>(p.second);
			assert(idx < size);

			glm::dmat4 mat = glm::translate(glm::dmat4(1.0), p.first->pos);
			matrices[idx] = mvp_mat * mat;
		}

		glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);

		glUseProgram(planet_shader);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffer);

		glBindBuffer(GL_DRAW_INDIRECT_BUFFER, drawcommands);

		glBindVertexArray(vertex_array);

		DrawElementsIndirectCommand* commands = (DrawElementsIndirectCommand*)glMapBuffer(GL_DRAW_INDIRECT_BUFFER, GL_READ_ONLY);

		for (size_t i = 0; i < size; ++i)
		{
			DrawElementsIndirectCommand command = commands[i];

			if (command.count == 0)
				continue;

			glUniformMatrix4fv(0, 1, GL_FALSE, &matrices[i][0][0]);

			glDrawElementsBaseVertex(GL_TRIANGLES, commands[i].count, GL_UNSIGNED_INT, (void*)commands[i].firstIndex, commands[i].baseVertex);
		}

		glUnmapBuffer(GL_DRAW_INDIRECT_BUFFER);
		//glMultiDrawElementsIndirect(GL_TRIANGLES, GL_UNSIGNED_INT, nullptr, size, 0);

		glBindVertexArray(0);

		glDeleteBuffers(1, &buffer);
	}

	/* Constructors and Destructors */
	renderer::renderer(GLuint shader, double planet_radius) :
		meshes(MESH_SIZE, NUM_BLOCKS),
		planet(planet_radius),
		planet_shader(shader)
	{
		glsl_shader meshgen = glsl_shader(false);
		meshgen.compute(read_file(concat("mesh_gen.glsl")));
		meshgen.link();
		meshgen.check_errors({ GL_COMPUTE_SHADER });

		glsl_shader max_calc = glsl_shader(false);
		max_calc.compute(read_file(concat("max.glsl")));
		max_calc.link();
		max_calc.check_errors({ GL_COMPUTE_SHADER });

		glsl_shader length_calc = glsl_shader(false);
		length_calc.compute(read_file(concat("length.glsl")));
		length_calc.link();
		length_calc.check_errors({ GL_COMPUTE_SHADER });

		glsl_shader command_update = glsl_shader(false);
		command_update.compute(read_file(concat("length.glsl")));
		command_update.link();
		command_update.check_errors({ GL_COMPUTE_SHADER });

		this->meshgen = meshgen.program();
		this->max_calc = max_calc.program();
		this->length_calc = length_calc.program();
		this->command_update = command_update.program();

		glProgramUniform1ui(this->meshgen, 1, SIDE_LEN);

		data = planet.data;

		unsigned int* indices = gen_indices(SIDE_LEN);

		GLint ubo_align;
		glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &ubo_align);
		ubo_offset_alignment = ubo_align;
		GLint ssbo_align;
		glGetIntegerv(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, &ssbo_align);
		ssbo_offset_alignment = ssbo_align;

		glCreateBuffers(1, &elements);
		glNamedBufferData(elements, num_indices(SIDE_LEN) * sizeof(unsigned int), indices, GL_STATIC_DRAW);

		glCreateBuffers(1, &drawcommands);
		glNamedBufferData(drawcommands, sizeof(DrawElementsIndirectCommand) * NUM_BLOCKS, nullptr, GL_STATIC_DRAW);

		delete[] indices;

		glGenVertexArrays(1, &vertex_array);
		glBindVertexArray(vertex_array);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, meshes.buffer());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(0));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(sizeof(float) * 3));
		glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(sizeof(float) * 6));

		glBindVertexArray(0);
	}
	renderer::~renderer()
	{
		glDeleteProgram(meshgen);
		glDeleteProgram(max_calc);
		glDeleteProgram(length_calc);
		glDeleteProgram(command_update);

		glDeleteBuffers(1, &elements);
	}
}
