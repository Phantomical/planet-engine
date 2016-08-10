#pragma once

#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\quaternion.hpp>

namespace planet_engine
{
	namespace util
	{
		constexpr double deg2rad(double v)
		{
			return v * 0.017453292519943295769;
		}
		constexpr double rad2deg(double v)
		{
			return v * 57.295779513082320877;
		}

		class AppBase
		{
		protected:
			GLFWwindow* Window;
			glm::dvec3 CamPos;
			glm::dquat CamRot;
			double FovY;
			double NearZ;
			double FarZ;
			double Aspect;

			void HandleInput();

		private:
			bool xDown;
			bool isLine;
			bool rDown;

			static void APIENTRY DebugProc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void*);
			static void ResizeCallback(GLFWwindow* win, int xsz, int ysz);

		public:
			virtual void OnLoad() { }
			virtual void OnUpdateFrame() { }
			virtual void OnRenderFrame() { }
			virtual void OnUnload() { }
			virtual void OnShaderRecompile() { }

			void Run();

			glm::dmat4 GetViewMatrix() const;
			glm::dmat4 GetProjMatrix() const;
			glm::dmat4 GetVPMatrix() const;

			AppBase(const char* title);
			~AppBase();
		};
	}
}
