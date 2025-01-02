section .text align=16

global NtAllocateVirtualMemory 

extern NtAllocateVirtualMemory  

NtAllocateVirtualMemory:
    mov r10, rcx                
    mov eax, 0x18              
    lea rcx, [rel syscall]    
    jmp rcx                   
    ret
syscall:
    syscall        
    ret
