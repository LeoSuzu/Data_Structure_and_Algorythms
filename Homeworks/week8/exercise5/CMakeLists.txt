cmake_minimum_required(VERSION 3.27)
project(exercise5)

set(CMAKE_CXX_STANDARD 17)

add_executable(exercise5 main.cpp
        node.cpp
        node.h
        utility.h
        utility.cpp
        )
