cmake_minimum_required(VERSION 3.9)
project(opengl2)

set(CMAKE_CXX_STANDARD 11)


add_executable(opengl2 src/main.cpp src/Display.cpp src/Display.h)

target_link_libraries(opengl2 SDL2 GL GLEW)