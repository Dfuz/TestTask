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
/*                     CLASS METHODS DrawableShape                       */
/*-----------------------------------------------------------------------*/
template<size_t VertexCount>
DrawableShape<VertexCount>::DrawableShape(int InitX, int InitY,
		 float red, float green, float blue, 
		 float scale)
	: Location(InitX, InitY),
	_red(red), _green(green), _blue(blue),
	_scale(scale)
{
	_coords.resize(1);
}

//template<size_t VertexCount>
//void DrawableShape<VertexCount>::draw(const glfwm::WindowID id)
//{
//	const auto window = glfwm::Window::getWindow(id);
//	int width = 0, height = 0;
//	window->getSize(width, height);
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, width, 0.0, height, 0.0, 1.0);
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPointSize(10);
//	glLineWidth(_scale);
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_POINTS);
//	//glVertex3f(00.0, 00.0, 0.0);
//	glVertex3f(width, height, 0.0);
//	glEnd();
//}

template<size_t VertexCount>
void DrawableShape<VertexCount>::setScale(double scale)
{
	_scale = scale;
}

template<size_t VertexCount>
void DrawableShape<VertexCount>::setColor(float RED, float GREEN, float BLUE)
{
	_red = RED;
	_green = GREEN;
	_blue = BLUE;
}

/*-----------------------------------------------------------------------*/
/*                     CLASS METHODS DrawableShape                       */
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
		glPointSize(10);
		glLineWidth(_scale);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_QUADS);
		glVertex3f(_x, _y, 0.f);
		const auto& [axisX, axisY] = _coords[0];
;		glVertex3f(axisX, axisY, 0.f);
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
