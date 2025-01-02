%include "syscall_macros.asm"

SYSCALL_STUB NtAllocateVirtualMemory, 0x18
SYSCALL_STUB NtFreeVirtualMemory, 0x19
SYSCALL_STUB NtProtectVirtualMemory, 0x1A
SYSCALL_STUB NtQueryVirtualMemory, 0x1B
