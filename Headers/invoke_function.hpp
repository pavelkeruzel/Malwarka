#include "../headers/function_info.hpp"

/**
 * @brief Invokes a function by its address with the provided arguments and returns the result.
 * 
 * This template function converts the function address stored in the FunctionInfo structure
 * into a callable function, calls it with the specified arguments, and returns the result.
 *
 * @tparam Ret The return type of the function.
 * @tparam Args The types of the arguments to pass to the function.
 * @param funcInfo A pointer to a FunctionInfo structure containing the function address.
 * @param args The arguments to pass to the function.
 * @return Ret The result of the function call.
 * @throw std::invalid_argument if the function address is invalid.
 */
template<typename Ret, typename... Args>
Ret invokeFunction(const FunctionInfo& funcInfo, const Args&... args) {
    // Check if the function address is valid
    if (!funcInfo.getFunctionAddress()) {
        throw std::invalid_argument("Invalid function address.");
    }
    
    // Convert the function address to a callable function pointer
    std::function<Ret(Args...)> func = reinterpret_cast<Ret(*)(Args...)>(funcInfo.getFunctionAddress());
    
    // Call the function with the provided arguments and return the result
    return func(args...);
}

