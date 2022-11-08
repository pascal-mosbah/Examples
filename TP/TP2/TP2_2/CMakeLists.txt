cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(TP2_2)

# Source files

set(SRC
    TP2_2.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_executable(TP2_2 ${SRC})
