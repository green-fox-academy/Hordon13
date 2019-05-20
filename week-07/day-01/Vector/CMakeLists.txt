cmake_minimum_required(VERSION 3.13)
project(Vector C)

set(CMAKE_C_STANDARD 11)

add_executable(Vector main.c src/vector.c src/vector.h test/test_vector.c vendor/ceedling/vendor/unity/src/unity.c)