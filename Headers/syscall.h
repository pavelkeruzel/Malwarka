#pragma once   // Ensures the header file is only included once during compilation

#include "dependencies.hpp"   // Includes the header file "dependencies.hpp", which contains necessary dependencies

extern "C" NTSTATUS NtAllocateVirtualMemory(  // Declares an external C function named NtAllocateVirtualMemory
    HANDLE ProcessHandle,    // Handle to the process in which to allocate memory
    PVOID* BaseAddress,      // Pointer to a variable that will receive the base address of the allocated region
    ULONG_PTR ZeroBits,      // Zero bits (usually set to 0)
    PSIZE_T RegionSize,      // Pointer to the size of the region to allocate
    ULONG AllocationType,    // Type of memory allocation (e.g., MEM_COMMIT | MEM_RESERVE)
    ULONG Protect            // Memory protection for the region (e.g., PAGE_READWRITE)
);
