#include "concrete_syscall.h"
#include "dependencies.h"

// Execute the system call using inline assembly
void ConcreteSyscall::execute() const {
#ifdef _WIN64
    __asm {
        mov rax, ssn
        mov rdi, arg1
        mov rsi, arg2
        mov rdx, arg3
        mov r10, arg4
        mov r8, arg5
        syscall
    }
#else
    __asm {
        mov eax, ssn
        mov ebx, arg1
        mov ecx, arg2
        mov edx, arg3
        mov esi, arg4
        mov edi, arg5
        int 0x2e
    }
#endif
    std::cout << "Syscall executed with SSN: " << ssn << std::endl;
}
