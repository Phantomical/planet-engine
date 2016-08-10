#pragma once
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\quaternion.hpp>

namespace planet_engine
{
	namespace input
	{
		extern glm::dvec3 CamPos;
		extern glm::dquat CamRot;

		void HandleInput(GLFWwindow* win);
	}
}
