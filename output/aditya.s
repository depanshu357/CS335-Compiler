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

#.t1 = 3
movq $3, -8(%rbp)

#print, .t1  
mov -8(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt

#.t2 = 5
movq $5, -16(%rbp)

#.t3 = 3
movq $3, -24(%rbp)

#.t4 = 8
movq $8, -32(%rbp)

#.t5 = 2
movq $2, -40(%rbp)

#.t6 = 1
movq $1, -48(%rbp)

#.t7 = 9
movq $9, -56(%rbp)

#.t8 = 4
movq $4, -64(%rbp)

#.t9 = 6
movq $6, -72(%rbp)

#.t10 = 7
movq $7, -80(%rbp)

#.t11 = declare_array(40) 
movq $80, %rdi
call malloc@plt
movq %rax, -96(%rbp)

#.t12 = 0
movq $0, -88(%rbp)

#.t11[.t12] = 9 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t2 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t3 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t4 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t5 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t6 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t7 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t8 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t9 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t10 

#.t12 = .t12 + 4
movq -88(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11 = .t11 + 4
movq -96(%rbp), %r13
movq $4, %r14
addq %r13, %r14
movq %r14, -96(%rbp)

#data = .t11
movq -96(%rbp), %r13
movq %r13, -104(%rbp)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
