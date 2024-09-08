cmake_minimum_required(VERSION 3.20)

project(main)

set(SOURCES main.cpp foo/foo.h)
set(SOURCE_LIB foo/foo.cpp)

add_library(foo STATIC ${SOURCE_LIB})

add_executable(main ${SOURCES} foo/foo.cpp)
target_link_libraries(main foo)
