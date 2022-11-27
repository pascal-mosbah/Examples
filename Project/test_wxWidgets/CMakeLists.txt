cmake_minimum_required(VERSION 3.18)
project(myapp)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                  $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                  )
    set(Boost_USE_STATIC_RUNTIME ON)
    set(Boost_DIR "C:/tools/Boost/lib/cmake/Boost-1.80.0")
    set(wxWidgets_ROOT_DIR  "C:/tools/wxWidgets")
    set(CMAKE_PREFIX_PATH  C:/tools/wxWidgets)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                      $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                      )
elseif(MSVC)
    set(Boost_DIR /usr/local/lib/cmake/Boost-1.80.0)
endif (MSVC)

find_package(Boost 1.80.0 COMPONENTS json serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(myapp myapp.cpp)
add_executable(example_of_use example_of_use.cpp My_new_Customer_dialog.cpp)

if(MSVC)
    set_target_properties(myapp PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
    set_property(TARGET myapp PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set_target_properties(example_of_use PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
    set_property(TARGET example_of_use PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif (MSVC)

target_link_libraries(myapp LINK_PUBLIC customer ${wxWidgets_LIBRARIES})
target_link_libraries(example_of_use LINK_PUBLIC customer ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})

