cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(TP2_1)

# Source files

set(SRC
    TP2_1.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_executable(TP2_1 ${SRC})
