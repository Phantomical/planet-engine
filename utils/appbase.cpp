#include "gl_core.h"
#include "appbase.h"

#include <sstream>
#include <Windows.h>

#include <glm\gtx\quaternion.hpp>
#include <glm\gtx\euler_angles.hpp>
#include <glm\gtc\matrix_transform.hpp>

namespace planet_engine
{
	namespace util
	{
		using glm::dmat4;
		using glm::dvec3;
		using glm::dquat;

		namespace
		{
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
		}

		struct KeyboardInterface
		{
		private:
			GLFWwindow* Window;

		public:
			KeyboardInterface(GLFWwindow* win) :
				Window(win)
			{

			}

			bool operator[](int key)
			{
				return glfwGetKey(Window, key) == GLFW_PRESS;
			}
		};

		void AppBase::HandleInput()
		{
			static constexpr double displacement = 0.02f;

			KeyboardInterface Keyboard(Window);
			dmat4 rot = (dmat4)CamRot;

			dvec3 left = dvec3(rot[0]);
			dvec3 up = dvec3(rot[1]);
			dvec3 front = dvec3(rot[2]);

			dvec3 NewCamRot;

			// Translate camera
			if (Keyboard[GLFW_KEY_W])
				CamPos += front * displacement;
			if (Keyboard[GLFW_KEY_S])
				CamPos -= front * displacement;
			if (Keyboard[GLFW_KEY_D])
				CamPos += left * displacement;
			if (Keyboard[GLFW_KEY_A])
				CamPos -= left * displacement;
			if (Keyboard[GLFW_KEY_Q])
				CamPos -= up * displacement;
			if (Keyboard[GLFW_KEY_E])
				CamPos += up * displacement;

			// Rotate camera
			if (Keyboard[GLFW_KEY_I])
				NewCamRot.y -= 0.1f;
			if (Keyboard[GLFW_KEY_K])
				NewCamRot.y += 0.1f;
			if (Keyboard[GLFW_KEY_J])
				NewCamRot.x -= 0.1f;
			if (Keyboard[GLFW_KEY_L])
				NewCamRot.x += 0.1f;
			if (Keyboard[GLFW_KEY_U])
				NewCamRot.z -= 0.1f;
			if (Keyboard[GLFW_KEY_O])
				NewCamRot.z += 0.1f;

			// Reset camera position and rotation
			if (Keyboard[GLFW_KEY_SPACE])
			{
				CamPos = dvec3(0, 0, 0);
				CamRot = dquat(1, 0, 0, 0);
			}

			// Toggle between wireframe and normal rendering
			if (Keyboard[GLFW_KEY_X])
			{
				if (!xDown)
				{
					if (isLine)
						glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					else
						glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
					isLine = !isLine;

					xDown = true;
				}
			}
			else
			{
				xDown = false;
			}

			// Close window
			if (Keyboard[GLFW_KEY_ESCAPE])
				glfwSetWindowShouldClose(Window, 1);

			// Shader recompile
			if (Keyboard[GLFW_KEY_R])
			{
				if (!rDown)
				{
					OnShaderRecompile();

					rDown = true;
				}
			}
			else
			{
				rDown = false;
			}

			dmat4 rmat = glm::eulerAngleYXZ(NewCamRot.x, NewCamRot.y, NewCamRot.z);
			CamRot *= glm::quat_cast(rmat);
		}
		void APIENTRY AppBase::DebugProc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void*)
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

			std::stringstream ss;
			ss << typestr << severitystr << ' ' << message << '\n';

			OutputDebugStringA(ss.str().c_str());
		}

		void AppBase::ResizeCallback(GLFWwindow* win, int xsz, int ysz)
		{
			AppBase* appbase = (AppBase*)glfwGetWindowUserPointer(win);
			glViewport(0, 0, xsz, ysz);
			appbase->Aspect = double(xsz) / double(ysz);
		}

		glm::dmat4 AppBase::GetViewMatrix() const
		{
			return glm::inverse(glm::translate(glm::dmat4(1.0), CamPos) * glm::mat4_cast(CamRot));
		}
		glm::dmat4 AppBase::GetProjMatrix() const
		{
			return projection(FovY, Aspect, NearZ, FarZ);
		}
		glm::dmat4 AppBase::GetVPMatrix() const
		{
			return GetProjMatrix() * GetViewMatrix();
		}

		void AppBase::Run()
		{
			glfwMakeContextCurrent(Window);

			OnLoad();

			while (!glfwWindowShouldClose(Window))
			{
				OnRenderFrame();
				OnUpdateFrame();

				glfwPollEvents();
				glfwSwapBuffers(Window);
			}

			OnUnload();
		}

		AppBase::AppBase(const char* title) :
			CamPos(0.0, 0.0, 0.0),
			CamRot(1.0, 0.0, 0.0, 0.0),
			FovY(deg2rad(60.0)),
			NearZ(0.05),
			FarZ(20.0),
			Aspect(1.5),
			xDown(false),
			isLine(false)
		{
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

			Window = glfwCreateWindow(1080, 720, title, nullptr, nullptr);
			glfwMakeContextCurrent(Window);
			
			glfwSetWindowSizeCallback(Window, ResizeCallback);
			glfwSetWindowUserPointer(Window, this);

			ogl_LoadFunctions();

			glDebugMessageCallback(&DebugProc, nullptr);
		}
		AppBase::~AppBase()
		{
			glfwDestroyWindow(Window);
		}
	}
}
