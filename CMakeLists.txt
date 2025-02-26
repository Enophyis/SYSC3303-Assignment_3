cmake_minimum_required(VERSION 3.30)
project(SYSC3303_Assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SYSC3303_Assignment_3
    main.cpp
    PedestriansEnabled.cpp
    PedestriansEnabled.h
    PedestriansFlash.cpp
    PedestriansFlash.h
    PedestriansWalk.cpp
    PedestriansWalk.h
        State.h
    VehiclesEnabled.cpp
    VehiclesEnabled.h
    VehiclesGreen.cpp
    VehiclesGreen.h
    VehiclesGreenInt.cpp
    VehiclesGreenInt.h
    VehiclesYellow.cpp
    VehiclesYellow.h)
