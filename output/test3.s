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
movq $4, -8(%rbp)
movq $5, -16(%rbp)
movq -8(%rbp), %r13
movq -16(%rbp), %r14
andq %r14, %r13
movq %r13, -24(%rbp)
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
