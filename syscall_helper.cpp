#include "syscall_helper.h"
#include "dependencies.h"

// Function to get the System Service Number (SSN) for a given function name
int getSyscallID(const char* funcName) {
    // Load the user32.dll library
    HMODULE user32 = LoadLibraryA("user32.dll");
    if (!user32) {
        std::cerr << "Failed to load user32.dll" << std::endl;
        return -1;
    }

    // Get the address of the function
    FARPROC funcAddress = GetProcAddress(user32, funcName);
    if (!funcAddress) {
        std::cerr << "Failed to get address of " << funcName << std::endl;
        FreeLibrary(user32);
        return -1;
    }

    // Convert the function address to SSN
    int ssn = reinterpret_cast<int>(funcAddress);

    // Free the library
    FreeLibrary(user32);

    return ssn;
}
