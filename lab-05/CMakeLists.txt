cmake_minimum_required(VERSION 3.26)
project(lab_05 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_05 main.c
        stack.c
        stack.h
        queue.c
        queue.h)
