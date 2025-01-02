section .text

extern _NtAllocateVirtualMemory

NtAllocateVirtualMemory:
    mov r10, rcx                ; Переместить аргумент rcx в r10
    mov eax, 0x18               ; Номер системного вызова для NtAllocateVirtualMemory
    lea rcx, [rel syscall]      ; Получить адрес инструкции syscall
    jmp rcx                     ; Безусловный переход
    ret
syscall:
    syscall                     ; Вызов системного вызова
    ret
