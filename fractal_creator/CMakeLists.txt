cmake_minimum_required(VERSION 3.5)
project(fractal_creator)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
add_executable(
    main
    main.cpp
    Bitmap.cpp
    Bitmap.h
    BitmapFileHeader.h
    BitmapInfoHeader.h
    Mandelbrot.h
    Mandelbrot.cpp
    Zoom.h
    ZoomList.cpp
    FractalCreator.cpp
    RGB.cpp
)