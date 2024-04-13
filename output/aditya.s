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
subq $112, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) a 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t1 = 0
movq $0, -16(%rbp)

#.t2 = a == .t1
movq -8(%rbp), %r13
movq -16(%rbp), %r14
cmpq %r13, %r14
sete %al
movzbq %al, %r14
movq %r14, -24(%rbp)

#if_false .t2 goto .label2
mov -24(%rbp), %rax
cmp $0, %rax
je .label2

#.t3 = 1
movq $1, -32(%rbp)

#move8 .t3 %rax 
movq -32(%rbp), %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $112, %rsp
popq %rbp
movq $8, %r13
ret

#goto .label1  
jmp .label1

#.label2:   
.label2:

#.label1:   
.label1:

#.t4 = 1
movq $1, -40(%rbp)

#.t5 = a == .t4
movq -8(%rbp), %r13
movq -40(%rbp), %r14
cmpq %r13, %r14
sete %al
movzbq %al, %r14
movq %r14, -48(%rbp)

#if_false .t5 goto .label4
mov -48(%rbp), %rax
cmp $0, %rax
je .label4

#.t6 = 1
movq $1, -56(%rbp)

#move8 .t6 %rax 
movq -56(%rbp), %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $112, %rsp
popq %rbp
movq $8, %r13
ret

#goto .label3  
jmp .label3

#.label4:   
.label4:

#.label3:   
.label3:

#.t7 = 1
movq $1, -64(%rbp)

#.t8 = a - .t7
movq -8(%rbp), %r13
movq -64(%rbp), %r14
subq %r14, %r13
movq %r13, -72(%rbp)

#push .t8  
pushq -72(%rbp)

#call, temp  
call temp
addq %r13, %rsp

#move8 %rax .t9 
movq %rax, -80(%rbp)

#.t10 = 2
movq $2, -88(%rbp)

#.t11 = a - .t10
movq -8(%rbp), %r13
movq -88(%rbp), %r14
subq %r14, %r13
movq %r13, -96(%rbp)

#push .t11  
pushq -96(%rbp)

#call, temp  
call temp
addq %r13, %rsp

#move8 %rax .t12 
movq %rax, -104(%rbp)

#.t13 = .t9 + .t12
movq -80(%rbp), %r13
movq -104(%rbp), %r14
addq %r13, %r14
movq %r14, -112(%rbp)

#move8 .t13 %rax 
movq -112(%rbp), %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $112, %rsp
popq %rbp
movq $8, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

#.t14 = 123
movq $123, -8(%rbp)

#i = .t14
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

#print, i  
mov -16(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
call printf@plt

#.t15 = 5
movq $5, -24(%rbp)

#push .t15  
pushq -24(%rbp)

#call, temp  
call temp
addq %r13, %rsp

#move8 %rax .t16 
movq %rax, -32(%rbp)

#i = .t16
movq -32(%rbp), %r13
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
syscall#.t12 = 0
movq $0, -88(%rbp)

#.t11[.t12] = 10 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq $10, %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t1 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -8(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t2 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -16(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t3 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -24(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t4 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -32(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t5 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -40(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t6 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -48(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t7 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -56(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t8 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -64(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t9 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -72(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11[.t12] = .t10 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -80(%rbp), %r15
movq %r15, (%r13, %r14)

#.t12 = .t12 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t11 = .t11 + 8
movq -96(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -96(%rbp)

#data = .t11
movq -96(%rbp), %r13
movq %r13, -104(%rbp)

#.t13 = 0
movq $0, -112(%rbp)

#.t15 = .t13 * 8
movq -112(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -120(%rbp)

#i = data[.t15]
movq -104(%rbp), %r13
movq -120(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -128(%rbp)

#.t16 = 1
movq $1, -136(%rbp)

#.t18 = .t16 * 8
movq -136(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -144(%rbp)

#j = data[.t18]
movq -104(%rbp), %r13
movq -144(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -152(%rbp)

#.t19 = 2
movq $2, -160(%rbp)

#.t21 = .t19 * 8
movq -160(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -168(%rbp)

#k = data[.t21]
movq -104(%rbp), %r13
movq -168(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -176(%rbp)

#.t22 = 3
movq $3, -184(%rbp)

#.t24 = .t22 * 8
movq -184(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -192(%rbp)

#l = data[.t24]
movq -104(%rbp), %r13
movq -192(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -200(%rbp)

#.t25 = 4
movq $4, -208(%rbp)

#.t27 = .t25 * 8
movq -208(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -216(%rbp)

#m = data[.t27]
movq -104(%rbp), %r13
movq -216(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -224(%rbp)

#.t28 = 5
movq $5, -232(%rbp)

#.t30 = .t28 * 8
movq -232(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -240(%rbp)

#n = data[.t30]
movq -104(%rbp), %r13
movq -240(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -248(%rbp)

#.t31 = 6
movq $6, -256(%rbp)

#.t33 = .t31 * 8
movq -256(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -264(%rbp)

#o = data[.t33]
movq -104(%rbp), %r13
movq -264(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -272(%rbp)

#.t34 = 7
movq $7, -280(%rbp)

#.t36 = .t34 * 8
movq -280(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -288(%rbp)

#p = data[.t36]
movq -104(%rbp), %r13
movq -288(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -296(%rbp)

#.t37 = 8
movq $8, -304(%rbp)

#.t39 = .t37 * 8
movq -304(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -312(%rbp)

#q = data[.t39]
movq -104(%rbp), %r13
movq -312(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -320(%rbp)

#.t40 = 9
movq $9, -328(%rbp)

#.t42 = .t40 * 8
movq -328(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -336(%rbp)

#r = data[.t42]
movq -104(%rbp), %r13
movq -336(%rbp), %r14
movq (%r13, %r14), %r15
movq %r15, -344(%rbp)

#print, i int 
mov -128(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, j int 
mov -152(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, k int 
mov -176(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, l int 
mov -200(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, m int 
mov -224(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, n int 
mov -248(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, o int 
mov -272(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, p int 
mov -296(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, q int 
mov -320(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

#print, r int 
mov -344(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
