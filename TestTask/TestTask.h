#pragma once

struct IShape
{
	virtual bool fillColor(float RED, float GREEN, float BLUE) = 0;
	virtual void setPosition(float X, float Y) const = 0;
	virtual void rotateShape(float angle) = 0;
	virtual void setScale(double scale) = 0;
};

struct IMovable
{
	virtual void setSpeed(double rotateSpeed) = 0;
};

class Dot : public IShape, public IMovable
{

};


