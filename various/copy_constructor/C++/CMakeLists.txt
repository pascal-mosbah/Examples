cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(copy_constructor_C++)

# Source files

set(SRC
    src/copy_constructor.cpp
    src/main.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_executable(copy_constructor_C++ ${SRC})
