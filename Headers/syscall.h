#ifndef SYSCALL_H
#define SYSCALL_H   // Ensures the header file is only included once during compilation

#include <Windows.h>    // Include necessary Windows headers for Windows API functions
#include <winnt.h>      // Include definitions for MEMORY_INFORMATION_CLASS and other NT-specific definitions

// Declaration of an external C function named NtAllocateVirtualMemory
// This function allocates virtual memory in the address space of a specified process.
extern "C" NTSTATUS NtAllocateVirtualMemory(
    HANDLE ProcessHandle,    // Handle to the process in which to allocate memory
    PVOID* BaseAddress,      // Pointer to a variable that will receive the base address of the allocated region
    ULONG_PTR ZeroBits,      // Number of high-order address bits that must be zero (usually set to 0)
    PSIZE_T RegionSize,      // Pointer to the size of the region to allocate
    ULONG AllocationType,    // Type of memory allocation (e.g., MEM_COMMIT | MEM_RESERVE)
    ULONG Protect            // Memory protection for the region (e.g., PAGE_READWRITE)
);

// Declaration of an external C function named NtFreeVirtualMemory
// This function frees virtual memory in the address space of a specified process.
extern "C" NTSTATUS NtFreeVirtualMemory(
    HANDLE ProcessHandle,    // Handle to the process in which to free memory
    PVOID* BaseAddress,      // Pointer to the base address of the region to free
    PSIZE_T RegionSize,      // Pointer to the size of the region to free
    ULONG FreeType           // Type of memory release (e.g., MEM_RELEASE)
);

// Declaration of an external C function named NtProtectVirtualMemory
// This function changes the protection on a region of committed pages in the virtual address space of a specified process.
extern "C" NTSTATUS NtProtectVirtualMemory(
    HANDLE ProcessHandle,    // Handle to the process in which to change protection
    PVOID* BaseAddress,      // Pointer to the base address of the region to protect
    PSIZE_T RegionSize,      // Pointer to the size of the region to protect
    ULONG NewProtect,        // New protection for the region (e.g., PAGE_READWRITE)
    PULONG OldProtect        // Pointer to a variable that receives the old protection
);

// Removing the declaration of MessageBoxW to avoid redeclaration warning

#endif // SYSCALL_H
