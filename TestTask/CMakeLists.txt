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

target_link_libraries(TestTask glfw OpenGL::GL)
# TODO: Add tests and install targets if needed.
