#define _USE_MATH_DEFINES
#include <cmath>

#include "TestTask.h"
/*-----------------------------------------------------------------------*/
/*                     CLASS METHODS Location                            */
/*-----------------------------------------------------------------------*/
Location::Location(GLfloat InitX, GLfloat InitY)
	: _x(InitX), _y(InitY)
{}

GLfloat Location::getX()
{
	return _x;
}

GLfloat Location::getY()
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
		glColor3f(_red, _green, _blue);
		const auto& [axisX, axisY] = _coords[0];
		glBegin(GL_POLYGON);
		glVertex2f(_x, _y);
		glVertex2f(axisX, _y);
		glVertex2f(axisX, axisY);
		glVertex2f(_x, axisY);
		glEnd();
}

/*-----------------------------------------------------------------------*/
/*                     CLASS METHODS Circle                              */
/*-----------------------------------------------------------------------*/
void Circle::draw(const glfwm::WindowID id)
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
	glColor3f(_red, _green, _blue);
	glBegin(GL_POLYGON);

	for (size_t i = 0; i < 360; ++i)
	{
		auto theta = i * (M_PI / 180);
		glVertex2f(static_cast<GLfloat>(_x + _radius * cos(theta)), (static_cast<GLfloat>(_y + _radius * sin(theta))));
	}
	glEnd();
}

void Ring::draw(const glfwm::WindowID id)
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
	glColor3f(_red, _green, _blue);
	glBegin(GL_POLYGON);

	for (size_t i = 0; i < 360; ++i)
	{
		auto theta = i * (M_PI / 180);
		glVertex2f(static_cast<GLfloat>(_x + _radius * cos(theta)), (static_cast<GLfloat>(_y + _radius * sin(theta))));
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (size_t i = 0; i < 360; ++i)
	{
		auto theta = i * (M_PI / 180);
		glVertex2f(static_cast<GLfloat>(_x + (_radius - _ringWidth) * cos(theta)), 
				  (static_cast<GLfloat>(_y + (_radius - _ringWidth) * sin(theta))));
	}
	glEnd();
}
