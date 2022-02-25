cmake_minimum_required(VERSION 3.21)
project(taskOne)

set(CMAKE_CXX_STANDARD 14)

add_executable(taskOne main.cpp GameComponent.cpp GameComponent.h Game.cpp Game.h DrawableGameComponent.cpp DrawableGameComponent.h)
