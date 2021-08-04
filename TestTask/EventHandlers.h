#pragma once
#include <GLFWM/glfwm.hpp>
#include <exception>
#include <iostream>
#include "TestTask.h"

using glfwm::EventType;

class ResizeHandler : public glfwm::EventHandler
{
public:
	glfwm::EventBaseType getHandledEventTypes() const override
	{
		return static_cast<glfwm::EventBaseType>(EventType::WINDOW_SIZE | EventType::FRAMEBUFFERSIZE);
	}
	bool handle(const glfwm::EventPointer& e) override
	{
		if (e->getEventType() == glfwm::EventType::WINDOW_SIZE)
		{
			auto castedEventPtr = std::dynamic_pointer_cast<glfwm::EventWindowSize>(e);
			auto window = glfwm::Window::getWindow(e->getWindowID());
			window->setTitle("Window has been resized");
			return true;
		}
		else if (e->getEventType() == glfwm::EventType::FRAMEBUFFERSIZE)
		{
			auto window = glfwm::Window::getWindow(e->getWindowID());			
			window->draw();
			window->swapBuffers();
			return true;
		}
	   else return false;
	}
};