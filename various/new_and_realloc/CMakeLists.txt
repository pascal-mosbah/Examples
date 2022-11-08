cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(new_and_realloc)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-pg -Wall -Wextra -pedantic)
#    add_link_options(-pg)
endif()

# Source files

set(SRC
    new_and_realloc.cpp
)

add_executable(new_and_realloc ${SRC})
