cmake_minimum_required(VERSION 3.23)
project(Task_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(Task_2 main.c src/tools.c include/main.h include/tools.h)
