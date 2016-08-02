#include "renderer.h"
#include "shader.h"
#include <GLFW\glfw3.h>

#include <glm\gtc\matrix_transform.hpp>

using namespace planet_engine;
using namespace planet_engine::util;

extern const char* PlanetVertexShader;
extern const char* PlanetFragmentShader;

void(__stdcall *OldGlDetachShader)(GLuint, GLuint);
void __stdcall _glDetachShaderProxy(GLuint program, GLuint shader)
{
	OldGlDetachShader(program, shader);
}

int main()
{
	glfwInit();

	GLFWwindow* win = glfwCreateWindow(1080, 720, "Planet Engine Demo", nullptr, nullptr);
	glfwMakeContextCurrent(win);

	glDetachShader(0, 0);
	OldGlDetachShader = glDetachShader;
	glDetachShader = _glDetachShaderProxy;

	GLuint program;
	{
		glsl_shader shader = glsl_shader(false)
			.vertex(PlanetVertexShader)
			.fragment(PlanetFragmentShader)
			.link();

		if (shader.shader_log(GL_VERTEX_SHADER) != "")
		{
			printf("%s", shader.shader_log(GL_VERTEX_SHADER).c_str());

			assert(false);
			std::terminate();
		}
		if (shader.shader_log(GL_FRAGMENT_SHADER) != "")
		{
			printf("%s", shader.shader_log(GL_FRAGMENT_SHADER).c_str());

			assert(false);
			std::terminate();
		}

		if (shader.program_log() != "")
		{
			printf("%s", shader.program_log().c_str());

			assert(false);
			std::terminate();
		}

		program = shader.program();
	}

	renderer ren{ 10000.0, program };

	glm::dvec3 cam_pos = glm::dvec3(0.0, 0.0, -12000.0);

	ren.update(cam_pos);

	while (!glfwWindowShouldClose(win))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glm::dmat4 view_mat = glm::lookAt(cam_pos, glm::dvec3(0.0, 0.0, 0.0), glm::dvec3(0.0, 1.0, 0.0));
		glm::dmat4 proj_mat = glm::perspective(60.0, 1080.0 / 720.0, 100.0, 20000.0);

		ren.render(proj_mat * view_mat);
		ren.update(cam_pos);

		glfwPollEvents();
		glfwSwapBuffers(win);
	}

	glfwDestroyWindow(win);
	glfwTerminate();

	return 0;
}
