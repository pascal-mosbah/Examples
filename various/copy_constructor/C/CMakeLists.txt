cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(copy_constructor)

# Source files

set(SRC
    src/copy_constructor.c
    src/main.c
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_executable(copy_constructor ${SRC})
