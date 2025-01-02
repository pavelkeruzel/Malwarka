%macro SYSCALL_STUB 2
section .text align=16

global %1

%1:
    mov r10, rcx                ; Переместить аргумент rcx в r10
    mov eax, %2                 ; Номер системного вызова для %1
    lea rcx, [rel syscall]      ; Получить адрес инструкции syscall
    jmp rcx                     ; Безусловный переход
    ret
syscall:
    syscall                     ; Вызов системного вызова
    ret
%endmacro
