cmake_minimum_required(VERSION 3.27)
project(Exercise1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise1
        Extended_queue.cpp
        Extended_queue.h
        main.cpp
        Queue.cpp
        Queue.h
        Utility.cpp
        Utility.h)
