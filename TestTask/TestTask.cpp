#include <iostream>
#include "TestTask.h"
#include "EventHandlers.h"

class MyDrawable : public glfwm::Drawable {
public:
    void draw(const glfwm::WindowID id) override
    {
        std::cout << "Drawing window " << id << std::endl;
    }
};

int main(int argc, char* argv[])
{
    glfwm::WindowManager::init();
    auto myDrawable = std::make_shared<Dot>();
    auto myHandler = std::make_shared<ResizeHandler>();
    auto mainWin = glfwm::WindowManager::createWindow(800, 600, std::string(), myHandler->getHandledEventTypes());
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