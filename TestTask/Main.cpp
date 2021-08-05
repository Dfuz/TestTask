#include "TestTask.h"
#include "EventHandlers.h"

using glfwm::WindowManager;
using glfwm::Window;

int main(int argc, char* argv[])
{
    WindowManager::init();

    auto myHandler = std::make_shared<ResizeHandler>();
    myHandler->drawableShapes[KeyType::KEY_1] = std::make_shared<Ring>(400, 300, 40.f, 20.f, 0.f, 0.f, 1.f);
    myHandler->drawableShapes[KeyType::KEY_2] = std::make_shared<Rectangle>(450, 350, 350, 250, 1.f);
    myHandler->drawableShapes[KeyType::KEY_3] = std::make_shared<Circle>(400, 300, 40.f, 0.f, 1.f);
    myHandler->drawableShape = myHandler->drawableShapes[KeyType::KEY_1];

    auto mainWin = glfwm::WindowManager::createWindow(800, 600, std::string(), myHandler->getHandledEventTypes());
    mainWin->setTitle(std::string("Main Window ") + std::to_string(mainWin->getID()));

    // center window
    int mx = 0, my = 0;
    int wx = 0, wy = 0;
    mainWin->getSize(wx, wy);
    glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), nullptr, nullptr, &mx, &my);
    mainWin->setPosition((mx - wx) / 2, (my - wy) / 2);

    std::cout << "1 - draw Ring, 2 - draw Rectangle, 3 - Circle" << std::endl
        << "Arrows - move shape" << std::endl;

    // bind events and drawable objects
    mainWin->bindEventHandler(myHandler, 0);
    glfwm::WindowManager::mainLoop();
    glfwm::WindowManager::terminate();

    return 0;
}