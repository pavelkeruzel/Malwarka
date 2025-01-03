#ifndef CONCRETESYSCALLFACTORY_H
#define CONCRETESYSCALLFACTORY_H

#include "syscall_factory.h"
#include "concrete_syscall.h"

// Concrete factory class for creating ConcreteSyscall objects
class ConcreteSyscallFactory : public SyscallFactory {
public:
    // Override the createSyscall function to create a ConcreteSyscall object
    Syscall* createSyscall(int ssn, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) const override {
        return new ConcreteSyscall(ssn, arg1, arg2, arg3, arg4, arg5);
    }
};

#endif // CONCRETESYSCALLFACTORY_H
