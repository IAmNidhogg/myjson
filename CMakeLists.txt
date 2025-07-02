cmake_minimum_required(VERSION 3.10)
project(myjson)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp) 
file(GLOB HPP ${PROJECT_SOURCE_DIR}/include/*.hpp)

add_library(json STATIC ${SRC} ${HPP}) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

link_directories(${PROJECT_SOURCE_DIR}/build/lib)

add_executable(demo ${PROJECT_SOURCE_DIR}/demo/main.cpp)

target_link_libraries(demo libjson.a)
