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
        .string "\n"
        .text
.str112:
        .string "Hello\n"
        .text
.str120:
        .string "Hello\n"
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
        .string "Aryan\n"
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

#func:   
func:
pushq %rbp
movq %rsp, %rbp
subq $8, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) x 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#print, x str 
mov -8(%rbp), %rax
mov %rax, %rsi
#leaq .str16(%rip), %rax
mov $.str40, %rdi
xor %rax, %rax
movq %rsp, -16(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -16(%rbp), %rsp

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $8, %rsp
popq %rbp
movq $8, %r13
ret

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $8, %rsp
popq %rbp
movq $8, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $136, %rsp

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

#.t11 = alloc_mem(88) 
movq %rsp, -136(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $88, %rdi
call malloc@plt
movq -136(%rbp), %rsp
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

#.t13 = "Hello"
movq (%rbp), %r13
movq %r13, -112(%rbp)

#i = .t13
movq -112(%rbp), %r13
movq %r13, -120(%rbp)

#print, i str 
mov -120(%rbp), %rax
mov %rax, %rsi
leaq .str120(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -136(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -136(%rbp), %rsp

##callnew   
movq %rsp, -136(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push i  
pushq -120(%rbp)

#call, func  
call func
addq %r13, %rsp
movq -136(%rbp), %rsp

#move8 %rax .t14 
movq %rax, -128(%rbp)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
