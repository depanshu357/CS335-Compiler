.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str1:
        .string "Sorted Array in Ascending Order:\n"
        .text
.global main

#bubbleSort:   
bubbleSort:
pushq %rbp
movq %rsp, %rbp
subq $312, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) array 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t1 = 0
movq $0, -24(%rbp)

#i = .t1
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

#.t2 = 0
movq $0, -40(%rbp)

#j = .t2
movq -40(%rbp), %r13
movq %r13, -48(%rbp)

#.t3 = -8
movq $-8, %r13
movq %r13, -56(%rbp)

#.t4 = array[.t3]
movq -8(%rbp), %r10
movq -56(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -64(%rbp)

#.t5 = -1
movq $-1, %r13
movq %r13, -72(%rbp)

#.t6 = .t5
movq -72(%rbp), %r13
movq %r13, -80(%rbp)

#.label2:   
.label2:

#.t6 = .t6 + 1
movq -80(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -80(%rbp)

#.t7 = .t6 < .t4
movq -80(%rbp), %r13
movq -64(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -88(%rbp)

#if_false .t7 goto .label1
mov -88(%rbp), %rax
cmp $0, %rax
je .label1

#i = .t6
movq -80(%rbp), %r13
movq %r13, -32(%rbp)

#.t8 = False
movq (%rbp), %r13
movq %r13, -96(%rbp)

#swapped = .t8
movq -96(%rbp), %r13
movq %r13, -104(%rbp)

#.t9 = 0
movq $0, -112(%rbp)

#.t10 = -8
movq $-8, %r13
movq %r13, -120(%rbp)

#.t11 = array[.t10]
movq -8(%rbp), %r10
movq -120(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -128(%rbp)

#.t12 = .t11 - i
movq -128(%rbp), %r13
movq -32(%rbp), %r14
subq %r14, %r13
movq %r13, -136(%rbp)

#.t13 = 1
movq $1, -144(%rbp)

#.t14 = .t12 - .t13
movq -136(%rbp), %r13
movq -144(%rbp), %r14
subq %r14, %r13
movq %r13, -152(%rbp)

#.t9 = .t9 - 1
movq -112(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -112(%rbp)

#.t15 = .t9
movq -112(%rbp), %r13
movq %r13, -160(%rbp)

#.label4:   
.label4:

#.t15 = .t15 + 1
movq -160(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -160(%rbp)

#.t16 = .t15 < .t14
movq -160(%rbp), %r13
movq -152(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -168(%rbp)

#if_false .t16 goto .label3
mov -168(%rbp), %rax
cmp $0, %rax
je .label3

#j = .t15
movq -160(%rbp), %r13
movq %r13, -48(%rbp)

#.t18 = j * 8
movq -48(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -176(%rbp)

#.t19 = 1
movq $1, -184(%rbp)

#.t20 = j + .t19
movq -48(%rbp), %r13
movq -184(%rbp), %r14
addq %r13, %r14
movq %r14, -192(%rbp)

#.t22 = .t20 * 8
movq -192(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -200(%rbp)

#.t23 = array[.t18] > array[.t22]
movq -8(%rbp), %r10
movq -176(%rbp), %r11
movq -8(%rbp), %r12
movq -200(%rbp), %r15
movq ( %r10, %r11 ), %r13
movq ( %r12, %r15 ), %r14
cmpq %r14, %r13
setg %al
movzbq %al, %r14
movq %r14, -208(%rbp)

#if_false .t23 goto .label6
mov -208(%rbp), %rax
cmp $0, %rax
je .label6

#.t25 = j * 8
movq -48(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -216(%rbp)

#temp = array[.t25]
movq -8(%rbp), %r10
movq -216(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -224(%rbp)

#.t27 = j * 8
movq -48(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -232(%rbp)

#.t28 = 1
movq $1, -240(%rbp)

#.t29 = j + .t28
movq -48(%rbp), %r13
movq -240(%rbp), %r14
addq %r13, %r14
movq %r14, -248(%rbp)

#.t31 = .t29 * 8
movq -248(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -256(%rbp)

#array[.t27] = array[.t31]
movq -8(%rbp), %r8
movq -232(%rbp), %r9
movq -8(%rbp), %r10
movq -256(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, ( %r8, %r9 )

#.t32 = 1
movq $1, -272(%rbp)

#.t33 = j + .t32
movq -48(%rbp), %r13
movq -272(%rbp), %r14
addq %r13, %r14
movq %r14, -280(%rbp)

#.t35 = .t33 * 8
movq -280(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -288(%rbp)

#array[.t35] = temp
movq -8(%rbp), %r8
movq -288(%rbp), %r9
movq -224(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t36 = True
movq (%rbp), %r13
movq %r13, -304(%rbp)

#swapped = .t36
movq -304(%rbp), %r13
movq %r13, -104(%rbp)

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

#.t37 = not swapped
movq -104(%rbp), %r14
cmpq $0, %r14
sete %al
movzbq %al, %r14
movq %r14, -312(%rbp)

#if_false .t37 goto .label8
mov -312(%rbp), %rax
cmp $0, %rax
je .label8

#goto .label7  
jmp .label7

#.label8:   
.label8:

#.label7:   
.label7:

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
addq $312, %rsp
popq %rbp
movq $8, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $184, %rsp

#.t38 = 2
movq $2, -8(%rbp)

#.t39 = .t38 * -1
movq -8(%rbp), %r13
movq $-1, %r14
imulq %r13, %r14
movq %r14, -16(%rbp)

#.t40 = 45
movq $45, -24(%rbp)

#.t41 = 0
movq $0, -32(%rbp)

#.t42 = 11
movq $11, -40(%rbp)

#.t43 = 9
movq $9, -48(%rbp)

#.t44 = .t43 * -1
movq -48(%rbp), %r13
movq $-1, %r14
imulq %r13, %r14
movq %r14, -56(%rbp)

#.t45 = alloc_mem(48) 
movq %rsp, -184(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $48, %rdi
call malloc@plt
movq -184(%rbp), %rsp
movq %rax, -64(%rbp)

#.t46 = 0
movq $0, -72(%rbp)

#.t45[.t46] = 5
movq -64(%rbp), %r8
movq -72(%rbp), %r9
movq $5, ( %r8, %r9 )

#.t46 = .t46 + 8
movq -72(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -72(%rbp)

#.t45[.t46] = .t39
movq -64(%rbp), %r8
movq -72(%rbp), %r9
movq -16(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t46 = .t46 + 8
movq -72(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -72(%rbp)

#.t45[.t46] = .t40
movq -64(%rbp), %r8
movq -72(%rbp), %r9
movq -24(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t46 = .t46 + 8
movq -72(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -72(%rbp)

#.t45[.t46] = .t41
movq -64(%rbp), %r8
movq -72(%rbp), %r9
movq -32(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t46 = .t46 + 8
movq -72(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -72(%rbp)

#.t45[.t46] = .t42
movq -64(%rbp), %r8
movq -72(%rbp), %r9
movq -40(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t46 = .t46 + 8
movq -72(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -72(%rbp)

#.t45[.t46] = .t44
movq -64(%rbp), %r8
movq -72(%rbp), %r9
movq -56(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t46 = .t46 + 8
movq -72(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -72(%rbp)

#.t45 = .t45 + 8
movq -64(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -64(%rbp)

#data = .t45
movq -64(%rbp), %r13
movq %r13, -88(%rbp)

##callnew   
movq %rsp, -184(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push data  
pushq -88(%rbp)

#call, bubbleSort  
call bubbleSort
addq %r13, %rsp
movq -184(%rbp), %rsp

#move8 %rax .t47 
movq %rax, %r13
movq %r13, -96(%rbp)

#.t48 = "Sorted Array in Ascending Order:"
movq $.str1, %r13
movq %r13, -112(%rbp)

#print, .t48 str 
mov -112(%rbp), %rax
mov %rax, %rsi
movq -112(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -184(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -184(%rbp), %rsp

#.t49 = 0
movq $0, -120(%rbp)

#i = .t49
movq -120(%rbp), %r13
movq %r13, -128(%rbp)

#.t50 = -8
movq $-8, %r13
movq %r13, -136(%rbp)

#.t51 = data[.t50]
movq -88(%rbp), %r10
movq -136(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -144(%rbp)

#.t52 = -1
movq $-1, %r13
movq %r13, -152(%rbp)

#.t53 = .t52
movq -152(%rbp), %r13
movq %r13, -160(%rbp)

#.label10:   
.label10:

#.t53 = .t53 + 1
movq -160(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -160(%rbp)

#.t54 = .t53 < .t51
movq -160(%rbp), %r13
movq -144(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -168(%rbp)

#if_false .t54 goto .label9
mov -168(%rbp), %rax
cmp $0, %rax
je .label9

#i = .t53
movq -160(%rbp), %r13
movq %r13, -128(%rbp)

#.t56 = i * 8
movq -128(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -176(%rbp)

#print, data[.t56] int 
movq -88(%rbp), %r8
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

#goto .label10  
jmp .label10

#.label9:   
.label9:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
