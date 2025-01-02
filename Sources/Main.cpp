#include "../headers/defenitions.hpp"
#include "../headers/function_info.hpp"
#include "../headers/syscall.hpp"

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
        printf("Memory allocated successfully at %p\n", baseAddress);
    } else {
        printf("Memory allocation failed with status code: 0x%lX\n", status);
    }

    return 0;
}


