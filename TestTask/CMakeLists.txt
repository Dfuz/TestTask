# CMakeList.txt : CMake project for TestTask, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# отключаем сборку тестов и документации
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
find_package(OpenGL REQUIRED)

# Add source to this project's executable.
add_executable (TestTask "TestTask.cpp" "TestTask.h")

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON)

target_link_libraries(TestTask glfwm OpenGL::GL)
# TODO: Add tests and install targets if needed.
