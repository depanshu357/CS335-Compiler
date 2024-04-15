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
subq $56, %rsp

#.t1 = 8
movq $8, -8(%rbp)

#.t2 = 4
movq $4, -16(%rbp)

#.t3 = 2
movq $2, -24(%rbp)

#.t4 = .t2 - .t3
movq -16(%rbp), %r13
movq -24(%rbp), %r14
subq %r14, %r13
movq %r13, -32(%rbp)

#.t5 = .t1 - .t4
movq -8(%rbp), %r13
movq -32(%rbp), %r14
subq %r14, %r13
movq %r13, -40(%rbp)

#x = .t5
movq -40(%rbp), %r13
movq %r13, -48(%rbp)

#print, x int 
mov -48(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -56(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -56(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
