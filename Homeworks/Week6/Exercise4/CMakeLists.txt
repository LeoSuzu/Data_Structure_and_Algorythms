cmake_minimum_required(VERSION 3.27)
project(Exercise4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise4
        extended_queue.cpp
        extended_queue.h
        main.cpp
        queue.cpp
        queue.h
        stack.cpp
        stack.h
        utility.cpp
        utility.h)
