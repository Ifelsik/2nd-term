cmake_minimum_required(VERSION 3.23)
project(RK_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(RK_2 main.c cJSON/cJSON.h cJSON/cJSON.c src/file.c include/file.h src/stack.c include/stack.h src/student.c include/student.h include/main.h)
