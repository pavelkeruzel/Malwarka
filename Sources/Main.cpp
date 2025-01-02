#include "../headers/defenitions.hpp"
#include "../headers/function_info.hpp"
#include "../headers/syscall.h"

int main() {
    HANDLE hProcess = GetCurrentProcess();
    PVOID baseAddress = nullptr;
    SIZE_T regionSize = 1024 * 1024; // 1 MB
    NTSTATUS status;

    // Allocate memory with proper flags
    status = NtAllocateVirtualMemory(
        hProcess,
        &baseAddress,
        0,
        &regionSize,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_READWRITE
    );

    if (status == 0) {
        std::cout << "Memory allocated successfully at " << baseAddress << std::endl;
    } else {
        std::cout << "Memory allocation failed with status code: 0x" << std::hex << status << std::endl;
        return 1;
    }

    // Ensure that the base address is valid and properly aligned
    if ((reinterpret_cast<uintptr_t>(baseAddress) & (4096 - 1)) != 0) {
        std::cerr << "Base address is not page-aligned: " << baseAddress << std::endl;
    }

    // Reinitialize the size and address for freeing memory
    PVOID freeAddress = baseAddress;
    SIZE_T freeSize = regionSize;

    // Use VirtualQuery to check memory properties before freeing
    MEMORY_BASIC_INFORMATION mbi;
    SIZE_T queryResult = VirtualQuery(baseAddress, &mbi, sizeof(mbi));
    if (queryResult == 0) {
        std::cerr << "VirtualQuery failed with error: " << GetLastError() << std::endl;
    } else {
        std::cout << "Region state: " << mbi.State << std::endl;
        std::cout << "Region protect: " << mbi.Protect << std::endl;
        std::cout << "Region type: " << mbi.Type << std::endl;
    }

    // Free the allocated memory with MEM_DECOMMIT
    status = NtFreeVirtualMemory(
        hProcess,
        &freeAddress,
        &freeSize,
        MEM_DECOMMIT
    );

    if (status == 0) {
        std::cout << "Memory decommitted successfully." << std::endl;

        // Now release the memory
        status = NtFreeVirtualMemory(
            hProcess,
            &freeAddress,
            &freeSize,
            MEM_RELEASE
        );

        if (status == 0) {
            std::cout << "Memory released successfully." << std::endl;
        } else {
            std::cout << "Memory release failed with status code: 0x" << std::hex << status << std::endl;
        }
    } else {
        std::cout << "Memory decommit failed with status code: 0x" << std::hex << status << std::endl;
        // Additional debugging information
        std::cerr << "Base address: " << baseAddress << std::endl;
        std::cerr << "Region size: " << regionSize << std::endl;
        std::cerr << "Free address: " << freeAddress << std::endl;
        std::cerr << "Free size: " << freeSize << std::endl;
    }

    // Show a message box using the indirect syscall
    int messageBoxResult = MessageBoxW(
        NULL,
        L"hui sosi pidoras",
        L"Indirect Syscall MessageBoxW",
        MB_OK
    );

    if (messageBoxResult == IDOK) {
        std::cout << "MessageBoxW displayed successfully." << std::endl;
    } else {
        std::cout << "MessageBoxW failed." << std::endl;
    }

    return 0;
}

