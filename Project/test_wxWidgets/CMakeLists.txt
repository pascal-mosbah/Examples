cmake_minimum_required(VERSION 3.18)
project(myapp)

if(MSVC)
    set(wxWidgets_ROOT_DIR  "C:/tools/wxWidgets")
    set(CMAKE_PREFIX_PATH  C:/tools/wxWidgets)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                      $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                      )
endif (MSVC)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(myapp myapp.cpp)

if(MSVC)
    set_target_properties(myapp PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
    set_property(TARGET myapp PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif (MSVC)

target_link_libraries(myapp ${wxWidgets_LIBRARIES})


