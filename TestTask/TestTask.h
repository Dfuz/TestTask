#pragma once

class IShape
{
	public: virtual bool fillColor(float RED, float GREEN, float BLUE) = 0;
	public:	virtual void setPosition(float X, float Y) const = 0;
	public:	virtual void rotateShape(float angle) = 0;
};

class IMovable
{

};

class Dot : public IShape
{

};


