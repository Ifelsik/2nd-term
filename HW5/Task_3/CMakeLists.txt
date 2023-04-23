cmake_minimum_required(VERSION 3.23)
project(Task_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Task_3 main.c src/db_utils.c include/db_utils.h src/file_utils.c include/file_utils.h sha256/sha-256.c sha256/sha-256.h)
