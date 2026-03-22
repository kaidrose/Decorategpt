cmake_minimum_required(VERSION 3.10)
project(KaidenMod)

set(CMAKE_CXX_STANDARD 17)

# Add Geode SDK path
include_directories(geode/include)
link_directories(geode/build)

add_library(KaidenMod SHARED
    src/main.cpp
    src/decorator.cpp
)

target_link_libraries(KaidenMod geode)
