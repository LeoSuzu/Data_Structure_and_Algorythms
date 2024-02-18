cmake_minimum_required(VERSION 3.27)
project(exercise1)

set(CMAKE_CXX_STANDARD 17)

add_executable(exercise1 main.cpp
        node.cpp
        node.h
        utility.h
        utility.cpp
        )
