cmake_minimum_required(VERSION 3.5)
project(rvalue_references)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
add_executable(
    main
    main.cpp
)