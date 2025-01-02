#ifndef SYSCALL_H
#define SYSCALL_H

#include "dependencies.hpp" // Include necessary dependencies

extern "C" NTSTATUS NtAllocateVirtualMemory(
    HANDLE ProcessHandle,    // Handle to the process in which to allocate memory
    PVOID* BaseAddress,      // Pointer to a variable that will receive the base address of the allocated region
    ULONG_PTR ZeroBits,      // Zero bits (usually set to 0)
    PSIZE_T RegionSize,      // Pointer to the size of the region to allocate
    ULONG AllocationType,    // Type of memory allocation (e.g., MEM_COMMIT | MEM_RESERVE)
    ULONG Protect            // Memory protection for the region (e.g., PAGE_READWRITE)
);

extern "C" NTSTATUS NtFreeVirtualMemory(
    HANDLE ProcessHandle,    // Handle to the process in which to free memory
    PVOID* BaseAddress,      // Pointer to the base address of the region to free
    PSIZE_T RegionSize,      // Pointer to the size of the region to free
    ULONG FreeType           // Type of memory release (e.g., MEM_RELEASE)
);

extern "C" NTSTATUS NtProtectVirtualMemory(
    HANDLE ProcessHandle,    // Handle to the process in which to change protection
    PVOID* BaseAddress,      // Pointer to the base address of the region to protect
    PSIZE_T RegionSize,      // Pointer to the size of the region to protect
    ULONG NewProtect,        // New protection for the region (e.g., PAGE_READWRITE)
    PULONG OldProtect        // Pointer to a variable that receives the old protection
);

#endif // SYSCALL_H
