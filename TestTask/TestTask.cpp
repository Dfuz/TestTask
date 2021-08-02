#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

#include "TestTask.h"

using namespace std;

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
	while (true)
	{}
	return 0;
}
