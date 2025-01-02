#include "../headers/defenitions.hpp"
#include "../headers/function_info.hpp"

int main() {
    std::vector<FunctionInfo> functionInfo = {
        FunctionInfo("MessageBoxW", "User32.dll")    
    };

    resolveFunctions(functionInfo);
 
    FunctionInfo* messageBoxInfo = findFunctionByName(functionInfo, "MessageBoxW");
    

    return 0;
}
