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
movq (%rbp), %r13
movq %r13, -8(%rbp)
movq -8(%rbp), %r14
cmpq $0, %r14
sete %al
movzbq %al, %r14
movq %r14, -16(%rbp)
movq -16(%rbp), %r13
movq %r13, -24(%rbp)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
