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
void draw_heptagon() 
{
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.6f, 0.8f, -5.0f);
	glVertex3f(0.0f, 1.0f, -5.0f);
	glVertex3f(0.6f, 0.8f, -5.0f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.6f, 0.8f, -5.0f);
	glVertex3f(0.8f, 0.4f, -5.0f);
	glVertex3f(-0.8f, 0.4f, -5.0f);
	glVertex3f(-0.6f, 0.8f, -5.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.8f, 0.4f, -5.0f);
	glVertex3f(0.6f, 0.0f, -5.0f);
	glVertex3f(-0.6f, 0.0f, -5.0f);
	glVertex3f(-0.8f, 0.4f, -5.0f);
	glEnd();
}

//Initializes 3D rendering
void initializeRendering()
{
	glfwInit();
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
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
	glEnable(GL_DEPTH_TEST);

	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		// Window or OpenGL context creation failed
		cout << "Window or OpenGL context creation failed!" << endl;
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(20);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window))
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		//
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //clear background screen to black

		//Clear information from last draw
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
		glLoadIdentity(); //Reset the drawing perspective

		glBegin(GL_QUADS); //Begin quadrilateral coordinates

		//Trapezoid
		glVertex3f(-0.7f, -1.5f, -5.0f);
		glVertex3f(0.7f, -1.5f, -5.0f);
		glVertex3f(0.4f, -0.5f, -5.0f);
		glVertex3f(-0.4f, -0.5f, -5.0f);

		glEnd(); //End quadrilateral coordinates

		glBegin(GL_TRIANGLES); //Begin triangle coordinates

		//Pentagon
		glVertex3f(0.5f, 0.5f, -5.0f);
		glVertex3f(1.5f, 0.5f, -5.0f);
		glVertex3f(0.5f, 1.0f, -5.0f);

		glVertex3f(0.5f, 1.0f, -5.0f);
		glVertex3f(1.5f, 0.5f, -5.0f);
		glVertex3f(1.5f, 1.0f, -5.0f);

		glVertex3f(0.5f, 1.0f, -5.0f);
		glVertex3f(1.5f, 1.0f, -5.0f);
		glVertex3f(1.0f, 1.5f, -5.0f);

		//Triangle
		glVertex3f(-0.5f, 0.5f, -5.0f);
		glVertex3f(-1.0f, 1.5f, -5.0f);
		glVertex3f(-1.5f, 0.5f, -5.0f);

		glEnd(); //End triangle coordinates
		//


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
