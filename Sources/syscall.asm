.code

extern _NtAllocateVirtualMemory:proc

NtAllocateVirtualMemory PROC
    mov r10, rcx
    mov eax, 0x18
    lea rcx, [rel syscall]
    jmp rcx
    ret
syscall:
    syscall
    ret
NtAllocateVirtualMemory ENDP

end
