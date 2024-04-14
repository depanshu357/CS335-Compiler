.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str:
        .string "\n"
        .text
.str0:
        .string "\n"
        .text
.str104:
        .string "\n"
        .text
.str112:
        .string "\n"
        .text
.str120:
        .string "\n"
        .text
.str16:
        .string "\n"
        .text
.str24:
        .string "\n"
        .text
.str32:
        .string "\n"
        .text
.str40:
        .string "\n"
        .text
.str48:
        .string "\n"
        .text
.str56:
        .string "\n"
        .text
.str64:
        .string "\n"
        .text
.str72:
        .string "\n"
        .text
.str8:
        .string "\n"
        .text
.str80:
        .string "\n"
        .text
.str88:
        .string "\n"
        .text
.str96:
        .string "\n"
        .text
.global main

#temp:   
temp:
pushq %rbp
movq %rsp, %rbp
subq $48, %rsp
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

#.t1 = 7
movq $7, -16(%rbp)

#.t3 = .t1 * 8
movq -16(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -24(%rbp)

#i = a[.t3]
movq -8(%rbp), %r10
movq -24(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -32(%rbp)

#.t4 = 8
movq $8, -40(%rbp)

#.t6 = .t4 * 8
movq -40(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -48(%rbp)

#move8 a[.t6] %rax 
movq -8(%rbp), %r8
movq -48(%rbp), %r9
movq ( %r8, %r9 ), %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $48, %rsp
popq %rbp
movq $8, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $128, %rsp

#.t7 = 10
movq $10, -8(%rbp)

#.t8 = 9
movq $9, -16(%rbp)

#.t9 = 8
movq $8, -24(%rbp)

#.t10 = 7
movq $7, -32(%rbp)

#.t11 = 6
movq $6, -40(%rbp)

#.t12 = 5
movq $5, -48(%rbp)

#.t13 = 4
movq $4, -56(%rbp)

#.t14 = 3
movq $3, -64(%rbp)

#.t15 = 2
movq $2, -72(%rbp)

#.t16 = 1
movq $1, -80(%rbp)

#.t17 = alloc_mem(88) 
movq %rsp, -128(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $88, %rdi
call malloc@plt
movq -128(%rbp), %rsp
movq %rax, -96(%rbp)

#.t18 = 0
movq $0, -88(%rbp)

#.t17[.t18] = 10 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq $10, %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t7 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -8(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t8 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -16(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t9 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -24(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t10 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -32(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t11 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -40(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t12 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -48(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t13 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -56(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t14 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -64(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t15 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -72(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17[.t18] = .t16 
movq -96(%rbp), %r13
movq -88(%rbp), %r14
movq -80(%rbp), %r15
movq %r15, (%r13, %r14)

#.t18 = .t18 + 8
movq -88(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -88(%rbp)

#.t17 = .t17 + 8
movq -96(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -96(%rbp)

#data = .t17
movq -96(%rbp), %r13
movq %r13, -104(%rbp)

##callnew   
movq %rsp, -128(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push data  
pushq -104(%rbp)

#call, temp  
call temp
addq %r13, %rsp
movq -128(%rbp), %rsp

#move8 %rax .t19 
movq %rax, -112(%rbp)

#i = .t19
movq -112(%rbp), %r13
movq %r13, -120(%rbp)

#print, i int 
mov -120(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -128(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -128(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
