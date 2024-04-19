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
subq $96, %rsp

#.t1 = 1
movq $1, -8(%rbp)

#.t2 = 2
movq $2, -16(%rbp)

#.t3 = 3
movq $3, -24(%rbp)

#.t4 = alloc_mem(32) 
movq %rsp, -96(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $32, %rdi
call malloc@plt
movq -96(%rbp), %rsp
movq %rax, -32(%rbp)

#.t5 = 0
movq $0, -40(%rbp)

#.t4[.t5] = 3
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq $3, ( %r8, %r9 )

#.t5 = .t5 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t4[.t5] = .t1
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -8(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t5 = .t5 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t4[.t5] = .t2
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -16(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t5 = .t5 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t4[.t5] = .t3
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -24(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t5 = .t5 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t4 = .t4 + 8
movq -32(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -32(%rbp)

#arr = .t4
movq -32(%rbp), %r13
movq %r13, -56(%rbp)

#.t6 = -8
movq $-8, %r13
movq %r13, -64(%rbp)

#.t7 = arr[.t6]
movq -56(%rbp), %r10
movq -64(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -72(%rbp)

#.t7 = .t7 * 8
movq -72(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -72(%rbp)

#.label2:   
.label2:

#.t6 = .t6 + 8
movq -64(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -64(%rbp)

#.t8 = .t6 < .t7
movq -64(%rbp), %r13
movq -72(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -80(%rbp)

#if_false .t8 goto .label1
mov -80(%rbp), %rax
cmp $0, %rax
je .label1

#i = arr[.t6]
movq -56(%rbp), %r10
movq -64(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -88(%rbp)

#print, i int 
mov -88(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -96(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -96(%rbp), %rsp

#goto .label2  
jmp .label2

#.label1:   
.label1:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
