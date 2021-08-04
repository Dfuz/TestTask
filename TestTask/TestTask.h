#pragma once
#include <vector>
#include <array>
#include <list>
#include <GLFWM/glfwm.hpp>

using std::array;
using std::pair;
using std::list;

/// <summary>
/// Interface for abstract shape
/// </summary>
struct IShape
{
	virtual void setColor(float RED, float GREEN, float BLUE) = 0;
	virtual void moveTo(float X, float Y) const = 0;
	virtual void rotateShape(float angle) = 0;
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
	Location(int InitX = 0, int InitY = 0);
	~Location() {};
	int getX();
	int getY();
};

/// <summary>
/// Abstract-class:
/// 1. void draw(const glfwm::WindowID id) and
/// 2. void rotateShape(float Angle)
/// 3. void moveTo(float, float)
/// are pure virtual functions and must be implemented
/// </summary>
template<size_t VertexCount>
class DrawableShape : public Location, public IShape, public glfwm::Drawable
{
protected:
	GLfloat _red, _green, _blue;
	array<pair<float, float>, VertexCount> _coords;
	float _scale;
public:
	DrawableShape(int InitX = 0, int InitY = 0, 
		float red = 0.f, float green = 0.f, float blue = 0.f, 
		float scale = 0.f);
	~DrawableShape() {}
	void setColor(float RED, float GREEN, float BLUE) override;
	void setScale(double scale) override;
};


class Rectangle : public DrawableShape<1>
{
public:
	void draw(const glfwm::WindowID id) override;
	void rotateShape(float angle) override;
	void moveTo(float X, float Y) const override;
};

