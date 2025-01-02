#include "../headers/function_info.hpp"

template<typename Ret, typename... Args>
Ret invokeFunction(FunctionInfo* funcInfo, Args... args) {
    if (!funcInfo || !funcInfo->function_address) {
        throw std::invalid_argument("Invalid function address.");
    }
    
    std::function<Ret(Args...)> func = reinterpret_cast<Ret(*)(Args...)>(funcInfo->function_address);
    
    return func(args...);
}
