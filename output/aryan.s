.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str1:
        .string "Result of expression 1:\n"
        .text
.str2:
        .string "\nResult of expression 2:\n"
        .text
.str3:
        .string "\nResult of expression 3:\n"
        .text
.str4:
        .string "\nResult of expression 4:\n"
        .text
.str5:
        .string "\nResult of expression 5:\n"
        .text
.str6:
        .string "\nResult of expression 6:\n"
        .text
.str7:
        .string "\nResult of expression 7:\n"
        .text
.str8:
        .string "\nResult of expression 8:\n"
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
subq $400, %rsp

#.t5 = "Result of expression 1:"
movq $.str1, %r13
movq %r13, -8(%rbp)

#print, .t5 str 
mov -8(%rbp), %rax
mov %rax, %rsi
movq -8(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t6 = 4
movq $4, -16(%rbp)

#.t7 = 3
movq $3, -24(%rbp)

#.t8 = .t6 + .t7
movq -16(%rbp), %r13
movq -24(%rbp), %r14
addq %r13, %r14
movq %r14, -32(%rbp)

#.t9 = 2
movq $2, -40(%rbp)

#.t10 = .t8 - .t9
movq -32(%rbp), %r13
movq -40(%rbp), %r14
subq %r14, %r13
movq %r13, -48(%rbp)

#x = .t10
movq -48(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t11 = "\nResult of expression 2:"
movq $.str2, %r13
movq %r13, -64(%rbp)

#print, .t11 str 
mov -64(%rbp), %rax
mov %rax, %rsi
movq -64(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t12 = 3
movq $3, -72(%rbp)

#.t13 = 4
movq $4, -80(%rbp)

#.t14 = .t12 * .t13
movq -72(%rbp), %r13
movq -80(%rbp), %r14
imulq %r13, %r14
movq %r14, -88(%rbp)

#.t15 = 2
movq $2, -96(%rbp)

#.t16 = .t14 - .t15
movq -88(%rbp), %r13
movq -96(%rbp), %r14
subq %r14, %r13
movq %r13, -104(%rbp)

#x = .t16
movq -104(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t17 = "\nResult of expression 3:"
movq $.str3, %r13
movq %r13, -112(%rbp)

#print, .t17 str 
mov -112(%rbp), %rax
mov %rax, %rsi
movq -112(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t18 = 10
movq $10, -120(%rbp)

#.t19 = 2
movq $2, -128(%rbp)

#.t20 = .t18 / .t19
movq -120(%rbp), %rax
movq -128(%rbp), %r14
cqto
idivq %r14
movq %rax, -136(%rbp)

#.t21 = 5
movq $5, -144(%rbp)

#.t22 = .t20 / .t21
movq -136(%rbp), %rax
movq -144(%rbp), %r14
cqto
idivq %r14
movq %rax, -152(%rbp)

#x = .t22
movq -152(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t23 = "\nResult of expression 4:"
movq $.str4, %r13
movq %r13, -160(%rbp)

#print, .t23 str 
mov -160(%rbp), %rax
mov %rax, %rsi
movq -160(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t24 = 2
movq $2, -168(%rbp)

#.t25 = 3
movq $3, -176(%rbp)

#.t26 = 2
movq $2, -184(%rbp)

#.t27 = .t25 ** .t26
movq -176(%rbp), %r13
movq -184(%rbp), %r14
movq %r13, %rax
movq %r14, %rcx
xor %rdx, %rdx
movq $1, %rdx
cmpq $0, %rcx
je .label1
.label1:
imul %rax, %rdx
dec %rcx
cmpq $0, %rcx
jne .label1
movq %rdx, -192(%rbp)

#.t28 = .t24 ** .t27
movq -168(%rbp), %r13
movq -192(%rbp), %r14
movq %r13, %rax
movq %r14, %rcx
xor %rdx, %rdx
movq $1, %rdx
cmpq $0, %rcx
je .label2
.label2:
imul %rax, %rdx
dec %rcx
cmpq $0, %rcx
jne .label2
movq %rdx, -200(%rbp)

#x = .t28
movq -200(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t29 = "\nResult of expression 5:"
movq $.str5, %r13
movq %r13, -208(%rbp)

#print, .t29 str 
mov -208(%rbp), %rax
mov %rax, %rsi
movq -208(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t30 = 2
movq $2, -216(%rbp)

#.t31 = 3
movq $3, -224(%rbp)

#.t32 = 4
movq $4, -232(%rbp)

#.t33 = .t31 * .t32
movq -224(%rbp), %r13
movq -232(%rbp), %r14
imulq %r13, %r14
movq %r14, -240(%rbp)

#.t34 = .t30 + .t33
movq -216(%rbp), %r13
movq -240(%rbp), %r14
addq %r13, %r14
movq %r14, -248(%rbp)

#x = .t34
movq -248(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t35 = "\nResult of expression 6:"
movq $.str6, %r13
movq %r13, -256(%rbp)

#print, .t35 str 
mov -256(%rbp), %rax
mov %rax, %rsi
movq -256(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t36 = 2
movq $2, -264(%rbp)

#.t37 = 3
movq $3, -272(%rbp)

#.t38 = .t36 + .t37
movq -264(%rbp), %r13
movq -272(%rbp), %r14
addq %r13, %r14
movq %r14, -280(%rbp)

#.t39 = 4
movq $4, -288(%rbp)

#.t40 = .t38 * .t39
movq -280(%rbp), %r13
movq -288(%rbp), %r14
imulq %r13, %r14
movq %r14, -296(%rbp)

#x = .t40
movq -296(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t41 = "\nResult of expression 7:"
movq $.str7, %r13
movq %r13, -304(%rbp)

#print, .t41 str 
mov -304(%rbp), %rax
mov %rax, %rsi
movq -304(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t42 = 10
movq $10, -312(%rbp)

#.t43 = 5
movq $5, -320(%rbp)

#.t44 = .t42 - .t43
movq -312(%rbp), %r13
movq -320(%rbp), %r14
subq %r14, %r13
movq %r13, -328(%rbp)

#.t45 = 3
movq $3, -336(%rbp)

#.t46 = .t44 + .t45
movq -328(%rbp), %r13
movq -336(%rbp), %r14
addq %r13, %r14
movq %r14, -344(%rbp)

#x = .t46
movq -344(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t47 = "\nResult of expression 8:"
movq $.str8, %r13
movq %r13, -352(%rbp)

#print, .t47 str 
mov -352(%rbp), %rax
mov %rax, %rsi
movq -352(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

#.t48 = 8
movq $8, -360(%rbp)

#.t49 = 5
movq $5, -368(%rbp)

#.t50 = .t48 % .t49
movq -360(%rbp), %rax
movq -368(%rbp), %r14
cqto
idivq %r14
movq %rdx, -376(%rbp)

#.t51 = 2
movq $2, -384(%rbp)

#.t52 = .t50 % .t51
movq -376(%rbp), %rax
movq -384(%rbp), %r14
cqto
idivq %r14
movq %rdx, -392(%rbp)

#x = .t52
movq -392(%rbp), %r13
movq %r13, -56(%rbp)

#print, x int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -400(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -400(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
