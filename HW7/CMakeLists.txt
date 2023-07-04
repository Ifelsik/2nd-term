cmake_minimum_required(VERSION 3.23)
project(HW7 C)

set(CMAKE_C_STANDARD 23)

add_executable(HW7 main.c src/students.c src/file.c src/mark_class.c src/attendance_class.c include/attendance_class.h)
