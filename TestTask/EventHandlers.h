#pragma once
#include <GLFWM/glfwm.hpp>
#include <exception>
#include <iostream>
#include <map>

#include "TestTask.h"

using glfwm::EventType;
using glfwm::KeyType;

class ResizeHandler : public glfwm::EventHandler
{
private:
	inline void changeShape(const KeyType& key, const glfwm::EventPointer& e)
	{
		if (drawableShapes.find(key) == end(drawableShapes))
			return;
		else
		{
			auto window = glfwm::Window::getWindow(e->getWindowID());
			window->unbindDrawable(drawableShape);
			drawableShape = drawableShapes.at(key);
			window->bindDrawable(drawableShape, 0);
		}
	}
public:
	std::map<KeyType, std::shared_ptr<glfwm::Drawable>> drawableShapes;
	std::shared_ptr<glfwm::Drawable> drawableShape;
	glfwm::EventBaseType getHandledEventTypes() const override
	{
		return static_cast<glfwm::EventBaseType>(EventType::WINDOW_SIZE | EventType::KEY);
	}
	bool handle(const glfwm::EventPointer& e) override
	{
		if (e->getEventType() == glfwm::EventType::WINDOW_SIZE)
		{
			auto castedEventPtr = std::dynamic_pointer_cast<glfwm::EventWindowSize>(e);
			auto window = glfwm::Window::getWindow(e->getWindowID());
			window->setTitle("Window has been resized");
			window->draw();
			window->swapBuffers();
			return true;
		}
		else if (e->getEventType() == glfwm::EventType::KEY)
		{
			if (drawableShape)
			{
				auto castedEventPtr = std::dynamic_pointer_cast<glfwm::EventKey>(e);
				auto castedShapePtr = std::dynamic_pointer_cast<IShape>(drawableShape);
				switch (castedEventPtr->getKey())
				{
				case KeyType::KEY_RIGHT:
					castedShapePtr->moveTo(2, 0);
					break;
				case KeyType::KEY_UP:
					castedShapePtr->moveTo(0, 2);
					break;
				case KeyType::KEY_DOWN:
					castedShapePtr->moveTo(0, -2);
					break;
				case KeyType::KEY_LEFT:
					castedShapePtr->moveTo(-2, 0);
					break;
				// switching drawable objects
				case KeyType::KEY_1:
					changeShape(KeyType::KEY_1, e);
					break;
				case KeyType::KEY_2:
					changeShape(KeyType::KEY_2, e);
					break;
				case KeyType::KEY_3:
					changeShape(KeyType::KEY_3, e);
					break;
				default:
					return false;
				}
				return true;
			}
		}
		return false;
	}
};