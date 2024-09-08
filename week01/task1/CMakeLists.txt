cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/g++.exe")
project(task1 VERSION 1.0 LANGUAGES CXX)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set(SOURCES main.cpp ../task3/include/ans_handler.h ../task3/include/my_math.h ../task3/src/ans_handler.cpp ../task3/src/my_math.cpp ../task3/main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(task1 ${SOURCES})