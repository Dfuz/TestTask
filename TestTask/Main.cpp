#include "TestTask.h"
#include "EventHandlers.h"

using glfwm::WindowManager;
using glfwm::Window;

int main(int argc, char* argv[])
{
    WindowManager::init();

    auto myDrawable = std::make_shared<Rectangle>(200, 200);
    myDrawable->setVertex({ {20.f, 20.f} });
    myDrawable->setColor(1.f, 0.f, 0.f);

    auto myHandler = std::make_shared<ResizeHandler>();
    myHandler->drawableShape = myDrawable;
    auto mainWin = glfwm::WindowManager::createWindow(800, 600, std::string(), myHandler->getHandledEventTypes());
    mainWin->setTitle(std::string("Main Window ") + std::to_string(mainWin->getID()));

    // center window
    int mx = 0, my = 0;
    int wx = 0, wy = 0;
    mainWin->getSize(wx, wy);
    glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), nullptr, nullptr, &mx, &my);
    mainWin->setPosition((mx - wx) / 2, (my - wy) / 2);

    // bind events and drawable objects
    mainWin->bindEventHandler(myHandler, 0);
    mainWin->bindDrawable(myDrawable, 0);
    glfwm::WindowManager::mainLoop();
    glfwm::WindowManager::terminate();

    return 0;
}