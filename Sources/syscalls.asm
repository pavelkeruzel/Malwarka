%include "syscall_macros.asm"  ; Include the file that contains the syscall macros

; Generate a syscall stub for NtAllocateVirtualMemory with syscall number 0x18
SYSCALL_STUB NtAllocateVirtualMemory, 0x18

; Generate a syscall stub for NtFreeVirtualMemory with syscall number 0x19
SYSCALL_STUB NtFreeVirtualMemory, 0x19

; Generate a syscall stub for NtProtectVirtualMemory with syscall number 0x1A
SYSCALL_STUB NtProtectVirtualMemory, 0x1A

; Generate a syscall stub for NtQueryVirtualMemory with syscall number 0x1B
SYSCALL_STUB NtQueryVirtualMemory, 0x1B
