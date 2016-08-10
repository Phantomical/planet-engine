
#include "gl_core.h"
#include "shader.h"
#include "load_file.h"

#include <glm\glm.hpp>
#include <GLFW\glfw3.h>


int main()
{
	glfwInit();
	
	glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	GLFWwindow* win = glfwCreateWindow(100, 100, "-INVISIBLE-", nullptr, nullptr);

	glfwMakeContextCurrent(win);

	GLuint program;
	{
		
	}
}
