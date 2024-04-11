.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main
main:

movq %r14, -0(%r15)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
