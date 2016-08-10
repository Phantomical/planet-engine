
#include "gl_core.h"
#include "shader.h"
#include "load_file.h"
#include "appbase.h"

#include "patch.h"

#include <glm\glm.hpp>
#include <GLFW\glfw3.h>

namespace util = planet_engine::util;
using namespace util;

constexpr size_t SIDE_LEN = 1024;
constexpr size_t NUM_VERTICES = planet_engine::num_vertices(SIDE_LEN);
constexpr size_t NUM_ELEMENTS = planet_engine::num_indices(SIDE_LEN);
constexpr size_t COMPUTE_GROUP_SIZE = 128;
static constexpr double radius = 10.0;

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

class MeshGenApp : public AppBase
{
public:
	MeshGenApp() :
		AppBase("Mesh Generation Demo")
	{

	}

	/* Shaders */
	GLuint meshgen;
	GLuint program;

	/* Buffers */
	GLuint elements;
	GLuint vertices;
	GLuint uniforms;

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

		shader prg(false);
		prg.vertex(read_file("vert.glsl"));
		prg.fragment(read_file("frag.glsl"));
		prg.link();

		prg.check_errors({ GL_VERTEX_SHADER, GL_FRAGMENT_SHADER });

		program = prg.program();

		glUseProgram(program);
		glUniform3f(1, LightDir[0], LightDir[1], LightDir[2]);
	}
	void GenBuffers()
	{
		unsigned int* elems = planet_engine::gen_indices(SIDE_LEN);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &elements);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * NUM_ELEMENTS, elems, GL_STATIC_DRAW);

		glGenBuffers(1, &vertices);
		glBindBuffer(GL_ARRAY_BUFFER, vertices);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 7 * NUM_VERTICES, nullptr, GL_STATIC_DRAW);

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
		glUseProgram(meshgen);

		glBindBuffer(GL_UNIFORM_BUFFER, uniforms);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(UniformLayout), &ComputeShaderUniforms, GL_DYNAMIC_DRAW);

		glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniforms);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, vertices);

		glUniform1ui(0, NUM_VERTICES);
		glUniform1ui(1, SIDE_LEN);

		glDispatchCompute((NUM_VERTICES + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);

		glMemoryBarrier(GL_ALL_BARRIER_BITS);
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
		MeshGenApp app;

		app.Run();
	}

	glfwTerminate();
}
