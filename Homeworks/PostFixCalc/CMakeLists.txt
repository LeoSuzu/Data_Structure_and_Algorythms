cmake_minimum_required(VERSION 3.27)
project(PostFixCalc)

set(CMAKE_CXX_STANDARD 17)

add_executable(PostFixCalc main.cpp
        Calc.cpp
        Calc.h
        NumStack.cpp
        NumStack.h)
