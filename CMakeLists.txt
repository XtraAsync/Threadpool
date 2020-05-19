# CMake entry point
cmake_minimum_required (VERSION 3.12)
project(thread-pool)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS "src/*.cpp")

# main.cpp
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
