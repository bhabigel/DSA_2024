cmake_minimum_required(VERSION 3.26)
project(lab_09 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_09 main.c
        binary_tree.c
        binary_tree.h
        ../lab-08/linked_list.c
        bst.c
        bst.h
        bst_person.c
        bst_person.h)
