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

	std::string read_file(const std::string& path)
	{
		std::ifstream t(path);

		assert(t.is_open());

		std::stringstream buffer;
		buffer << t.rdbuf();
		return buffer.str();
	}

	/* Mesh Manipulation and Calculation Functions */
	void update_state::concat(const update_state& ust)
	{
		commands.insert(commands.end(), ust.commands.begin(), ust.commands.end());
		movecommands.insert(movecommands.end(), ust.movecommands.begin(), ust.movecommands.end());
	}

	void renderer::update_meshes(size_t n)
	{
		update_state ustate;

		{
			for (auto p : data->to_add)
			{
				pipeline.generate(p);
			}

			for (auto p : data->to_remove)
			{
				pipeline.remove(p);
			}

			ustate = pipeline.process(n);

			data->to_add.clear();
			data->to_remove.clear();

			pipeline.cull();

			//if (!to_compute.empty())
			//	compute_states.push_back(compute_bounds(std::initializer_list<std::shared_ptr<patch>>(
			//		to_compute.data(), to_compute.data() + to_compute.size())));
		}

		if (ustate.movecommands.size() != 0)
		{
			glUseProgram(command_update);
			glUniform1ui(0, ustate.movecommands.size());
			
			GLuint buffers[2];
			glCreateBuffers(2, buffers);
			
			glNamedBufferData(buffers[0], ustate.movecommands.size() * sizeof(MoveCommand), ustate.movecommands.data(), GL_STATIC_DRAW);
			glNamedBufferData(buffers[1], ustate.commands.size() * sizeof(DrawElementsIndirectCommand), ustate.commands.data(), GL_STATIC_DRAW);
			
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, buffers[1]);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, drawcommands);
			
			glDispatchCompute((ustate.movecommands.size() + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);
			
			glMemoryBarrier(/*GL_SHADER_STORAGE_BARRIER_BIT | GL_COMMAND_BARRIER_BIT*/ GL_ALL_BARRIER_BITS);
			
			glDeleteBuffers(2, buffers);

			//DrawElementsIndirectCommand* commands = (DrawElementsIndirectCommand*)glMapNamedBuffer(drawcommands, GL_READ_WRITE);
			//
			////std::memset(commands, 0, sizeof(DrawElementsIndirectCommand) * pipeline.manager().max_index());
			//
			//for (auto p : pipeline.patches())
			//{
			//	DrawElementsIndirectCommand cmd;
			//	cmd.baseInstance = 0;
			//	cmd.baseVertex = p.second * pipeline.manager().block_size() / VERTEX_SIZE;
			//	cmd.count = NUM_INDICES;
			//	cmd.firstIndex = 0;
			//	cmd.instanceCount = 1;
			//}
			//
			//for (auto cmd : ustate.movecommands)
			//{
			//	if (cmd.is_new)
			//	{
			//		commands[cmd.dest] = ustate.commands[cmd.source];
			//	}
			//	else
			//	{
			//		std::memset(commands + cmd.dest, 0, sizeof(DrawElementsIndirectCommand));
			//	}
			//}
			//
			//glUnmapNamedBuffer(drawcommands);
		}
	}

	/* Public Functions */
	void renderer::update(const glm::dvec3& cam_pos)
	{
		planet.update(cam_pos);

		// Add and remove meshes
		update_meshes(COMMANDS_PER_FRAME);
	}
	void renderer::render(const glm::dmat4& mvp_mat)
	{
		size_t size = pipeline.manager().current_max();

		glm::mat4* matrices = new glm::mat4[size];

		for (auto& p : pipeline.patches())
		{
			GLuint idx = p.second;
			assert(idx < size);

			glm::dmat4 mat = mvp_mat * glm::translate(glm::dmat4(1.0), p.first->pos);
			matrices[idx] = mat;
		}

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, matbuffer);
		glBufferData(GL_SHADER_STORAGE_BUFFER, size * sizeof(glm::mat4), matrices, GL_DYNAMIC_DRAW);
		
		delete[] matrices;

		glUseProgram(planet_shader);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, matbuffer);

		glBindBuffer(GL_DRAW_INDIRECT_BUFFER, drawcommands);

		glBindVertexArray(vertex_array);

		glMultiDrawElementsIndirect(GL_TRIANGLES, GL_UNSIGNED_INT, nullptr, size, 0);

		glBindVertexArray(0);
	}
	
	/* Constructors and Destructors */
	renderer::renderer(GLuint shader, double planet_radius) :
		pipeline(NUM_BLOCKS),
		planet(planet_radius),
		planet_shader(shader)
	{
		glsl_shader command_update = glsl_shader(false);
		command_update.compute(read_file("command_update.glsl"));
		command_update.link();
		command_update.check_errors({ GL_COMPUTE_SHADER });

		this->command_update = command_update.program();

		data = planet.data;
		data->scale = SCALE;

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
