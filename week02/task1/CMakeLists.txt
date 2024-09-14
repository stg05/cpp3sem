cmake_minimum_required(VERSION 3.20)

project(main)

set(SOURCES main.cpp src/utils.cpp src/vec3.cpp src/transformations.cpp include/transformations.h include/params.h)
set(CMAKE_CXX_STANDARD 20)

add_executable(main ${SOURCES})
