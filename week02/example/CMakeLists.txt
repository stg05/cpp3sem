cmake_minimum_required(VERSION 3.20)

project(main)

set(SOURCES main.cpp ../raytracer/main.cpp)

add_executable(main ${SOURCES})
