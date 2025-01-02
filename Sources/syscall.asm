section .text align=16   ; Start a new section of code with text (code) segment, align by 16 bytes

extern _NtAllocateVirtualMemory  ; Declare external procedure to be imported

NtAllocateVirtualMemory:   ; Label for the procedure NtAllocateVirtualMemory
    mov r10, rcx           ; Move the value in rcx to r10, according to syscall calling conventions
    mov eax, 0x18          ; Move the syscall number (0x18) for NtAllocateVirtualMemory into eax
    lea rcx, [rel syscall] ; Load the effective address of the syscall label into rcx
    jmp rcx                ; Jump to the address stored in rcx, effectively jumping to the syscall instruction
    ret                    ; Return from the procedure

syscall:                   ; Label for syscall instruction
    syscall                ; Execute the syscall instruction
    ret                    ; Return from the syscall instruction
