#ifndef SYSCALL_H
#define SYSCALL_H

// Base class for system calls
class Syscall {
public:
    virtual ~Syscall() = default;

    // Pure virtual function to execute the system call
    virtual void execute() const = 0;
};

#endif // SYSCALL_H
