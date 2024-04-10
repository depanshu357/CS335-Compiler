.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main
main:
push %rbp
movq %rsp, %r15
movq $3, -0(%r15)
movq $2, -8(%r15)
movq -0(%r15), %rdx
movq -8(%r15), %r14
cqto
idivq %r14
movq %rdx, -16(%r15)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
