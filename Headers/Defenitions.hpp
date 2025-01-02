#pragma once
#include "Dependencies.hpp"

class FunctionInfo;
void resolveFunctions(std::vector<FunctionInfo>& functions);
template <typename... Args> 
void callFunctionByName(const std::string& functionName, Args&&... args);
FunctionInfo* findFunctionByName(std::vector<FunctionInfo>& functions, const std::string& function_name);
