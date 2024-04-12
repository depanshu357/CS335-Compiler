.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main

#.t1 = 5
movq $5, -8(%rbp)

#.t2 = 3
movq $3, -16(%rbp)

#.t3 = .t1 >= .t2
movq -8(%rbp), %r13
movq -16(%rbp), %r14
cmpq %r14, %r13
setge %al
movzbq %al, %r14
movq %r14, -24(%rbp)

#x = .t3
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
