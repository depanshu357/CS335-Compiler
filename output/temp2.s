.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main

#main:   
main:
pushq %rbp
movq %rsp, %rbp

#.t1 = 45
movq $45, -8(%rbp)

#x = .t1
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

#.t2 = 3
movq $3, -24(%rbp)

#.t3 = x >> .t2
movq -16(%rbp), %r13
movq -24(%rbp), %r14
movq %r13, %rax
movq %r14, %rcx
shr %cl, %al
movq %rax, -32(%rbp)

#x = .t3
movq -32(%rbp), %r13
movq %r13, -16(%rbp)

#print, x  
mov -16(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
