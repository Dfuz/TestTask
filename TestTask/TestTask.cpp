#include <iostream>
#include "TestTask.h"

class MyDrawable : public glfwm::Drawable {
public:
    void draw(const glfwm::WindowID id) override
    {
        std::cout << "Drawing window " << id << std::endl;
    }
};
std::shared_ptr<MyDrawable> myDrawable;

class MyHandler;
std::shared_ptr<MyHandler> myHandler;

class MyHandler : public glfwm::EventHandler {
public:
    glfwm::EventBaseType getHandledEventTypes() const override
    {
        return static_cast<glfwm::EventBaseType>(glfwm::EventType::MOUSE_BUTTON);
    }

    bool handle(const glfwm::EventPointer& e) override
    {
        if (e->getEventType() == glfwm::EventType::MOUSE_BUTTON) {

            std::shared_ptr<glfwm::EventMouseButton> mb = std::dynamic_pointer_cast<glfwm::EventMouseButton>(e);

            if (mb->getAction() != glfwm::ActionType::RELEASE)
                return false;

            glfwm::WindowPointer win = glfwm::Window::getWindow(e->getWindowID());
            int w, h, x, y;
            win->getSize(w, h);
            win->getPosition(x, y);

            if (mb->getMouseButton() == glfwm::MouseButtonType::MOUSE_BUTTON_LEFT) {
                glfwm::WindowPointer newWin = glfwm::WindowManager::createWindow(w * 0.9, h * 0.9, std::string(), getHandledEventTypes());
                newWin->setTitle(std::string("Window ") + std::to_string(newWin->getID()) + std::string(". Built from ") + std::to_string(e->getWindowID()));
                newWin->setPosition(x + w * 0.1, y + h * 0.1);
                newWin->bindEventHandler(myHandler, 0);
                newWin->bindDrawable(myDrawable, 0);
                glfwm::WindowGroupPointer grp = glfwm::WindowGroup::getGroup(glfwm::WindowGroup::getWindowGroup(e->getWindowID()));
                if (grp)
                    grp->attachWindow(newWin->getID());
                return true;
            }
            else if (mb->getMouseButton() == glfwm::MouseButtonType::MOUSE_BUTTON_RIGHT) {
                win->setShouldClose(true);
                return true;
            }
            return false;
        }

        return false;
    }
};



int main(int argc, char* argv[])
{
    glfwm::WindowManager::init();
    glfwm::WindowManager::setHint(GLFW_CLIENT_API, GLFW_NO_API);
    myHandler = std::make_shared<MyHandler>();
    myDrawable = std::make_shared<MyDrawable>();
    glfwm::WindowPointer mainWin = glfwm::WindowManager::createWindow(800, 600, std::string(), myHandler->getHandledEventTypes());
    mainWin->setTitle(std::string("Main Window ") + std::to_string(mainWin->getID()));
    mainWin->bindEventHandler(myHandler, 0);
    mainWin->bindDrawable(myDrawable, 0);
    glfwm::WindowGroupPointer grp = glfwm::WindowGroup::newGroup();
    grp->attachWindow(mainWin->getID());
    grp->runLoopConcurrently();
    glfwm::WindowManager::mainLoop();
    glfwm::WindowManager::terminate();

    return 0;
}