#ifndef FUNCTION_INFO_H
#define FUNCTION_INFO_H

#include "dependencies.hpp" // Include necessary dependencies

class FunctionInfo {
public:
    // Constructor initializes function name and library name
    FunctionInfo(const std::string& func_name, const std::string& lib_name)
        : function_name(func_name), library_name(lib_name), function_address(nullptr), function_pointer(nullptr) {}

    // Getter for function name
    std::string getFunctionName() const { return function_name; }

    // Getter for library name
    std::string getLibraryName() const { return library_name; }

    // Getter for function address
    FARPROC getFunctionAddress() const { return function_address; }

    // Getter for function pointer
    void* getFunctionPointer() const { return function_pointer; }

    // Setter for function name
    void setFunctionName(const std::string& name) { function_name = name; }

    // Setter for library name
    void setLibraryName(const std::string& name) { library_name = name; }

    // Setter for function address
    void setFunctionAddress(FARPROC address) { function_address = address; }

    // Setter for function pointer
    void setFunctionPointer(void* pointer) { function_pointer = pointer; }
    
    // Default copy constructor
    FunctionInfo(const FunctionInfo& other) = default;

    // Default assignment operator
    FunctionInfo& operator=(const FunctionInfo& other) = default;

    // Equality operator to compare two FunctionInfo objects
    bool operator==(const FunctionInfo& other) const {
        return function_name == other.function_name &&
               library_name == other.library_name &&
               function_address == other.function_address;
    }

    // Inequality operator to compare two FunctionInfo objects
    bool operator!=(const FunctionInfo& other) const {
        return !(*this == other);
    }

private:
    std::string function_name;    // Name of the function
    std::string library_name;     // Name of the library where the function is located
    FARPROC function_address;     // Address of the function
    void* function_pointer;       // Pointer to the function
};

#endif // FUNCTION_INFO_H
