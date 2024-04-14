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
        .string "Hello World\n"
        .text
.str8:
        .string "Hello World\n"
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
leaq .str8(%rip), %rax
mov %rax, %rdi
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

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp

#.t1 = "Hello World"
movq $.str0, %r13
movq %r13, -8(%rbp)

#x = .t1
movq -8(%rbp), %r13
movq %r13, -16(%rbp)

#print, x str 
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

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
