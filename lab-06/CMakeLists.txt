cmake_minimum_required(VERSION 3.26)
project(lab_06 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_06 main.c
        patient.c
        patient.h
        queue.c
        queue.h)
