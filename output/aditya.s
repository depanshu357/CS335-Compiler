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
subq $312, %rsp

#.t1 = 5
movq $5, -8(%rbp)

#.t2 = 3
movq $3, -16(%rbp)

#.t3 = 8
movq $8, -24(%rbp)

#.t4 = 2
movq $2, -32(%rbp)

#.t5 = 1
movq $1, -40(%rbp)

#.t6 = 9
movq $9, -48(%rbp)

#.t7 = 4
movq $4, -56(%rbp)

#.t8 = 6
movq $6, -64(%rbp)

#.t9 = 7
movq $7, -72(%rbp)

#.t10 = declare_array(80) 
shr $4, %rsp
add $1, %rsp
shl $4, %rsp
movq $80, %rdi
call malloc@plt
movq %rax, -88(%rbp)

#.t11 = 0
movq $0, -80(%rbp)

#.t10[.t11] = 9 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq $9, %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t1 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -8(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t2 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -16(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t3 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -24(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t4 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -32(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t5 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -40(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t6 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -48(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t7 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -56(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t8 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -64(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10[.t11] = .t9 
movq -88(%rbp), %r13
movq -80(%rbp), %r14
movq -72(%rbp), %r15
movq %r15, (%r13, %r14)

#.t11 = .t11 + 8
movq -80(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t10 = .t10 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#data = .t10
movq -88(%rbp), %r13
movq %r13, -96(%rbp)

#.t12 = 0
movq $0, -104(%rbp)

#.t14 = .t12 * 8
movq -104(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -112(%rbp)

#i = data[.t14]
movq -96(%rbp), %r13
movq -112(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -120(%rbp)

#.t15 = 1
movq $1, -128(%rbp)

#.t17 = .t15 * 8
movq -128(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -136(%rbp)

#j = data[.t17]
movq -96(%rbp), %r13
movq -136(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -144(%rbp)

#.t18 = 2
movq $2, -152(%rbp)

#.t20 = .t18 * 8
movq -152(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -160(%rbp)

#k = data[.t20]
movq -96(%rbp), %r13
movq -160(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -168(%rbp)

#.t21 = 3
movq $3, -176(%rbp)

#.t23 = .t21 * 8
movq -176(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -184(%rbp)

#l = data[.t23]
movq -96(%rbp), %r13
movq -184(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -192(%rbp)

#.t24 = 4
movq $4, -200(%rbp)

#.t26 = .t24 * 8
movq -200(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -208(%rbp)

#m = data[.t26]
movq -96(%rbp), %r13
movq -208(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -216(%rbp)

#.t27 = 5
movq $5, -224(%rbp)

#.t29 = .t27 * 8
movq -224(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -232(%rbp)

#n = data[.t29]
movq -96(%rbp), %r13
movq -232(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -240(%rbp)

#.t30 = 6
movq $6, -248(%rbp)

#.t32 = .t30 * 8
movq -248(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -256(%rbp)

#o = data[.t32]
movq -96(%rbp), %r13
movq -256(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -264(%rbp)

#.t33 = 7
movq $7, -272(%rbp)

#.t35 = .t33 * 8
movq -272(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -280(%rbp)

#p = data[.t35]
movq -96(%rbp), %r13
movq -280(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -288(%rbp)

#.t36 = 8
movq $8, -296(%rbp)

#.t38 = .t36 * 8
movq -296(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -304(%rbp)

#q = data[.t38]
movq -96(%rbp), %r13
movq -304(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -312(%rbp)

#print, n  
mov -240(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
add $1, %rsp
shl $4, %rsp
call printf@plt

#print, o  
mov -264(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
add $1, %rsp
shl $4, %rsp
call printf@plt

#print, p  
mov -288(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
add $1, %rsp
shl $4, %rsp
call printf@plt

#print, q  
mov -312(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
add $1, %rsp
shl $4, %rsp
call printf@plt

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
