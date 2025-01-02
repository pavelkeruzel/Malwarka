#include "../headers/defenitions.hpp"
#include "../headers/function_info.hpp"

int main() {
    std::vector<FunctionInfo> functionInfo = {
        FunctionInfo("MessageBoxW", "User32.dll")    
    };

    resolveFunctions(functionInfo);
 
    FunctionInfo* msgBoxInfo = findFunctionByName(functionInfo, "MessageBoxW");
    MessageBoxParams params = { NULL, L"Lol hui", L"Sosi pidor", MB_OK | MB_ICONINFORMATION };
    invokeFunction<int, MessageBoxParams>(*msgBoxInfo, params);
    return 0;
}