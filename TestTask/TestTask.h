#pragma once
#include <GLFWM/glfwm.hpp>

struct IShape
{
	virtual bool fillColor(float RED, float GREEN, float BLUE) = 0;
	virtual void setPosition(float X, float Y) const = 0;
	virtual void rotateShape(float angle) = 0;
	virtual void setScale(double scale) = 0;
};

class Dot : public glfwm::Drawable
{
	void draw(const glfwm::WindowID id) override
	{
		auto window = glfwm::Window::getWindow(id);
		int width = 0, height = 0;
		window->getSize(width, height);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, width, 0.0, height, 0.0, 1.0); // this creates a canvas you can do 2D drawing on
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPointSize(10);
		glLineWidth(4.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(10.0, 10.0, 0.0);
		glVertex3f(200.0, 200.0, 0.0);
		glEnd();
	}
};


