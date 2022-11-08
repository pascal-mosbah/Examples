cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(pointer_to_pointer_allocation)

# Source files

set(SRC
    pointer_to_pointer_allocation.c
)

add_executable(pointer_to_pointer_allocation ${SRC})
