#include "../headers/defenitions.hpp"
#include "../headers/function_info.hpp"

int main() {
    std::vector<FunctionInfo> functionInfo = {
        FunctionInfo("MessageBoxW", "User32.dll")
    };

    std::cout << "Resolving functions..." << std::endl;
    resolveFunctions(functionInfo);

    std::cout << "Finding function 'MessageBoxW'..." << std::endl;
    FunctionInfo* msgBoxInfo = findFunctionByName(functionInfo, "MessageBoxW");
    if (!msgBoxInfo) {
        std::cerr << "Function 'MessageBoxW' not found." << std::endl;
        return 1;
    }

    std::cout << "Function address: " << msgBoxInfo->getFunctionAddress() << std::endl;

    MessageBoxParams params = { GetDesktopWindow(), L"Hello, World!", L"Message Box", MB_OK | MB_ICONINFORMATION };

    std::cout << "Parameters: " 
              << "\nhWnd: " << params.hWnd 
              << "\nText: " << params.lpText 
              << "\nCaption: " << params.lpCaption 
              << "\nType: " << params.uType << std::endl;

    std::cout << "Invoking 'MessageBoxW'..." << std::endl;
    int result = invokeFunction<int>(*msgBoxInfo, params);
    std::cout << "MessageBoxW returned: " << result << std::endl;

    int directResult = MessageBoxW(GetDesktopWindow(), L"Direct call: Hello, World!", L"Direct Message Box", MB_OK | MB_ICONINFORMATION);
    std::cout << "Direct MessageBoxW returned: " << directResult << std::endl;

    return 0;
}
