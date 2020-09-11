cmake_minimum_required(VERSION 3.17)
project(SingleWindowLibrary)

set(CMAKE_CXX_STANDARD 14)

include_directories(SingleWindowLibrary/Headers SingleWindowLibrary/Dependencies)
link_directories(SingleWindowLibrary/DependencyLibs)

add_executable(SingleWindowLibrary
        SingleWindowLibrary/core.cpp
        main.cpp)

target_link_libraries(SingleWindowLibrary SDL2 SDL2main)
