#pragma once
#include "dependencies.hpp"

// Forward declaration of the FunctionInfo class
class FunctionInfo;

/**
 * @brief Resolves functions from dynamic libraries and stores their addresses.
 * 
 * This function iterates through a vector of FunctionInfo structures, loads the specified libraries,
 * retrieves the addresses of the specified functions, and stores these addresses in the FunctionInfo structures.
 *
 * @param functions A reference to a vector containing FunctionInfo structures.
 * @throw std::runtime_error if the library cannot be loaded or the function address cannot be retrieved.
 */
void resolveFunctions(std::vector<FunctionInfo>& functions);

/**
 * @brief Finds a FunctionInfo structure by its function name in a given vector.
 * 
 * This function iterates through a vector of FunctionInfo structures and searches
 * for a structure with the specified function name. If found, it returns a pointer
 * to the corresponding FunctionInfo structure. If not found, it returns nullptr.
 *
 * @param functions A reference to a vector containing FunctionInfo structures.
 * @param function_name The name of the function to search for.
 * @return FunctionInfo* A pointer to the found FunctionInfo structure, or nullptr if not found.
 */
FunctionInfo* findFunctionByName(std::vector<FunctionInfo>& functions, const std::string& function_name);

// Function defenition for syscall
extern "C" NTSTATUS NtAllocateVirtualMemory(
    HANDLE ProcessHandle,
    PVOID* BaseAddress,
    ULONG_PTR ZeroBits,
    PSIZE_T RegionSize,
    ULONG AllocationType,
    ULONG Protect
);

