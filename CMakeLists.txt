cmake_minimum_required(VERSION 3.10)
project(Malware)

set(CMAKE_CXX_STANDARD 17)

# Specify the C++ compiler
set(CMAKE_CXX_COMPILER clang++)

# Compiler flags for Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O2")
endif()

# Collect source files
file(GLOB SOURCES "sources/*.cpp")
file(GLOB HEADERS "headers/*.hpp")

# Specify the assembler source files
set(ASM_SOURCES sources/syscalls.asm)

# Include directories for headers
include_directories(headers)
include_directories(sources)

# Enable NASM assembly language
enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_OBJECT_FORMAT win64)

# Add the executable
add_executable(Malware ${SOURCES} ${HEADERS} ${ASM_SOURCES})
