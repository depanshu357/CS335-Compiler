.section .data
msg:    .asciz "hi\n"   # Null-terminated string to be printed
len = . - msg          # Compute length of the string

.section .text
.global main

main:
    # write syscall
    mov $1, %rax        # System call number for write
    mov $1, %rdi        # File descriptor 1 is stdout
    mov $msg, %rsi      # Address of the string
    mov $len, %rdx      # Length of the string
    syscall             # Invoke the system call

    # exit syscall
    mov $60, %rax       # System call number for exit
    xor %rdi, %rdi      # Exit code is 0
    syscall             # Invoke the system call


.note0:

        .string "%ld\n"
        .text
        .globl main