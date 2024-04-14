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
subq $208, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) arr 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t1 = 0
movq $0, -16(%rbp)

#i = .t1
movq -16(%rbp), %r13
movq %r13, -24(%rbp)

#.t2 = 0
movq $0, -32(%rbp)

#j = .t2
movq -32(%rbp), %r13
movq %r13, -40(%rbp)

#.t3 = 10
movq $10, -48(%rbp)

#n = .t3
movq -48(%rbp), %r13
movq %r13, -56(%rbp)

#.t4 = 0
movq $0, -64(%rbp)

#.t4 = .t4 - 1
movq -64(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -64(%rbp)

#.t5 = .t4
movq -64(%rbp), %r13
movq %r13, -72(%rbp)

#.label2:   
.label2:

#.t5 = .t5 + 1
movq -72(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -72(%rbp)

#.t6 = .t5 < n
movq -72(%rbp), %r13
movq -56(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -80(%rbp)

#if_false .t6 goto .label1
mov -80(%rbp), %rax
cmp $0, %rax
je .label1

#i = .t5
movq -72(%rbp), %r13
movq %r13, -24(%rbp)

#.t7 = 0
movq $0, -88(%rbp)

#.t7 = .t7 - 1
movq -88(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -88(%rbp)

#.t8 = .t7
movq -88(%rbp), %r13
movq %r13, -96(%rbp)

#.label4:   
.label4:

#.t8 = .t8 + 1
movq -96(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -96(%rbp)

#.t9 = .t8 < n
movq -96(%rbp), %r13
movq -56(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -104(%rbp)

#if_false .t9 goto .label3
mov -104(%rbp), %rax
cmp $0, %rax
je .label3

#j = .t8
movq -96(%rbp), %r13
movq %r13, -40(%rbp)

#.t11 = j * 8
movq -40(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -112(%rbp)

#a = arr[.t11]
movq -8(%rbp), %r10
movq -112(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -120(%rbp)

#.t12 = 1
movq $1, -128(%rbp)

#.t13 = j + .t12
movq -40(%rbp), %r13
movq -128(%rbp), %r14
addq %r13, %r14
movq %r14, -136(%rbp)

#.t15 = .t13 * 8
movq -136(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -144(%rbp)

#b = arr[.t15]
movq -8(%rbp), %r10
movq -144(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -152(%rbp)

#.t16 = a > b
movq -120(%rbp), %r13
movq -152(%rbp), %r14
cmpq %r14, %r13
setg %al
movzbq %al, %r14
movq %r14, -160(%rbp)

#if_false .t16 goto .label6
mov -160(%rbp), %rax
cmp $0, %rax
je .label6

#.t18 = j * 8
movq -40(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -168(%rbp)

#arr[.t18] = b
movq -8(%rbp), %r8
movq -168(%rbp), %r9
movq -152(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t19 = 1
movq $1, -184(%rbp)

#.t20 = j + .t19
movq -40(%rbp), %r13
movq -184(%rbp), %r14
addq %r13, %r14
movq %r14, -192(%rbp)

#.t22 = .t20 * 8
movq -192(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -200(%rbp)

#arr[.t22] = a
movq -8(%rbp), %r8
movq -200(%rbp), %r9
movq -120(%rbp), %r13
movq %r13, ( %r8, %r9 )

#goto .label5  
jmp .label5

#.label6:   
.label6:

#.label5:   
.label5:

#goto .label4  
jmp .label4

#.label3:   
.label3:

#goto .label2  
jmp .label2

#.label1:   
.label1:

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $208, %rsp
popq %rbp
movq $8, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $184, %rsp

#.t23 = 10
movq $10, -8(%rbp)

#.t24 = 9
movq $9, -16(%rbp)

#.t25 = 8
movq $8, -24(%rbp)

#.t26 = 7
movq $7, -32(%rbp)

#.t27 = 6
movq $6, -40(%rbp)

#.t28 = 5
movq $5, -48(%rbp)

#.t29 = 4
movq $4, -56(%rbp)

#.t30 = 3
movq $3, -64(%rbp)

#.t31 = 2
movq $2, -72(%rbp)

#.t32 = 1
movq $1, -80(%rbp)

#.t33 = alloc_mem(88) 
movq %rsp, -184(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $88, %rdi
call malloc@plt
movq -184(%rbp), %rsp
movq %rax, -96(%rbp)

#.t34 = 0
movq $0, -88(%rbp)

#.t33[.t34] = 10 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq $10, %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t23 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -8(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t24 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -16(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t25 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -24(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t26 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -32(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t27 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -40(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t28 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -48(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t29 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -56(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t30 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -64(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t31 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -72(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33[.t34] = .t32 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -80(%rbp), %r15
movq %r15, (%r13, %r14)

#.t34 = .t34 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t33 = .t33 + 8
movq -96(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -96(%rbp)

#data = .t33
movq -96(%rbp), %r13
movq %r13, -104(%rbp)

##callnew   
movq %rsp, -184(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push data  
pushq -104(%rbp)

#call, temp  
call temp
addq %r13, %rsp
movq -184(%rbp), %rsp

#move8 %rax .t35 
movq %rax, -112(%rbp)

#.t36 = 10
movq $10, -120(%rbp)

#n = .t36
movq -120(%rbp), %r13
movq %r13, -128(%rbp)

#.t37 = 0
movq $0, -136(%rbp)

#i = .t37
movq -136(%rbp), %r13
movq %r13, -144(%rbp)

#.t38 = 0
movq $0, -152(%rbp)

#.t38 = .t38 - 1
movq -152(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -152(%rbp)

#.t39 = .t38
movq -152(%rbp), %r13
movq %r13, -160(%rbp)

#.label8:   
.label8:

#.t39 = .t39 + 1
movq -160(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -160(%rbp)

#.t40 = .t39 < n
movq -160(%rbp), %r13
movq -128(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -168(%rbp)

#if_false .t40 goto .label7
mov -168(%rbp), %rax
cmp $0, %rax
je .label7

#i = .t39
movq -160(%rbp), %r13
movq %r13, -144(%rbp)

#.t42 = i * 8
movq -144(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -176(%rbp)

#print, data[.t42] int 
movq -104(%rbp), %r8
movq -176(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -184(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -184(%rbp), %rsp

#goto .label8  
jmp .label8

#.label7:   
.label7:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
