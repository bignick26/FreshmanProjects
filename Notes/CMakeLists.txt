cmake_minimum_required(VERSION 3.6)
project(Notes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Dog.cpp Dog.cpp Dog.h)
add_executable(Notes ${SOURCE_FILES})