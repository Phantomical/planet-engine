#pragma once

#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\quaternion.hpp>

extern glm::dvec3 CamPos;
extern glm::dquat CamRot;

void HandleInput(GLFWwindow* win);
