cmake_minimum_required(VERSION 3.13)
project(FleetofThings)

set(CMAKE_CXX_STANDARD 14)

add_executable(FleetofThings main.cpp Fleet.cpp Fleet.h Thing.cpp Thing.h)