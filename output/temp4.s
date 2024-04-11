.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main
main:
push %rbp
movq %rsp, %rbp
movq $5, -8(%rbp)
movq $3, -16(%rbp)
movq -8(%rbp), %r13
movq -16(%rbp), %r14
xorq %r13, %r14
movq %r14, -24(%rbp)
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
