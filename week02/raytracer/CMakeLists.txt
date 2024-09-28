cmake_minimum_required(VERSION 3.20)

project(main)

set(SOURCES main.cpp src/utils.cpp src/vec3.cpp src/transformations.cpp src/ray.cpp src/viewport.cpp include/viewport.h src/scene.cpp include/scene.h include/color.h src/color.cpp)
set(CMAKE_CXX_STANDARD 20)

add_executable(main ${SOURCES})
