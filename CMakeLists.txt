cmake_minimum_required(VERSION 3.23)
project(aocpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        aocpp
        src/main.cpp
        src/utils.h
        src/d01.h
        src/d02.h
        src/d03.h
        src/demos.h)
