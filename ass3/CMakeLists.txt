cmake_minimum_required(VERSION 3.26)
project(ass3 C)

set(CMAKE_C_STANDARD 99)

add_executable(ass3
        avlTree.c
        avlTree.h main.c
        newAVLTree.c)
