#include "input.h"

#include <glm\gtx\euler_angles.hpp>

namespace planet_engine
{
	namespace input
	{
		glm::dvec3 CamPos;
		glm::dquat CamRot;

		using glm::dmat4;
		using glm::dvec3;
		using glm::dquat;

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

		bool xDown = false;
		bool isLine = false;

		void HandleInput(GLFWwindow* win)
		{
			static constexpr double displacement = 0.02f;

			KeyboardInterface Keyboard(win);
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
				glfwSetWindowShouldClose(win, 1);

			dmat4 rmat = glm::eulerAngleYXZ(NewCamRot.x, NewCamRot.y, NewCamRot.z);
			CamRot *= glm::quat_cast(rmat);
		}
	}
}
