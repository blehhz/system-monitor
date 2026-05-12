cmake_minimum_required(VERSION 3.16)

project(sysfetch)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(sysfetch
    src/main.cpp
    src/system.cpp
    src/cpu.cpp
    src/memory.cpp
    src/disk.cpp
    src/monitor.cpp
    src/jsonBuilder.cpp
    src/api.cpp
)

target_include_directories(sysfetch PRIVATE
    include
)

target_compile_options(sysfetch PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)