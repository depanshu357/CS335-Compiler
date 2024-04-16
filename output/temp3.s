.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str1:
        .string "He\n"
        .text
.str2:
        .string "Hd\n"
        .text
.global main

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp

#.t1 = "He"
movq $.str1, %r13
movq %r13, -8(%rbp)

#.t2 = "Hd"
movq $.str2, %r13
movq %r13, -16(%rbp)

#.t3 = .t1 < .t2
movq -8(%rbp), %r13
movq -16(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -24(%rbp)

#x = .t3
movq -24(%rbp), %r13
movq %r13, -32(%rbp)

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
