section .text
    global indirect_syscall

; Function to perform an indirect system call
indirect_syscall:
    mov rax, [rsp + 8]   ; SSN (ID of the system call)
    mov rdi, [rsp + 16]  ; First argument
    mov rsi, [rsp + 24]  ; Second argument
    mov rdx, [rsp + 32]  ; Third argument
    mov r10, [rsp + 40]  ; Fourth argument
    mov r8,  [rsp + 48]  ; Fifth argument
    syscall              ; Perform the system call
    ret
