.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str0:
        .string "Hello World\n"
        .text
.str16:
        .string "Hello\n"
        .text
.str8:
        .string "Hello World\n"
        .text
.global main

#func:   
func:
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

#move8 16(%rbp) x 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#print, x str 
mov -8(%rbp), %rax
mov %rax, %rsi
movq -8(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -24(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -24(%rbp), %rsp

#.t1 = "Hello"
movq $.str0, %r13
movq %r13, -16(%rbp)

#move8 .t1 %rax 
movq -16(%rbp), %rax

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

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp

#.t2 = "Hello World"
movq $.str0, %r13
movq %r13, -8(%rbp)

#x = .t2
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

##callnew   
movq %rsp, -40(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push x  
pushq -16(%rbp)

#call, func  
call func
addq %r13, %rsp
movq -40(%rbp), %rsp

#move8 %rax .t3 
movq %rax, -24(%rbp)

#y = .t3
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

#print, y str 
mov -32(%rbp), %rax
mov %rax, %rsi
movq -32(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -40(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -40(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
