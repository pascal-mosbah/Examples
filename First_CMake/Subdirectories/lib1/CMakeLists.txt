cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(lib1)

# Source files

set(SRC
    src/file.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_library(lib1 STATIC ${SRC})
