#pragma once
#include <vector>
#include <array>
#include <list>
#include <GLFWM/glfwm.hpp>

using std::initializer_list;
using std::array;
using std::pair;
using std::list;

/// <summary>
/// Interface for abstract shape
/// </summary>
struct IShape
{
	virtual void setColor(float RED, float GREEN, float BLUE) = 0;
	virtual void moveTo(float offsetX, float offsetY) = 0;
	virtual void setScale(double scale) = 0;
	virtual ~IShape() {}
};

/// <summary>
/// Class-helper
/// </summary>
class Location
{
protected: 
	GLfloat _x;
	GLfloat _y;
public:
	Location(GLfloat InitX = 0, GLfloat InitY = 0);
	~Location() {};
	GLfloat getX();
	GLfloat getY();
};

/// <summary>
/// Abstract-class:
/// void draw(const glfwm::WindowID id)
/// are pure virtual function and must be implemented
/// </summary>
template<size_t VertexCount>
class DrawableShape : public Location, public IShape, public glfwm::Drawable
{
protected:
	GLfloat _red, _green, _blue;
	array<pair<float, float>, VertexCount> _coords;
	double _scale;
public:
	DrawableShape(GLfloat InitX = 0, GLfloat InitY = 0,
		float red = 0.f, float green = 0.f, float blue = 0.f,
		float scale = 0.f) 
		: Location(InitX, InitY),
		_red(red), _green(green), _blue(blue),
		_scale(scale) 
	{};
	~DrawableShape() {}
	void setColor(float RED, float GREEN, float BLUE) override
	{
		_red = RED;
		_green = GREEN;
		_blue = BLUE;
	}
	void setScale(double scale) override { _scale = scale; }
	bool setVertex(initializer_list<pair<float, float>> initList)
	{
		if (initList.size() != VertexCount) return false;
		auto iterator = initList.begin();
		for (size_t i = 0; i < initList.size(); i++)
		{
			_coords[i] = *iterator++;
		}
		return true;
	}
	void operator=(const initializer_list<pair<float, float>>& rhs)
	{
		setVertex(rhs);
	}
	void moveTo(float offsetX, float offsetY) override
	{
		_x += offsetX;
		_y += offsetY;

		for (auto& [x, y] : _coords)
		{
			x += offsetX;
			y += offsetY;
		}
		return;
	}
};

/// <summary>
/// Simple rectangle
/// </summary>
class Rectangle : public DrawableShape<1>
{
public:
	Rectangle(GLfloat InitX = 0, GLfloat InitY = 0, GLfloat InitX2 = 0, GLfloat InitY2 = 0,
		float red = 0.f, float green = 0.f, float blue = 0.f,
		float scale = 0.f)
		: DrawableShape<1>(InitX, InitY, red, green, blue, scale)
	{
		_coords[0].first = InitX2;
		_coords[0].second = InitY2;
	};
	void draw(const glfwm::WindowID id) override;
};

class Circle : public DrawableShape<0>
{
protected:
	float _radius;
public:
	Circle(GLfloat InitX = 0, GLfloat InitY = 0, float radius = 0.f,
		float red = 0.f, float green = 0.f, float blue = 0.f,
		float scale = 0.f)
		: DrawableShape<0>(InitX, InitY, red, green, blue, scale),
		_radius(radius)
	{}
	void draw(const glfwm::WindowID id) override;
	void setRadius(float radius) { _radius = radius; }
};

class Ring : public Circle
{
protected:
	float _ringWidth;
public:
	Ring(GLfloat InitX = 0, GLfloat InitY = 0, float radius = 0.f, float ringwidth = 1.f,
		float red = 0.f, float green = 0.f, float blue = 0.f,
		float scale = 0.f)
		: Circle(InitX, InitY, radius, red, green, blue, scale),
		_ringWidth(ringwidth)
	{}
	void setRingWidth(float ringwidth) { _ringWidth = ringwidth; }
	void draw(const glfwm::WindowID id) override;
};