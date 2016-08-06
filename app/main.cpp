#include "renderer.h"
#include "shader.h"
#include <GLFW\glfw3.h>
#include <sstream>

#include <glm\gtc\matrix_transform.hpp>

using namespace planet_engine;
using namespace planet_engine::util;

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
	std::string read_file(const std::string& fname);
}

void APIENTRY DebugProc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void*)
{
	const char* typestr;
	const char* severitystr;
	switch (type)
	{
	case GL_DEBUG_TYPE_ERROR:
		typestr = "[ERROR]";
		break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
		typestr = "[UNDEFINED BEHAVIOUR]";
		break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
		typestr = "[DEPRECATED BEHAVIOUR]";
		break;
	case GL_DEBUG_TYPE_PERFORMANCE:
		typestr = "[PERFORMANCE]";
		break;
	case GL_DEBUG_TYPE_PORTABILITY:
		typestr = "[PERFORMANCE]";
		break;
	case GL_DEBUG_TYPE_OTHER:
		typestr = "[OTHER]";
		break;
	default:
		typestr = "[UNKNOWN]";
		break;
	}
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:
		severitystr = "[HIGH]";
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		severitystr = "[MEDIUM]";
		break;
	case GL_DEBUG_SEVERITY_LOW:
		severitystr = "[LOW]";
		break;
	case GL_DEBUG_SEVERITY_NOTIFICATION:
		severitystr = "[NOTIFICATION]";
		return;
	default:
		severitystr = "[UNKNOWN]";
		break;
	}

	OutputDebug(typestr, severitystr, ' ', message, '\n');
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

	GLFWwindow* win = glfwCreateWindow(1080, 720, "Planet Engine Demo", nullptr, nullptr);
	glfwMakeContextCurrent(win);
	
	ogl_LoadFunctions();

	glfwSwapBuffers(win);
	
	//glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(DebugProc, nullptr);

	glClearColor(0.0, 0.0, 0.0, 1.0);

	{
		GLuint program;
		{
			glsl_shader shader = glsl_shader(false);
			shader.vertex(read_file(concat("planet_shader_vert.glsl")));
			shader.fragment(read_file(concat("planet_shader_frag.glsl")));
			shader.link();
			shader.check_errors({ GL_VERTEX_SHADER, GL_FRAGMENT_SHADER });

			program = shader.program();
		}

		renderer ren{ program, 10000.0 };

		glm::dvec3 cam_pos = glm::dvec3(0.0, 0.0, -12000.0);

		ren.update(cam_pos);

		while (!glfwWindowShouldClose(win))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glm::dmat4 view_mat = glm::lookAt(cam_pos, glm::dvec3(0.0, 0.0, 0.0), glm::dvec3(0.0, 1.0, 0.0));
			glm::dmat4 proj_mat = glm::perspective(60.0, 1080.0 / 720.0, 1000.0, 20000.0);

			ren.render(proj_mat * view_mat);
			ren.update(cam_pos);

			glfwPollEvents();
			glfwSwapBuffers(win);
		}

		glDeleteProgram(program);
	}

	glfwDestroyWindow(win);
	glfwTerminate();

	return 0;
}
