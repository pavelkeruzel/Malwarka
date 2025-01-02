#include "../headers/function_info.hpp"

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
