cmake_minimum_required(VERSION 3.13)
project(Flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flyable main.cpp Flyable.h Vehicle.h Animals.h Bird.cpp Bird.h Helicopter.cpp Helicopter.h)