cmake_minimum_required(VERSION 3.13)
project(AnimalsInTheZoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnimalsInTheZoo main.cpp Animals.h Reptile.cpp Reptile.h Birds.cpp Birds.h Mammal.cpp Mammal.h)