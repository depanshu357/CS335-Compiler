.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main
main:
pushq %rbp
movq %rsp, %rbp
movq $123, -8(%rbp)
movq -8(%rbp), %r13
movq %r13, -16(%rbp)
movq $0, -24(%rbp)
movq -24(%rbp), %r13
movq %r13, -32(%rbp)
movq $1, -40(%rbp)
movq $5, -48(%rbp)
movq -40(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -40(%rbp)
movq -40(%rbp), %r13
movq %r13, -56(%rbp)
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
mov -64(%rbp), %rax
cmp $0, %rax
je .label1
movq -56(%rbp), %r13
movq %r13, -16(%rbp)
mov -32(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt
movq -16(%rbp), %r13
movq -32(%rbp), %r14
imulq %r13, %r14
movq %r14, -72(%rbp)
movq $1, -80(%rbp)
movq -72(%rbp), %r13
movq -80(%rbp), %r14
addq %r13, %r14
movq %r14, -88(%rbp)
movq -88(%rbp), %r13
movq %r13, -32(%rbp)
jmp .label2
.label1:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
