cmake_minimum_required(VERSION 3.13)
project(GardenApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(GardenApplication main.cpp Flowers.cpp Flowers.h Trees.cpp Trees.h Plants.cpp Plants.h Garden.cpp Garden.h)