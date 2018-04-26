cmake_minimum_required(VERSION 3.6)
project(vectors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector.cpp Vector.h)
add_executable(vectors ${SOURCE_FILES} Vector.cpp Vector.h)