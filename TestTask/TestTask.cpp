#include "TestTask.h"

using glfwm::WindowManager;
using glfwm::Window;
/*-----------------------------------------------------------------------*/
/*                     CLASS METHODS Location                            */
/*-----------------------------------------------------------------------*/
Location::Location(int InitX, int InitY)
	: _x(InitX), _y(InitY)
{}

int Location::getX()
{
	return _x;
}

int Location::getY()
{
	return _y;
}

/*-----------------------------------------------------------------------*/
/*                     CLASS METHODS Rectangle                           */
/*-----------------------------------------------------------------------*/
void Rectangle::draw(const glfwm::WindowID id)
{
		const auto window = glfwm::Window::getWindow(id);
		int width = 0, height = 0;
		window->getSize(width, height);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, width, 0.0, height, 0.0, 1.0);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glPointSize(10);
		glLineWidth(_scale);
		glColor3f(_red, _green, _blue);
		//glBegin(GL_POLYGON);
		//glVertex3f(_x, _y, 0.f);
		const auto& [axisX, axisY] = _coords[0];
		//glVertex3f(300, 300, 0.f);
		//glRectf(0, 0, 300, 300);
		//glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(_x, _y);
		glVertex2f(axisX, _y);
		glVertex2f(axisX, axisY);
		glVertex2f(_x, axisY);
		glEnd();
}

void Rectangle::rotateShape(float angle)
{
	return;
}

void Rectangle::moveTo(float X, float Y) const
{
	return;
}
