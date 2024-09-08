cmake_minimum_required(VERSION 3.20)

project(foo)

set(SOURCE_LIB foo.cpp)

add_library(foo STATIC ${SOURCE_LIB})