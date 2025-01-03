#ifndef SYSCALLFACTORY_H
#define SYSCALLFACTORY_H

#include "syscall.h"

// Factory class for creating system call objects
class SyscallFactory {
public:
    virtual ~SyscallFactory() = default;

    // Pure virtual function to create a system call object
    virtual Syscall* createSyscall(int ssn, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) const = 0;
};

#endif // SYSCALLFACTORY_H
