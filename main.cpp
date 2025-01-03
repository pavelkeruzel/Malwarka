#include "dependencies.h"
#include "concrete_syscall_factory.h"
#include "syscall_helper.h"

// Function to perform a system call using the given factory and arguments
void performSyscall(const SyscallFactory& factory, int ssn, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    // Create a system call object using the factory
    Syscall* syscall = factory.createSyscall(ssn, arg1, arg2, arg3, arg4, arg5);
    
    // Execute the system call
    syscall->execute();
    
    // Delete the system call object
    delete syscall;
}

int main() {
    // Create a ConcreteSyscallFactory object
    ConcreteSyscallFactory factory;

    // Get the System Service Number (SSN) for the MessageBoxW function
    const char* funcName = "MessageBoxW";
    int ssn = getSyscallID(funcName);

    if (ssn != -1) {
        std::cout << "SSN for " << funcName << ": " << ssn << std::endl;

        // Define the arguments for the MessageBoxW function
        HWND hWnd = nullptr;  // Window handle
        LPCWSTR lpText = L"sosi hui virustotal!";  // Message text
        LPCWSTR lpCaption = L"Greetings";  // Message caption
        UINT uType = MB_OK;  // Message box type

        // Perform the system call using the factory and arguments
        performSyscall(factory, ssn, hWnd, (void*)lpText, (void*)lpCaption, (void*)uType, nullptr);
    } else {
        std::cerr << "Failed to get SSN for " << funcName << std::endl;
    }

    return 0;
}
