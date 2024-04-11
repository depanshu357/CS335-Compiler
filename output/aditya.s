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
movq $0, -8(%rbp)
subq $8, %rsp
movq -8(%rbp), %r13
movq %r13, -16(%rbp)
subq $8, %rsp
movq $0, -24(%rbp)
subq $8, %rsp
movq -24(%rbp), %r13
movq %r13, -32(%rbp)
subq $8, %rsp
movq $1, -40(%rbp)
subq $8, %rsp
movq $5, -48(%rbp)
subq $8, %rsp
movq -40(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -40(%rbp)
movq -40(%rbp), %r13
movq %r13, -56(%rbp)
subq $8, %rsp
.label2:
movq -56(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -56(%rbp)
movq -56(%rbp), %r13
movq -48(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -64(%rbp)
subq $8, %rsp
mov -64(%rbp), %rax
cmp $0, %rax
je .label1
movq -56(%rbp), %r13
movq %r13, -16(%rbp)
movq $1, -72(%rbp)
subq $8, %rsp
movq -32(%rbp), %r13
movq -72(%rbp), %r14
addq %r13, %r14
movq %r14, -80(%rbp)
subq $8, %rsp
movq -80(%rbp), %r13
movq %r13, -32(%rbp)
jmp .label2
.label1:
mov -32(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
