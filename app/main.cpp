#include "renderer.h"
#include <GLFW\glfw3.h>

#include <glm\gtc\matrix_transform.hpp>

using namespace planet_engine;

int main()
{
	glfwInit();

	GLFWwindow* win = glfwCreateWindow(1080, 720, "Planet Engine Demo", nullptr, nullptr);
	glfwMakeContextCurrent(win);

	renderer ren{ 10000.0 };

	glm::dvec3 cam_pos = glm::dvec3(0.0, 0.0, -12000.0);

	while (!glfwWindowShouldClose(win))
	{
		ren.update(cam_pos);

		glm::dmat4 view_mat = glm::lookAt(cam_pos, glm::dvec3(0.0, 0.0, 0.0), glm::dvec3(0.0, 1.0, 0.0));
		glm::dmat4 proj_mat = glm::perspective(60.0, 1080.0 / 720.0, 100.0, 20000.0);

		ren.render(proj_mat * view_mat, nullptr, 0);
	}
}
