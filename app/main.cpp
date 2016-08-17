#include "renderer.h"
#include "shader.h"
#include "input.h"
#include <GLFW\glfw3.h>
#include <iostream>

#include <glm\gtc\matrix_transform.hpp>

using namespace planet_engine;
using namespace planet_engine::util;

#define TARGET_DIR "D:\\Projects\\Projects\\C++\\planet-engine\\x64\\Debug\\"

void tick();
void launch_watchdog();
void terminate_watchdog();

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

constexpr double deg2rad(double v)
{
	return v * 0.017453292519943295769;
}
constexpr double rad2deg(double v)
{
	return v * 57.295779513082320877;
}
glm::dmat4 projection(double fovy, double aspect, double near_z, double far_z)
{
	double tmp1 = 1.0 / std::tan(fovy);
	double tmp2 = 1.0 / (far_z - near_z);

	return glm::dmat4(
		tmp1, 0.0, 0.0, 0.0,
		0.0, aspect * tmp1, 0.0, 0.0,
		0.0, 0.0, (far_z + near_z)  * tmp2, 1.0,
		0.0, 0.0, -2.0*far_z*near_z * tmp2, 0.0);
}
glm::dmat4 translation(const glm::dvec3& v)
{
	return glm::dmat4(
		1.0, 0.0, 0.0, v.x,
		0.0, 1.0, 0.0, v.y,
		0.0, 0.0, 1.0, v.z,
		0.0, 0.0, 0.0, 1.0);
}

double aspect;

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
		return;break;
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
		return;break;
	default:
		severitystr = "[UNKNOWN]";
		break;
	}

	std::string str = message;
	if (*(str.end() - 1) == '\n')
		*(str.end() - 1) = '\0';

	OutputDebug(typestr, severitystr, ' ', message, '\n');
	OutputDebug("");
}

void WindowCallback(GLFWwindow* win, int xsz, int ysz)
{
	glViewport(0, 0, xsz, ysz);
	aspect = double(xsz) / double(ysz);
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

	GLFWwindow* win = glfwCreateWindow(1080, 720, "Planet Engine Demo", nullptr, nullptr);
	glfwMakeContextCurrent(win);

	glfwSetWindowSizeCallback(win, &WindowCallback);

	ogl_LoadFunctions();

	glfwSwapBuffers(win);

	aspect = 1.5;

	//launch_watchdog();

	//glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(DebugProc, nullptr);

	glClearColor(0.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);

	glPointSize(10);

	bool cDown = false;

	{
		GLuint program;
		{
			glsl_shader shader = glsl_shader(false);
			shader.vertex(read_file(concat("planet_shader_vert.glsl")));
			shader.fragment(read_file(concat("planet_shader_frag.glsl")));
			shader.link();
			shader.check_errors({ GL_VERTEX_SHADER, GL_FRAGMENT_SHADER });

			program = shader.program();

			glProgramUniform3f(program, 1, 0.0, 0.0, 1.0);
		}

		renderer ren{ program, 6700000.0 };
		renderer ren2{ program, 500000.0 };

		CamPos = glm::dvec3(0.0, 0.0, -ren.planet.data->planet_radius - 10000.0);
		CamRot = glm::dquat(1.0, 0.0, 0.0, 0.0);

		ren.update(CamPos);
		ren2.update(CamPos);

		size_t i = 0;
		while (!glfwWindowShouldClose(win))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glm::dmat4 view_mat = glm::inverse(glm::translate(glm::dmat4(1.0), CamPos) * (glm::dmat4)CamRot);
			glm::dmat4 model_mat = glm::translate(glm::dmat4(1.0), glm::dvec3(10000000.0, 0.0, 0.0));

			{
				glm::dmat4 proj_mat = projection(deg2rad(60.0), aspect, 10000.0, 1000000000.0);
				auto vp_mat = proj_mat * view_mat;

				ren.render(vp_mat);
				ren2.render(vp_mat * model_mat);
			}

			glClear(GL_DEPTH_BUFFER_BIT);

			{
				glm::dmat4 proj_mat = projection(deg2rad(60.0), aspect, 0.05, 10000.0);
				auto vp_mat = proj_mat * view_mat;

				ren.render(vp_mat);
				ren2.render(vp_mat * model_mat);
			}

			ren.update(CamPos);
			ren2.update(CamPos - glm::dvec3(10000000.0, 0.0, 0.0));

			HandleInput(win, 20000);

			glfwPollEvents();
			glfwSwapBuffers(win);

			tick();
		}

		glDeleteProgram(program);
	}

	//terminate_watchdog();

	glfwDestroyWindow(win);
	glfwTerminate();

	return 0;
}
