%macro SYSCALL_STUB 2        ; Define a macro named SYSCALL_STUB that takes 2 arguments

section .text align=16       ; Define a new section for code with 16-byte alignment

global %1                    ; Export the label provided as the first argument

%1:                          ; Define the label with the name provided as the first argument
    mov r10, rcx             ; Move the value in rcx to r10, as per syscall calling conventions
    mov eax, %2              ; Move the syscall number provided as the second argument into eax
    lea rcx, [rel syscall]   ; Load the effective address of the syscall instruction into rcx
    jmp rcx                  ; Jump to the address stored in rcx, effectively jumping to the syscall instruction
    ret                      ; Return from the procedure

syscall:                     ; Define the label for the actual syscall instruction
    syscall                  ; Execute the syscall instruction
    ret                      ; Return from the syscall instruction

%endmacro                    ; End the macro definition
