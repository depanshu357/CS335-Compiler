.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"

        .text
.global main
main:
movq -0(%r15), %r13
movq -8(%r15), %r14
addq %r13, %r14
movq %r14, -16(%r15)
mov -20(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rdi
mov %rax, %rdi
xor %rax, %rax
call printf@plt

ret
