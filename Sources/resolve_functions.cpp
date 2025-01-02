#include "../headers/function_info.hpp"

/**
 * @brief Resolves functions from dynamic libraries and stores their addresses.
 *
 * This function iterates through a vector of FunctionInfo structures, loads the specified libraries,
 * retrieves the addresses of the specified functions, and stores these addresses in the FunctionInfo structures.
 *
 * @param functions A reference to a vector containing FunctionInfo structures.
 * @throw std::runtime_error if the library cannot be loaded or the function address cannot be retrieved.
 */
void resolveFunctions(std::vector<FunctionInfo>& functions) {
    for (auto& functionInfo : functions) {
        HMODULE hModule = LoadLibraryA(functionInfo.getLibraryName().c_str());
        if (!hModule) {
            std::cerr << "Failed to load library: " << functionInfo.getLibraryName() << std::endl;
            throw std::runtime_error("Failed to load library: " + functionInfo.getLibraryName());
        }

        FARPROC functionAddress = GetProcAddress(hModule, functionInfo.getFunctionName().c_str());
        if (!functionAddress) {
            std::cerr << "Failed to get function address: " << functionInfo.getFunctionName() << " from library: " << functionInfo.getLibraryName() << std::endl;
            FreeLibrary(hModule);
            throw std::runtime_error("Failed to get function address: " + functionInfo.getFunctionName());
        }

        functionInfo.setFunctionAddress(functionAddress);
        functionInfo.setFunctionPointer(reinterpret_cast<void*>(functionAddress));

        FreeLibrary(hModule);
    }
}
