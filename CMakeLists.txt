cmake_minimum_required(VERSION 3.10)
project(Malware)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_COMPILER clang++)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O2")
endif()

file(GLOB SOURCES "sources/*.cpp")
file(GLOB HEADERS "headers/*.hpp")

set(ASM_SOURCES sources/syscall.asm)

include_directories(headers)   
include_directories(sources)   

enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_OBJECT_FORMAT win64)

add_executable(Malware ${SOURCES} ${HEADERS} ${ASM_SOURCES})
