.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str1:
        .string "Fibonacci test passed\n"
        .text
.str2:
        .string "Fibonacci test failed\n"
        .text
.str3:
        .string "Fibonacci test passed\n"
        .text
.str4:
        .string "Fibonacci test failed\n"
        .text
.global main

#fibonacci:   
fibonacci:
pushq %rbp
movq %rsp, %rbp
subq $128, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) n 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t1 = 0
movq $0, -24(%rbp)

#.t2 = n <= .t1
movq -8(%rbp), %r13
movq -24(%rbp), %r14
cmpq %r13, %r14
setge %al
movzbq %al, %r14
movq %r14, -32(%rbp)

#if_false .t2 goto .label2
mov -32(%rbp), %rax
cmp $0, %rax
je .label2

#.t3 = 0
movq $0, -40(%rbp)

#move8 .t3 %rax 
movq -40(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $128, %rsp
popq %rbp
movq $8, %r13
ret

#goto .label1  
jmp .label1

#.label2:   
.label2:

#.t4 = 1
movq $1, -56(%rbp)

#.t5 = n == .t4
movq -8(%rbp), %r13
movq -56(%rbp), %r14
cmpq %r13, %r14
sete %al
movzbq %al, %r14
movq %r14, -64(%rbp)

#if_false .t5 goto .label3
mov -64(%rbp), %rax
cmp $0, %rax
je .label3

#.t6 = 1
movq $1, -72(%rbp)

#move8 .t6 %rax 
movq -72(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $128, %rsp
popq %rbp
movq $8, %r13
ret

#goto .label1  
jmp .label1

#.label3:   
.label3:

#.t7 = 1
movq $1, -80(%rbp)

#.t8 = n - .t7
movq -8(%rbp), %r13
movq -80(%rbp), %r14
subq %r14, %r13
movq %r13, -88(%rbp)

##callnew   
movq %rsp, -136(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t8  
pushq -88(%rbp)

#call, fibonacci  
call fibonacci
addq %r13, %rsp
movq -136(%rbp), %rsp

#move8 %rax .t9 
movq %rax, %r13
movq %r13, -96(%rbp)

#.t10 = 2
movq $2, -104(%rbp)

#.t11 = n - .t10
movq -8(%rbp), %r13
movq -104(%rbp), %r14
subq %r14, %r13
movq %r13, -112(%rbp)

##callnew   
movq %rsp, -136(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t11  
pushq -112(%rbp)

#call, fibonacci  
call fibonacci
addq %r13, %rsp
movq -136(%rbp), %rsp

#move8 %rax .t12 
movq %rax, %r13
movq %r13, -120(%rbp)

#.t13 = .t9 + .t12
movq -96(%rbp), %r13
movq -120(%rbp), %r14
addq %r13, %r14
movq %r14, -128(%rbp)

#move8 .t13 %rax 
movq -128(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $128, %rsp
popq %rbp
movq $8, %r13
ret

#.label1:   
.label1:

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $200, %rsp

#.t14 = 9
movq $9, -8(%rbp)

##callnew   
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t14  
pushq -8(%rbp)

#call, fibonacci  
call fibonacci
addq %r13, %rsp
movq -200(%rbp), %rsp

#move8 %rax .t15 
movq %rax, %r13
movq %r13, -16(%rbp)

#fib_number1 = .t15
movq -16(%rbp), %r13
movq %r13, -32(%rbp)

#.t16 = 10
movq $10, -40(%rbp)

##callnew   
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t16  
pushq -40(%rbp)

#call, fibonacci  
call fibonacci
addq %r13, %rsp
movq -200(%rbp), %rsp

#move8 %rax .t17 
movq %rax, %r13
movq %r13, -48(%rbp)

#fib_number2 = .t17
movq -48(%rbp), %r13
movq %r13, -56(%rbp)

#.t18 = 11
movq $11, -64(%rbp)

##callnew   
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t18  
pushq -64(%rbp)

#call, fibonacci  
call fibonacci
addq %r13, %rsp
movq -200(%rbp), %rsp

#move8 %rax .t19 
movq %rax, %r13
movq %r13, -72(%rbp)

#fib_number3 = .t19
movq -72(%rbp), %r13
movq %r13, -80(%rbp)

#print, fib_number1 int 
mov -32(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -200(%rbp), %rsp

#print, fib_number2 int 
mov -56(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -200(%rbp), %rsp

#print, fib_number3 int 
mov -80(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -200(%rbp), %rsp

#.t20 = 34
movq $34, -88(%rbp)

#.t21 = fib_number1 == .t20
movq -32(%rbp), %r13
movq -88(%rbp), %r14
cmpq %r13, %r14
sete %al
movzbq %al, %r14
movq %r14, -96(%rbp)

#.t22 = 55
movq $55, -104(%rbp)

#.t23 = fib_number2 == .t22
movq -56(%rbp), %r13
movq -104(%rbp), %r14
cmpq %r13, %r14
sete %al
movzbq %al, %r14
movq %r14, -112(%rbp)

#.t24 = 89
movq $89, -120(%rbp)

#.t25 = fib_number3 == .t24
movq -80(%rbp), %r13
movq -120(%rbp), %r14
cmpq %r13, %r14
sete %al
movzbq %al, %r14
movq %r14, -128(%rbp)

#.t26 = and .t23

#.t27 = .t21 and .t26
movq -96(%rbp), %r13
movq -136(%rbp), %r14
cmpq $0, %r13
setne %al
movzbq %al, %r13
cmpq $0, %r14
setne %al
movzbq %al, %r14
andq %r13, %r14
movq %r14, -144(%rbp)

#if_false .t27 goto .label5
mov -144(%rbp), %rax
cmp $0, %rax
je .label5

#.t28 = "Fibonacci test passed"
movq $.str1, %r13
movq %r13, -152(%rbp)

#print, .t28 str 
mov -152(%rbp), %rax
mov %rax, %rsi
movq -152(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -200(%rbp), %rsp

#goto .label4  
jmp .label4

#.label5:   
.label5:

#.t29 = "Fibonacci test failed"
movq $.str2, %r13
movq %r13, -160(%rbp)

#print, .t29 str 
mov -160(%rbp), %rax
mov %rax, %rsi
movq -160(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -200(%rbp), %rsp

#.label4:   
.label4:

#.t30 = fib_number2 + fib_number1
movq -56(%rbp), %r13
movq -32(%rbp), %r14
addq %r13, %r14
movq %r14, -168(%rbp)

#.t31 = fib_number3 == .t30
movq -80(%rbp), %r13
movq -168(%rbp), %r14
cmpq %r13, %r14
sete %al
movzbq %al, %r14
movq %r14, -176(%rbp)

#if_false .t31 goto .label7
mov -176(%rbp), %rax
cmp $0, %rax
je .label7

#.t32 = "Fibonacci test passed"
movq $.str3, %r13
movq %r13, -184(%rbp)

#print, .t32 str 
mov -184(%rbp), %rax
mov %rax, %rsi
movq -184(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -200(%rbp), %rsp

#goto .label6  
jmp .label6

#.label7:   
.label7:

#.t33 = "Fibonacci test failed"
movq $.str4, %r13
movq %r13, -192(%rbp)

#print, .t33 str 
mov -192(%rbp), %rax
mov %rax, %rsi
movq -192(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -200(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -200(%rbp), %rsp

#.label6:   
.label6:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
