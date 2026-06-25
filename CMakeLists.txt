cmake_minimum_required(VERSION 3.16)

project(system-monitor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(system-monitor
    src/main.cpp
    
    src/api/jsonBuilder.cpp
    src/api/api.cpp
    
    src/modules/cpu/cpu.cpp
    src/modules/cpu/cpuService.cpp
    
    src/modules/memory/memory.cpp
    src/modules/memory/memoryService.cpp
    
    src/modules/disk/disk.cpp
    src/modules/disk/diskService.cpp
    
    src/modules/system/system.cpp
    src/modules/system/systemService.cpp
    
)

target_include_directories(system-monitor PRIVATE
    include
)

target_compile_options(system-monitor PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)