
cmake_minimum_required(VERSION 3.20)
# ^ Minimal of version of CMake you need to begin the build

# set(CMAKE_CXX_COMPILER g++)
# ^ Variable of path to C++ compiler
project(MyMath)

set(SOURCES src/ans_handler.cpp src/my_math.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
# ^ Directory where store build of project
set(EXECUTABLE_OUTPUT_PATH ../bin)

include_directories(./include)
# ^ Directory with headers to be included (like -I option of compiler)

add_executable(MyMath main.cpp ${SOURCES})
# ^ Create executable with sources