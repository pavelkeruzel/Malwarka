// #pragma once
// #include "Defenitions.hpp"
// #include "FunctionInfo.hpp"

// template <typename... Args>
// void callFunctionByName(std::unordered_map<std::string, FunctionInfo>& functionInfoMap, const std::string& functionName, Args&&... args) {
//     auto it = functionInfoMap.find(functionName);
//     if (it != functionInfoMap.end()) {
//         void* functionPointer = it->second.getFunctionPointer();
//         if (functionPointer) {
//             auto callFunction = [&](auto&&... params) {
//                 if (functionName == "MessageBoxA") {
//                     using FunctionType = int (WINAPI *)(HWND, LPCSTR, LPCSTR, UINT);
//                     auto func = reinterpret_cast<FunctionType>(functionPointer);
//                     return func(std::forward<decltype(params)>(params)...);
//                 } else if (functionName == "GetTickCount") {
//                     using FunctionType = DWORD (WINAPI *)();
//                     auto func = reinterpret_cast<FunctionType>(functionPointer);
//                     return func();
//                 }
//                 throw std::runtime_error("Unknown function: " + functionName);
//             };
//             callFunction(std::forward<Args>(args)...);
//         } else {
//             throw std::runtime_error("Function pointer is null for function: " + functionName);
//         }
//     } else {
//         throw std::runtime_error("Function not found: " + functionName);
//     }
// }
