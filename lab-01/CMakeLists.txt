cmake_minimum_required(VERSION 3.26)
project(lab_01 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab-01 main.c
        function.c
        function.h)