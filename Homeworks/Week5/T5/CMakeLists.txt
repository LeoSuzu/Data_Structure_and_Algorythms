cmake_minimum_required(VERSION 3.27)
project(T5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(T5
        Extended_stack.cpp
        Extended_stack.h
        T5.cpp
        Utility.h)
