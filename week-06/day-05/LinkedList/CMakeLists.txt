cmake_minimum_required(VERSION 3.13)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedList main.c src/list.c src/list.h test/test_list.c vendor/ceedling/vendor/unity/src/unity.c)