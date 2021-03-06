#include "renderer.h"
#include "shader.h"
#include "findutils.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iterator>
#include <utility>
#include <tuple>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>

#pragma warning(disable : 4267)

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

	std::string read_file(const std::string& path)
	{
		std::ifstream t(path);

		assert(t.is_open());

		std::stringstream buffer;
		buffer << t.rdbuf();
		return buffer.str();
	}

	void renderer::update_meshes()
	{
		static size_t add_max = 0;
		static size_t remove_max = 0;

		update_state ustate;

		{
			add_max = std::max(add_max, data->to_add.size());
			remove_max = std::max(remove_max, data->to_remove.size());

			for (auto p : data->to_add)
			{
				pipeline.generate(p);
			}

			for (auto p : data->to_remove)
			{
				pipeline.remove(p);
			}

			ustate = pipeline.process();

			data->to_add.clear();
			data->to_remove.clear();

			pipeline.cull();
		}

		if (ustate.movecommands.size() != 0)
		{
			glUseProgram(command_update);
			glUniform1ui(0, ustate.movecommands.size());
			
			GLuint buffers[2];
			glGenBuffers(2, buffers);
			
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffers[0]);
			glBufferData(GL_SHADER_STORAGE_BUFFER, ustate.movecommands.size() * sizeof(MoveCommand), ustate.movecommands.data(), GL_STATIC_DRAW);
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffers[1]);
			glBufferData(GL_SHADER_STORAGE_BUFFER, ustate.commands.size() * sizeof(DrawElementsIndirectCommand), ustate.commands.data(), GL_STATIC_DRAW);
			
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, buffers[1]);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, drawcommands);
			
			glDispatchCompute((ustate.movecommands.size() + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);
			
			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT | GL_COMMAND_BARRIER_BIT);
			
			glDeleteBuffers(2, buffers);
		}
	}

	/* Public Functions */
	void renderer::update(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel)
	{
		planet.update(cam_pos, cam_vel);

		// Add and remove meshes
		update_meshes();
	}
	void renderer::render(const glm::dmat4& mvp_mat)
	{
		size_t size = pipeline.manager().current_max();

		glm::mat4* matrices = new glm::mat4[size];

		for (size_t i = 0; i < visible.size(); ++i)
		{
			if (!visible[i].expired())
			{
				std::shared_ptr<patch> p = visible[i].lock();
				glm::dmat4 mat = mvp_mat * glm::translate(glm::dmat4(1.0), p->pos);
				matrices[i] = mat;
			}
		}

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, matbuffer);
		glBufferData(GL_SHADER_STORAGE_BUFFER, visible.size() * sizeof(glm::mat4), 
			matrices, GL_DYNAMIC_DRAW);
		
		delete[] matrices;

		glUseProgram(planet_shader);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, matbuffer);

		glBindBuffer(GL_DRAW_INDIRECT_BUFFER, visible_commands);

		glBindVertexArray(vertex_array);

		glMultiDrawElementsIndirect(GL_TRIANGLES, GL_UNSIGNED_INT, nullptr, visible.size(), 0);

		glBindVertexArray(0);
	}
	void renderer::frustum_cull(const frustum& f)
	{
		visible.clear();
		std::vector<std::pair<GLuint, GLuint>> cmds;

		for (const auto& val : pipeline.patches())
		{
			if (f.intersects(val.first->actual_pos, val.first->farthest_vertex))
			{
				cmds.emplace_back(val.second, (GLuint)cmds.size());
				visible.push_back(val.first);
			}
		}

		glUseProgram(copy_commands);

		glUniform1ui(0, cmds.size());

		GLuint commands;
		glGenBuffers(1, &commands);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, commands);
		glBufferData(GL_SHADER_STORAGE_BUFFER, cmds.size() * sizeof(GLuint) * 2, cmds.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, visible_commands);
		glBufferData(GL_SHADER_STORAGE_BUFFER, cmds.size() * sizeof(DrawElementsIndirectCommand),
			nullptr, GL_STATIC_DRAW);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, commands);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, drawcommands);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, visible_commands);

		glDispatchCompute((cmds.size() + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);

		glMemoryBarrier(GL_COMMAND_BARRIER_BIT);
	}
		
	/* Constructors and Destructors */
	renderer::renderer(GLuint shader, double planet_radius, double scale) :
		pipeline(NUM_BLOCKS),
		planet(planet_radius, scale),
		planet_shader(shader)
	{
		glsl_shader command_update = glsl_shader(false);
		command_update.compute(read_file("command_update.glsl"));
		command_update.link();
		command_update.check_errors({ GL_COMPUTE_SHADER });

		glsl_shader copy_commands = glsl_shader(false);
		copy_commands.compute(read_file("copy-commands.glsl"));
		copy_commands.link();
		copy_commands.check_errors({ GL_COMPUTE_SHADER });

		this->command_update = command_update.program();
		this->copy_commands = copy_commands.program();

		data = planet.data;

		unsigned int* indices = gen_indices(SIDE_LEN);
		
		glGenBuffers(1, &elements);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_indices(SIDE_LEN) * sizeof(unsigned int), indices, GL_STATIC_DRAW);

		glGenBuffers(1, &drawcommands);
		glBindBuffer(GL_DRAW_INDIRECT_BUFFER, drawcommands);
		glBufferData(GL_DRAW_INDIRECT_BUFFER, sizeof(DrawElementsIndirectCommand) * NUM_BLOCKS, nullptr, GL_STATIC_DRAW);

		GLuint zero = 0;
		glClearBufferData(GL_DRAW_INDIRECT_BUFFER, GL_R32UI, GL_RED, GL_UNSIGNED_INT, &zero);

		glGenBuffers(1, &matbuffer);
		glGenBuffers(1, &visible_commands);

		delete[] indices;

		glGenVertexArrays(1, &vertex_array);
		glBindVertexArray(vertex_array);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);

		glBindBuffer(GL_ARRAY_BUFFER, pipeline.manager().buffer());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(0));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(sizeof(float) * 3));
		glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(sizeof(float) * 6));
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, vOffset(sizeof(float) * 7));

		glBindVertexArray(0);
	}
	renderer::~renderer()
	{
		glDeleteProgram(command_update);

		glDeleteBuffers(1, &elements);
		glDeleteBuffers(1, &drawcommands);
		glDeleteBuffers(1, &matbuffer);
	}
}
