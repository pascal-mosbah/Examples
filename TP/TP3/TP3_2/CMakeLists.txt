cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(TP3_2)

# default all warnings
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Source files

set(SRC
    TP3_2.cpp
    main.cpp
)

add_executable(TP3_2 ${SRC})
