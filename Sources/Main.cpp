#include "../headers/dependencies.hpp"
#include "../headers/defenitions.hpp"
#include "../headers/function_info.hpp"

int main() {
    // std::vector<FunctionInfo> functionInfo = {
    //     FunctionInfo("MessageBoxW", "User32.dll")    
    // };

    // resolveFunctions(functionInfo);

    // try {
    //     resolveFunctions(functionInfo);
    //     std::cout << "Functions resolved successfully." << std::endl;
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     return 1;
    // }
    
    // FunctionInfo* messageBoxInfo = findFunctionByName(functionInfo, "MessageBoxW");
    // if (messageBoxInfo != nullptr) {
    //     std::cout << messageBoxInfo->getFunctionName() << std::endl;
    //     std::cout << messageBoxInfo->getFunctionPointer() << std::endl;
    // }

    return 0;
}
