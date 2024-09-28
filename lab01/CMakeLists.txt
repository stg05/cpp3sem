cmake_minimum_required(VERSION 3.20)

project(main)

set(SOURCES main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -Wall)

add_executable(main ${SOURCES})
