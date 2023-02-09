cmake_minimum_required(VERSION 3.23)
project(aocpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        aocpp
        src/main.cpp
        src/include/utils.h
        src/include/d01.h
        src/d01.cpp src/include/d01.h src/utils.cpp)
