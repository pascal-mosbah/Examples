cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(Dog_and_cat)

# default all warnings
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Source files

set(SRC
    Dog_and_cat.cpp
    main.cpp
)

add_executable(Dog_and_cat ${SRC})
