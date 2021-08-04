#pragma once
#include <GLFWM/glfwm.hpp>
#include <exception>
#include <iostream>

#include "TestTask.h"

using glfwm::EventType;
using glfwm::KeyType;

class ResizeHandler : public glfwm::EventHandler
{
public:
	std::shared_ptr<IShape> drawableShape;
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

				switch (castedEventPtr->getKey())
				{
				case KeyType::KEY_RIGHT:
					drawableShape->moveTo(2, 0);
					break;
				case KeyType::KEY_UP:
					drawableShape->moveTo(0, 2);
					break;
				case KeyType::KEY_DOWN:
					drawableShape->moveTo(0, -2);
					break;
				case KeyType::KEY_LEFT:
					drawableShape->moveTo(-2, 0);
					break;
				}
				return true;
			}
			return false;
		}
		else return false;
	}
};