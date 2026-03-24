cmake_minimum_required(VERSION 3.21)
project(DecorGPT)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/decorator.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

find_package(Geode REQUIRED)
target_link_libraries(${PROJECT_NAME} Geode::Geode)
