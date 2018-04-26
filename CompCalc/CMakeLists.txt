cmake_minimum_required(VERSION 3.6)
project(CompCalc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
    complex.cc
    complex.h
    string-parse.cc
    string-parse.h
    main.cc)
add_executable(CompCalc ${SOURCE_FILES})