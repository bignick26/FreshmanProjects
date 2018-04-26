cmake_minimum_required(VERSION 3.6)
project(Vector3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Vector.cc
    Vector.h
    main.cpp)
add_executable(Vector3 ${SOURCE_FILES})