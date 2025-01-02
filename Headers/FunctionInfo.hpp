#pragma once
#include "Dependencies.hpp"

class FunctionInfo {
public:
    FunctionInfo(const std::string& func_name, const std::string& lib_name)
        : function_name(func_name), library_name(lib_name), function_address(nullptr), function_pointer(nullptr) {}

    std::string getFunctionName() const { return function_name; }
    std::string getLibraryName() const { return library_name; }
    FARPROC getFunctionAddress() const { return function_address; }
    void* getFunctionPointer() const { return function_pointer; }

    void setFunctionName(const std::string& name) { function_name = name; }
    void setLibraryName(const std::string& name) { library_name = name; }
    void setFunctionAddress(FARPROC address) { function_address = address; }
    void setFunctionPointer(void* pointer) { function_pointer = pointer; }
    
    FunctionInfo(const FunctionInfo& other) = default;

    FunctionInfo& operator=(const FunctionInfo& other) = default;

    bool operator==(const FunctionInfo& other) const {
        return function_name == other.function_name &&
               library_name == other.library_name &&
               function_address == other.function_address;
    }

    bool operator!=(const FunctionInfo& other) const {
        return !(*this == other);
    }

private:
    std::string function_name;
    std::string library_name;
    FARPROC function_address;
    void* function_pointer;
};