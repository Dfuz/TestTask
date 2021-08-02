#ifdef _WIN32
	#include <Windows.h>
#endif 
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <iostream>

#include "TestTask.h"

using namespace std;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{
	if (!glfwInit())
	{
		// Initialization failed
		cout << "Initialization failed!" << endl;
		return 1;
	}
	else cout << "Hello GLFW!" << endl;

	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		// Window or OpenGL context creation failed
		cout << "Window or OpenGL context creation failed!" << endl;
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	while (!glfwWindowShouldClose(window))
	{
		glfwSetKeyCallback(window, key_callback);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
