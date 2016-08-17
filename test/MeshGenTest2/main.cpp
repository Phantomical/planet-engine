
#include "gl_core.h"
#include "shader.h"
#include "load_file.h"
#include "appbase.h"

#include "patch.h"

#include <glm\glm.hpp>
#include <GLFW\glfw3.h>

using namespace planet_engine::util;

constexpr size_t SIDE_LEN = 2;
constexpr size_t NUM_VERTICES = planet_engine::num_vertices(SIDE_LEN);
constexpr size_t NUM_ELEMENTS = planet_engine::num_indices(SIDE_LEN);
constexpr size_t COMPUTE_GROUP_SIZE = 128;
static constexpr double radius = 10.0;
static constexpr size_t VERTEX_SIZE = sizeof(float) * 8;
static constexpr size_t MESH_SIZE = NUM_VERTICES * VERTEX_SIZE;
static constexpr size_t VERTEX_BUFFER_SIZE = (SIDE_LEN + 2) * (SIDE_LEN + 2) * sizeof(float) * 4;
static constexpr size_t NUM_INVOCATIONS = ((SIDE_LEN + 2) * (SIDE_LEN + 2) + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE;
static constexpr size_t GEN_VERTEX_INVOCATIONS = (SIDE_LEN + 2 + 7) / 8;

using glm::dvec3;
using glm::dvec4;
using glm::dmat4;
using glm::mat4;
using glm::vec3;

struct UniformLayout
{
	glm::dvec3 pos;
	double planet_radius;
	glm::dvec3 nwc;
	double skirt_depth;
	glm::dvec3 nec;
	double scale;
	glm::dvec3 swc;
	double _pad4;
	glm::dvec3 sec;
	double _pad5;
};

class MeshGen2App : public AppBase
{
public:
	MeshGen2App() :
		AppBase("Mesh Generation Demo 2")
	{

	}

	/* Shaders */
	GLuint vertex_gen;
	GLuint meshgen;
	GLuint program;

	/* Buffers */
	GLuint elements;
	GLuint vertices;
	GLuint uniforms;
	GLuint buffer;

	/* Vertex Array Objects */
	GLuint vao;

	/* Uniform Values */
	UniformLayout ComputeShaderUniforms;
	vec3 LightDir;

	void GenShaders(bool fail = true)
	{
		shader meshgen(false);
		meshgen.compute(read_file("mesh_gen.glsl"));
		meshgen.link();

		meshgen.check_errors({ GL_COMPUTE_SHADER }, fail);

		this->meshgen = meshgen.program();

		shader vertgen(false);
		vertgen.compute(read_file("vertex_gen.glsl"));
		vertgen.link();

		vertgen.check_errors({ GL_COMPUTE_SHADER }, fail);

		this->vertex_gen = vertgen.program();

		shader prg(false);
		prg.vertex(read_file("vert.glsl"));
		prg.fragment(read_file("frag.glsl"));
		prg.link();

		prg.check_errors({ GL_VERTEX_SHADER, GL_FRAGMENT_SHADER }, fail);

		program = prg.program();

		glUseProgram(program);
		glUniform3f(1, LightDir[0], LightDir[1], LightDir[2]);
	}
	void GenBuffers()
	{
		unsigned int* elems = planet_engine::gen_indices(SIDE_LEN);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &buffer);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffer);
		glBufferStorage(GL_SHADER_STORAGE_BUFFER, VERTEX_BUFFER_SIZE, nullptr, 0);

		glGenBuffers(1, &elements);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * NUM_ELEMENTS, elems, GL_STATIC_DRAW);

		glGenBuffers(1, &vertices);
		glBindBuffer(GL_ARRAY_BUFFER, vertices);
		glBufferData(GL_ARRAY_BUFFER, VERTEX_SIZE * NUM_VERTICES, nullptr, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 3));
		glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 6));

		glBindVertexArray(0);

		glGenBuffers(1, &uniforms);

		delete[] elems;
	}
	void GenVertices()
	{
		glBindBuffer(GL_UNIFORM_BUFFER, uniforms);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(UniformLayout), &ComputeShaderUniforms, GL_DYNAMIC_DRAW);
		
		glUseProgram(vertex_gen);
		
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniforms);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffer);

		glDispatchCompute(GEN_VERTEX_INVOCATIONS, GEN_VERTEX_INVOCATIONS, 1);
		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

		glUseProgram(meshgen);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffer);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, vertices);

		glDispatchCompute(NUM_INVOCATIONS, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);
	}

	void OnLoad() override
	{
		UniformLayout vals =
		{
			dvec3(0.0, 10.0, 0.0),
			radius,
			dvec3(radius, radius, -radius),
			2.0, // Skirt Depth
			dvec3(-radius, radius, -radius),
			1.0, // Scale
			dvec3(radius, radius, radius),
			0.0, // Padding
			dvec3(-radius, radius, radius)
		};

		ComputeShaderUniforms = vals;

		LightDir = -vec3(0.0, 0.5, 0.5);

		GenShaders();
		GenBuffers();
		GenVertices();

		glClearColor(0.0, 0.0, 1.0, 1.0);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		NearZ = 0.0005;
	}
	void OnUnload() override
	{
		glDeleteProgram(meshgen);
		glDeleteProgram(program);

		glDeleteBuffers(1, &elements);
		glDeleteBuffers(1, &vertices);
		glDeleteBuffers(1, &uniforms);
	}

	void OnUpdateFrame() override
	{
		HandleInput();
	}
	void OnRenderFrame() override
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(program);

		glBindVertexArray(vao);

		mat4 MVP = (mat4)GetVPMatrix();
		glUniformMatrix4fv(0, 1, GL_FALSE, &MVP[0][0]);

		glDrawElements(GL_TRIANGLES, NUM_ELEMENTS, GL_UNSIGNED_INT, nullptr);

		glBindVertexArray(0);
	}

	void OnShaderRecompile() override
	{
		printf("Recompiling...\n");

		glDeleteProgram(meshgen);
		glDeleteProgram(program);

		GenShaders(false);
		GenVertices();
	}
};


int main()
{
	glfwInit();

	{
		MeshGen2App app;

		app.Run();
	}

	glfwTerminate();
}
