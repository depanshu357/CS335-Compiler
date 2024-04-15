.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.global main

#Test___init__:   
Test___init__:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 0(%rbp) self 
movq 0(%rbp), %r13
movq %r13, -8(%rbp)

#.t1 = self + 0
movq -8(%rbp), %r13
movq $0, %r14
addq %r13, %r14
movq %r14, -24(%rbp)

#.t2 = 1
movq $1, -32(%rbp)

#move8 .t2 .t1 
movq -32(%rbp), %r13
movq %r13, -24(%rbp)

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $32, %rsp
popq %rbp
movq $8, %r13
ret

#Test_add:   
Test_add:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 0(%rbp) self 
movq 0(%rbp), %r13
movq %r13, -8(%rbp)

#move8 24(%rbp) b 
movq 24(%rbp), %r13
movq %r13, -16(%rbp)

#.t3 = self + 8
movq -8(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t4 = .t3 + b
movq -40(%rbp), %r13
movq -16(%rbp), %r14
addq %r13, %r14
movq %r14, -48(%rbp)

#move8 .t4 x 
movq -48(%rbp), %r13
movq %r13, -56(%rbp)

#move8 x %rax 
movq -56(%rbp), %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $56, %rsp
popq %rbp
movq $16, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp

##callnew   
movq %rsp, -56(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#.t5 = alloc_mem(8) 
movq %rsp, -56(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $8, %rdi
call malloc@plt
movq -56(%rbp), %rsp
movq %rax, -8(%rbp)

#push .t5  
pushq -8(%rbp)

#call, Test___init__  
call Test___init__
addq %r13, %rsp
movq -56(%rbp), %rsp

#i = .t5
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

#.t6 = 0
movq $0, -24(%rbp)

#j = .t6
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

#.t7 = 1
movq $1, -40(%rbp)

##callnew   
movq %rsp, -56(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t7  
pushq -40(%rbp)

#push i  
pushq -16(%rbp)

#call, Test_add  
call Test_add
addq %r13, %rsp
movq -56(%rbp), %rsp

#move8 %rax j 
movq %rax, -32(%rbp)

#print, j int 
mov -32(%rbp), %rax
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
