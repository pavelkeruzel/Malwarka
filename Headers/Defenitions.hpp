#pragma once
#include "dependencies.hpp"

// Forward declaration of the FunctionInfo class
class FunctionInfo;

/**
 * @brief Resolves functions from dynamic libraries and stores their addresses.
 * 
 * This function iterates through a vector of FunctionInfo structures, loads the specified libraries,
 * retrieves the addresses of the specified functions, and stores these addresses in the FunctionInfo structures.
 *
 * @param functions A reference to a vector containing FunctionInfo structures.
 * @throw std::runtime_error if the library cannot be loaded or the function address cannot be retrieved.
 */
void resolveFunctions(std::vector<FunctionInfo>& functions);

/**
 * @brief Calls a function by its name with the provided arguments.
 * 
 * This template function finds the function by its name and calls it with the specified arguments.
 *
 * @tparam Args The types of the arguments to pass to the function.
 * @param functionName The name of the function to call.
 * @param args The arguments to pass to the function.
 */
template <typename... Args> 
void callFunctionByName(const std::string& functionName, Args&&... args);

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
FunctionInfo* findFunctionByName(std::vector<FunctionInfo>& functions, const std::string& function_name);

/**
 * @brief Invokes a function by its address with the provided arguments and returns the result.
 * 
 * This template function converts the function address to a callable function, 
 * calls it with the specified arguments, and returns the result.
 *
 * @tparam Ret The return type of the function.
 * @tparam Args The types of the arguments to pass to the function.
 * @param funcInfo A pointer to a FunctionInfo structure containing the function address.
 * @param args The arguments to pass to the function.
 * @return Ret The result of the function call.
 * @throw std::invalid_argument if the function address is invalid.
 */
template<typename Ret, typename... Args>
Ret invokeFunction(FunctionInfo* funcInfo, Args... args);

int MessageBoxW(
  HWND    hWnd,       // Дескриптор родительского окна
  LPCWSTR lpText,     // Текст сообщения
  LPCWSTR lpCaption,  // Заголовок окна сообщения
  UINT    uType       // Тип окна сообщения (иконки, кнопки и т. д.)
);
