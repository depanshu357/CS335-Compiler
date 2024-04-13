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
        .string "SAB HO GAYA\n"
        .text
.str104:
        .string "\n"
        .text
.str112:
        .string "\n"
        .text
.str128:
        .string "\n"
        .text
.str144:
        .string "\n"
        .text
.str16:
        .string "\n"
        .text
.str160:
        .string "\n"
        .text
.str176:
        .string "\n"
        .text
.str192:
        .string "\n"
        .text
.str200:
        .string "\n"
        .text
.str216:
        .string "SAB HO GAYA\n"
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

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $224, %rsp

#.t1 = 10
movq $10, -8(%rbp)

#.t2 = 9
movq $9, -16(%rbp)

#.t3 = 8
movq $8, -24(%rbp)

#.t4 = 7
movq $7, -32(%rbp)

#.t5 = 6
movq $6, -40(%rbp)

#.t6 = 5
movq $5, -48(%rbp)

#.t7 = 4
movq $4, -56(%rbp)

#.t8 = 3
movq $3, -64(%rbp)

#.t9 = 2
movq $2, -72(%rbp)

#.t10 = 1
movq $1, -80(%rbp)

#.t11 = declare_array(88) 
movq %rsp, -224(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $88, %rdi
call malloc@plt
movq -224(%rbp), %rsp
movq %rax, -96(%rbp)

#.t12 = 0
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

#.t13 = 1
movq $1, -112(%rbp)

#.t15 = .t13 * 8
movq -112(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -120(%rbp)

#.t16 = 2
movq $2, -128(%rbp)

#.t18 = .t16 * 8
movq -128(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -136(%rbp)

#.t19 = 3
movq $3, -144(%rbp)

#.t21 = .t19 * 8
movq -144(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -152(%rbp)

#.t22 = data[.t18] * data[.t21]
movq -104(%rbp), %r10
movq -136(%rbp), %r11
movq -104(%rbp), %r12
movq -152(%rbp), %r15
movq ( %r10, %r11 ), %r13
movq ( %r12, %r15 ), %r14
imulq %r13, %r14
movq %r14, -160(%rbp)

#data[.t15] = .t22
movq -104(%rbp), %r8
movq -120(%rbp), %r9
movq -160(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t23 = 1
movq $1, -176(%rbp)

#.t25 = .t23 * 8
movq -176(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -184(%rbp)

#i = data[.t25]
movq -104(%rbp), %r10
movq -184(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -192(%rbp)

#print, i int 
mov -192(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -224(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -224(%rbp), %rsp

#.t26 = 1
movq $1, -200(%rbp)

#.t28 = .t26 * 8
movq -200(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -208(%rbp)

#print, data[.t28] int 
movq -104(%rbp), %r8
movq -208(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -224(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -224(%rbp), %rsp

#.t29 = "SAB HO GAYA"
movq (%rbp), %r13
movq %r13, -216(%rbp)

#print, .t29 str 
mov -216(%rbp), %rax
mov %rax, %rsi
leaq .str216(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -224(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -224(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
