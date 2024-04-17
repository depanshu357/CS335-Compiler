.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str1:
        .string "Hello\n"
        .text
.str2:
        .string "Hello\n"
        .text
.str3:
        .string "True\n"
        .text
.str4:
        .string "False\n"
        .text
.global main

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp

#.t1 = "Hello"
movq $.str1, %r13
movq %r13, -8(%rbp)

#.t2 = "Hello"
movq $.str2, %r13
movq %r13, -16(%rbp)

#.t3 = .t1 > .t2
# comparison of strings
movq -8(%rbp), %rdi
movq -16(%rbp), %rsi
call strcmp@PLT
cmp $1, %eax
sete %al
movzbq %al, %r14
movq %r14, -24(%rbp)

#x = .t3
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

#if_false x goto .label2
mov -32(%rbp), %rax
cmp $0, %rax
je .label2

#.t4 = "True"
movq $.str3, %r13
movq %r13, -40(%rbp)

#print, .t4 str 
mov -40(%rbp), %rax
mov %rax, %rsi
movq -40(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -56(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -56(%rbp), %rsp

#goto .label1  
jmp .label1

#.label2:   
.label2:

#.t5 = "False"
movq $.str4, %r13
movq %r13, -48(%rbp)

#print, .t5 str 
mov -48(%rbp), %rax
mov %rax, %rsi
movq -48(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -56(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -56(%rbp), %rsp

#.label1:   
.label1:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
