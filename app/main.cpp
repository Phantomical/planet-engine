#include "defs.h"
#include "renderer.h"
#include "shader.h"
#include "input.h"
#include <GLFW\glfw3.h>
#include <iostream>

#include <glm\gtc\matrix_transform.hpp>

using namespace planet_engine;
using namespace planet_engine::util;

#define TARGET_DIR "D:\\Projects\\Projects\\C++\\planet-engine\\x64\\Debug\\"

namespace
{
	std::string concat(const std::string& appendix)
	{
		return appendix;
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
glm::dmat4 translation(const glm::dvec3& v)
{
	return glm::dmat4(
		1.0, 0.0, 0.0, v.x,
		0.0, 1.0, 0.0, v.y,
		0.0, 0.0, 1.0, v.z,
		0.0, 0.0, 0.0, 1.0);
}

double aspect;
double displacement = 20;

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
		typestr = "[PORTABILITY]";
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

	std::string str = message;
	if (*(str.end() - 1) == '\n')
		*(str.end() - 1) = '\0';

	OutputDebug(typestr, severitystr, ' ', str.c_str(), '\n');
	OutputDebug("");
}

void WindowCallback(GLFWwindow* win, int xsz, int ysz)
{
	glViewport(0, 0, xsz, ysz);
	if (ysz == 0)
		ysz = 1;
	aspect = double(xsz) / double(ysz);
}
void ScrollCallback(GLFWwindow* win, double xoffset, double yoffset) {
	displacement = exp2(log2(displacement) + (yoffset / 10));
	std::cout << displacement << std::endl;
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

	GLFWwindow* win = glfwCreateWindow(1080, 720, "Planet Engine Demo", nullptr, nullptr);
	glfwMakeContextCurrent(win);

	glfwSetWindowSizeCallback(win, &WindowCallback);
	glfwSetScrollCallback(win, &ScrollCallback);

	glfwSwapBuffers(win);

	aspect = 1.5;

	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(DebugProc, nullptr);

	glClearColor(0.05f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);

	glDepthFunc(GL_GREATER);
	glClipControl(GL_LOWER_LEFT, GL_ZERO_TO_ONE);
	glDepthRange(1.0, 0.0);
	glClearDepth(0.0);

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

			glProgramUniform3f(program, 1, 0.0, 0.0, -1.0);
			glProgramUniform1f(program, 2, (float)deg2rad(5));
		}


		renderer ren{ program, 6700000.0 };
		renderer ren2{ program, 1000000.0, 10.0 };

		CamPos = glm::dvec3(0.0, 0.0, ren.planet.data->planet_radius + 100000);
		CamRot = glm::dquat(1.0, 0.0, 0.0, 0.0);

		ren.update(CamPos);
		ren2.update(CamPos);

		glm::dvec3 prevpos = CamPos;

		size_t i = 0;
		while (!glfwWindowShouldClose(win))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glm::dmat4 view_mat = glm::inverse(glm::translate(glm::dmat4(1.0), CamPos) * (glm::dmat4)CamRot);
			glm::dmat4 model_mat = glm::translate(glm::dmat4(1.0), glm::dvec3(10000000.0, 0.0, 0.0));

			frustum f{ view_mat *  glm::perspective(deg2rad(10.0), aspect, 0.1, 1000000000.0) };


			{
				glm::dmat4 proj_mat = glm::infinitePerspective(deg2rad(60.0), aspect, 10000.0);
				auto vp_mat = proj_mat * view_mat;

				ren.render(vp_mat);
				ren2.render(vp_mat * model_mat);
			}

			glClear(GL_DEPTH_BUFFER_BIT);

			{
				glm::dmat4 proj_mat = glm::perspective(deg2rad(60.0), aspect, 0.1, 21000.0);
				auto vp_mat = proj_mat * view_mat;

				ren.render(vp_mat);
				ren2.render(vp_mat * model_mat);
			}

			if (glfwGetKey(win, GLFW_KEY_F) != GLFW_PRESS)
			{
				ren.update(CamPos, (CamPos - prevpos) * 60.0);
				ren2.update(CamPos - glm::dvec3(10000000.0, 0.0, 0.0), CamPos - prevpos);
			}

			prevpos = CamPos;

			HandleInput(win, displacement);

			ren.frustum_cull(f);
			ren2.frustum_cull(f);

			glfwPollEvents();
			glfwSwapBuffers(win);
		}

		glDeleteProgram(program);
	}

	glfwDestroyWindow(win);
	glfwTerminate();

	return 0;
}
