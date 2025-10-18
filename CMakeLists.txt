cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(untitled main.cpp appicon.rc)

set_target_properties(untitled PROPERTIES OUTPUT_NAME "SlopeFind++")

if(MINGW)
    target_link_options(untitled PRIVATE -static -static-libgcc -static-libstdc++)
endif ()
