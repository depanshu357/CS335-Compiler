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
subq $16, %rsp

#.t1 = 123
movq $123, -8(%rbp)

#i = .t1
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

#print, i  
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
