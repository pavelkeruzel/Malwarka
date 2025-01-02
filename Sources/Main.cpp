#include "../headers/defenitions.hpp"
#include "../headers/function_info.hpp"
#include "../headers/syscall.h"

int main() {
    HANDLE hProcess = GetCurrentProcess();
    PVOID baseAddress = nullptr;
    SIZE_T regionSize = 1024 * 1024; // 1 MB
    NTSTATUS status = NtAllocateVirtualMemory(
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
    }

    // Free the allocated memory
    status = NtFreeVirtualMemory(
        hProcess,
        &baseAddress,
        &regionSize,
        MEM_RELEASE
    );

    if (status == 0) {
        std::cout << "Memory freed successfully." << std::endl;
    } else {
        std::cout << "Memory free failed with status code: 0x" << std::hex << status << std::endl;
    }

    return 0;
}



