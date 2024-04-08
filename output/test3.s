.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main
main:
push %rbx
movq %rsp, %r15
movq $3, -0(%r15)
movq $2, -8(%r15)
movq -0(%r15), %r13
movq -8(%r15), %r14
addq %r13, %r14
movq %r14, -16(%r15)
mov -16(%r15), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
