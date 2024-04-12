.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main

#temp:   
temp:
pushq %rbp
movq %rsp, %rbp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15
subq $16, %rsp

#move8 0(%rbp) a 
movq (%rbp), 0(%rbp)

#move8 4(%rbp) b 
movq (%rbp), 4(%rbp)

#.t1 = 1
movq $1, -8(%rbp)

#i = .t1
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

#move i %rax 

#move8 %rbp %rsp 
movq %, %

#move8 -8(%rbp) %rbp 
movq %, -8(%rbp)

#add %rsp $8 

#main:   
main:
pushq %rbp
movq %rsp, %rbp

#.t2 = 123
movq $123, -8(%rbp)

#i = .t2
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

#.t3 = 0
movq $0, -24(%rbp)

#j = .t3
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

#push j  

#push i  

#call, temp  

#move %rax .t4 

#.t5 = 1
movq $1, -40(%rbp)

#.t6 = 5
movq $5, -48(%rbp)

#.t5 = .t5 - 1
movq -40(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -40(%rbp)

#.t7 = .t5
movq -40(%rbp), %r13
movq %r13, -56(%rbp)

#.label2:   
.label2:

#.t7 = .t7 + 1
movq -56(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -56(%rbp)

#.t8 = .t7 < .t6
movq -56(%rbp), %r13
movq -48(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -64(%rbp)

#if_false .t8 goto .label1
mov -64(%rbp), %rax
cmp $0, %rax
je .label1

#i = .t7
movq -56(%rbp), %r13
movq %r13, -16(%rbp)

#print, j  
mov -32(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt

#.t9 = i * j
movq -16(%rbp), %r13
movq -32(%rbp), %r14
imulq %r13, %r14
movq %r14, -72(%rbp)

#.t10 = 1
movq $1, -80(%rbp)

#.t11 = .t9 + .t10
movq -72(%rbp), %r13
movq -80(%rbp), %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#j = .t11
movq -88(%rbp), %r13
movq %r13, -32(%rbp)

#goto .label2  
jmp .label2

#.label1:   
.label1:

#move8 %rbp %rsp 
movq %, %

#move8 -8(%rbp) %rbp 
movq %, -8(%rbp)

#add %rsp $0 

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
