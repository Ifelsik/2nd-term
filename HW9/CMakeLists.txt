cmake_minimum_required(VERSION 3.23)
project(HW9 C)

set(CMAKE_C_STANDARD 23)

add_executable(HW9 main.c src/stack.c include/stack.h src/data_parser.c include/data_parser.h main.h)
