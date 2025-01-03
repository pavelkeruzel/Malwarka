cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SyscallProject LANGUAGES C CXX ASM)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the compiler
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Add the executable
add_executable(SyscallProject
    main.cpp
    concrete_syscall.cpp
    syscall_helper.cpp
    syscall.asm
)

# Include directories
target_include_directories(SyscallProject PUBLIC "${PROJECT_SOURCE_DIR}")

# Link libraries (if necessary)
# target_link_libraries(SyscallProject <libraries>)
