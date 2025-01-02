#include "../headers/Defenitions.hpp"
#include "../headers/FunctionInfo.hpp"

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
FunctionInfo* findFunctionByName(std::vector<FunctionInfo>& functions, const std::string& function_name) {
    auto it = std::find_if(functions.begin(), functions.end(), [&function_name](const FunctionInfo& func) {
        return func.getFunctionName() == function_name;
    });

    if (it != functions.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}
