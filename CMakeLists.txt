cmake_minimum_required(VERSION 3.22)
project(SYSC3303_Assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SYSC3303_Assignment_3
        main.cpp
        State.cpp
        State.h
        Context.h
 )
