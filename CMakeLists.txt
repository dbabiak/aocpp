cmake_minimum_required(VERSION 3.23)
project(aocpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        aocpp
        main.cpp
        utils.h
        d01.h
        d02.h
        d03.h
        demos.h)
