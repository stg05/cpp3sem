cmake_minimum_required(VERSION 3.20)

project(task1 VERSION 1.0 LANGUAGES C)

set(CMAKE_C_COMPILER "C:\\Program Files (x86)\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\bin\\gcc.exe")
set(SOURCES main.c tetris.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_executable(task2 ${SOURCES})