cmake_minimum_required(VERSION 3.5)

project(lvalue_references)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(
    main
    main.cpp
)