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
movq -8(%rbp), %r13
movq %r13, -16(%rbp)
movq $0, -24(%rbp)
movq -24(%rbp), %r13
movq %r13, -32(%rbp)
movq $1, -40(%rbp)
movq $5, -48(%rbp)
movq -56(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -56(%rbp)
movq -56(%rbp), %r13
movq %r13, -64(%rbp)
.label2:
movq -72(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -72(%rbp)
movq -72(%rbp), %r13
movq -48(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -80(%rbp)
mov -80(%rbp), %rax
cmp $0, %rax
je .label1
movq -72(%rbp), %r13
movq %r13, -88(%rbp)
mov -88(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt
jmp .label2
.label1:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
