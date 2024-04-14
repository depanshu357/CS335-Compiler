.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str0:
        .string "Hello\n"
        .text
.str104:
        .string "Hello\n"
        .text
.str112:
        .string "Hello\n"
        .text
.str120:
        .string "Hello\n"
        .text
.str144:
        .string "Hello\n"
        .text
.str152:
        .string "Hello\n"
        .text
.str16:
        .string "Hello\n"
        .text
.str24:
        .string "Hello\n"
        .text
.str32:
        .string "Hello\n"
        .text
.str40:
        .string "Hello\n"
        .text
.str48:
        .string "Hello\n"
        .text
.str56:
        .string "Hello\n"
        .text
.str64:
        .string "Hello\n"
        .text
.str72:
        .string "Hello\n"
        .text
.str8:
        .string "Hello\n"
        .text
.str80:
        .string "Hello\n"
        .text
.str88:
        .string "Hello\n"
        .text
.str96:
        .string "Hello\n"
        .text
.global main

#foo___init__:   
foo___init__:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp
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
movq %r14, -16(%rbp)

#.t2 = 1
movq $1, -24(%rbp)

#move8 .t2 .t1 
movq -24(%rbp), %r13
movq %r13, -16(%rbp)

#.t3 = self + 8
movq -8(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -32(%rbp)

#.t4 = 1
movq $1, -40(%rbp)

#move8 .t4 .t3 
movq -40(%rbp), %r13
movq %r13, -32(%rbp)

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $40, %rsp
popq %rbp
movq $8, %r13
ret

#foo_prit:   
foo_prit:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
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

#.t5 = "Hello"
movq (%rbp), %r13
movq %r13, -16(%rbp)

#print, .t5 str 
mov -16(%rbp), %rax
mov %rax, %rsi
leaq .str16(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -24(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -24(%rbp), %rsp

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $16, %rsp
popq %rbp
movq $8, %r13
ret

#foo_temp:   
foo_temp:
pushq %rbp
movq %rsp, %rbp
subq $152, %rsp
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

#move8 24(%rbp) a 
movq 24(%rbp), %r13
movq %r13, -16(%rbp)

#.t6 = 10
movq $10, -24(%rbp)

#.t7 = 9
movq $9, -32(%rbp)

#.t8 = 8
movq $8, -40(%rbp)

#.t9 = 7
movq $7, -48(%rbp)

#.t10 = 6
movq $6, -56(%rbp)

#.t11 = 5
movq $5, -64(%rbp)

#.t12 = 4
movq $4, -72(%rbp)

#.t13 = 3
movq $3, -80(%rbp)

#.t14 = 2
movq $2, -88(%rbp)

#.t15 = 1
movq $1, -96(%rbp)

#.t16 = alloc_mem(88) 
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $88, %rdi
call malloc@plt
movq -160(%rbp), %rsp
movq %rax, -112(%rbp)

#.t17 = 0
movq $0, -104(%rbp)

#.t16[.t17] = 10 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq $10, %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t6 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -24(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t7 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -32(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t8 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -40(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t9 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -48(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t10 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -56(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t11 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -64(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t12 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -72(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t13 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -80(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t14 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -88(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16[.t17] = .t15 
movq -112(%rbp), %r13
movq -104(%rbp), %r14
movq -96(%rbp), %r15
movq %r15, (%r13, %r14)

#.t17 = .t17 + 8
movq -104(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -104(%rbp)

#.t16 = .t16 + 8
movq -112(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -112(%rbp)

#data = .t16
movq -112(%rbp), %r13
movq %r13, -120(%rbp)

#.t19 = a * 8
movq -16(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -128(%rbp)

#.t21 = a * 8
movq -16(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -136(%rbp)

#.t22 = data[.t19] * data[.t21]
movq -120(%rbp), %r10
movq -128(%rbp), %r11
movq -120(%rbp), %r12
movq -136(%rbp), %r15
movq ( %r10, %r11 ), %r13
movq ( %r12, %r15 ), %r14
imulq %r13, %r14
movq %r14, -144(%rbp)

#i = .t22
movq -144(%rbp), %r13
movq %r13, -152(%rbp)

#print, i int 
mov -152(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -160(%rbp), %rsp

#move8 i %rax 
movq -152(%rbp), %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $152, %rsp
popq %rbp
movq $16, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp

##callnew   
movq %rsp, -24(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#.t23 = alloc_mem(16) 
movq %rsp, -24(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $16, %rdi
call malloc@plt
movq -24(%rbp), %rsp
movq %rax, (%rbp)

#push .t23  
pushq (%rbp)

#call, foo___init__  
call foo___init__
addq %r13, %rsp
movq -24(%rbp), %rsp

#f = .t23
movq (%rbp), %r13
movq %r13, -8(%rbp)

##callnew   
movq %rsp, -24(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push f  
pushq -8(%rbp)

#call, foo_prit  
call foo_prit
addq %r13, %rsp
movq -24(%rbp), %rsp

#.t25 = 5
movq $5, -16(%rbp)

##callnew   
movq %rsp, -24(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t25  
pushq -16(%rbp)

#push f  
pushq -8(%rbp)

#call, foo_temp  
call foo_temp
addq %r13, %rsp
movq -24(%rbp), %rsp

#move8 %rax i 
movq %rax, (%rbp)

#print, i int 
mov (%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -24(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -24(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
