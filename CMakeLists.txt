cmake_minimum_required(VERSION 3.9)
project(opengl2)

set(CMAKE_CXX_STANDARD 11)


add_executable(opengl2 main.cpp)

target_link_libraries(opengl2 SDL2 GL GLEW)