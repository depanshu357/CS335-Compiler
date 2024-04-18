.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str1:
        .string "omphoo\n"
        .text
.str2:
        .string "b\n"
        .text
.str3:
        .string "a\n"
        .text
.global main

#ompho___init__:   
ompho___init__:
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

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t1 = self + 0
movq -8(%rbp), %r13
movq $0, %r14
addq %r13, %r14
movq %r14, -24(%rbp)

#.t2 = 1
movq $1, -32(%rbp)

#move8 .t2 .t1[0] 
movq -24(%rbp), %r10
movq $0, %r11
movq -32(%rbp), %r13
movq %r13, ( %r10, %r11 )

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

#ompho_say_my_name:   
ompho_say_my_name:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t3 = "omphoo"
movq $.str1, %r13
movq %r13, -24(%rbp)

#move8 .t3 %rax 
movq -24(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $32, %rsp
popq %rbp
movq $8, %r13
ret

#foo___init__:   
foo___init__:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t5 = self + 0
movq -8(%rbp), %r13
movq $0, %r14
addq %r13, %r14
movq %r14, -24(%rbp)

#.t6 = 1
movq $1, -32(%rbp)

#.t5 = .t4
movq (%rbp), %r13
movq %r13, -24(%rbp)

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $32, %rsp
popq %rbp
movq $8, %r13
ret

#foo_sub:   
foo_sub:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#move8 24(%rbp) a 
movq 24(%rbp), %r13
movq %r13, -16(%rbp)

#move8 32(%rbp) b 
movq 32(%rbp), %r13
movq %r13, -24(%rbp)

#.t7 = a - b
movq -16(%rbp), %r13
movq -24(%rbp), %r14
subq %r14, %r13
movq %r13, -56(%rbp)

#move8 .t7 %rax 
movq -56(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $64, %rsp
popq %rbp
movq $24, %r13
ret

#klass___init__:   
klass___init__:
pushq %rbp
movq %rsp, %rbp
subq $72, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#move8 24(%rbp) x 
movq 24(%rbp), %r13
movq %r13, -32(%rbp)

#.t9 = self + 0
movq -8(%rbp), %r13
movq $0, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t10 = 1
movq $1, -48(%rbp)

#.t9 = .t8
movq (%rbp), %r13
movq %r13, -40(%rbp)

#.t11 = self + 8
movq -8(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -56(%rbp)

#.t12 = 2
movq $2, -64(%rbp)

#move8 .t12 .t11[0] 
movq -56(%rbp), %r10
movq $0, %r11
movq -64(%rbp), %r13
movq %r13, ( %r10, %r11 )

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $72, %rsp
popq %rbp
movq $16, %r13
ret

#klass_add:   
klass_add:
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

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t13 = self + 0
movq -8(%rbp), %r13
movq $0, %r14
addq %r13, %r14
movq %r14, -24(%rbp)

#.t14 = self + 8
movq -8(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -32(%rbp)

#.t15 = .t13[0] + .t14[0]
movq -24(%rbp), %r10
movq $0, %r11
movq -32(%rbp), %r12
movq $0, %r15
movq ( %r10, %r11 ), %r13
movq ( %r12, %r15 ), %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#x = .t15
movq -40(%rbp), %r13
movq %r13, -48(%rbp)

#print, x int 
mov -48(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -56(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -56(%rbp), %rsp

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

#temp___init__:   
temp___init__:
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

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#move8 24(%rbp) x 
movq 24(%rbp), %r13
movq %r13, -32(%rbp)

#.t16 = self + 0
movq -8(%rbp), %r13
movq $0, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#move8 x .t16[0] 
movq -40(%rbp), %r10
movq $0, %r11
movq -32(%rbp), %r13
movq %r13, ( %r10, %r11 )

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
movq $16, %r13
ret

#temp_sub:   
temp_sub:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) self 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#.t17 = self + 0
movq -8(%rbp), %r13
movq $0, %r14
addq %r13, %r14
movq %r14, -16(%rbp)

#print, .t17[0] int 
movq -16(%rbp), %r8
movq $0, %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -32(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -32(%rbp), %rsp

#.t18 = 3
movq $3, -24(%rbp)

#move8 .t18 %rax 
movq -24(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $24, %rsp
popq %rbp
movq $8, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $160, %rsp

#.t20 = 123
movq $123, -8(%rbp)

##callnew   
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t20  
pushq -8(%rbp)

#.t19 = alloc_mem(8) 
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $8, %rdi
call malloc@plt
movq -160(%rbp), %rsp
movq %rax, -16(%rbp)

#push .t19  
pushq -16(%rbp)

#call, temp___init__  
call temp___init__
addq %r13, %rsp
movq -160(%rbp), %rsp

#z = .t19
movq -16(%rbp), %r13
movq %r13, -24(%rbp)

#.t22 = 2
movq $2, -32(%rbp)

##callnew   
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t22  
pushq -32(%rbp)

#.t21 = alloc_mem(16) 
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $16, %rdi
call malloc@plt
movq -160(%rbp), %rsp
movq %rax, -40(%rbp)

#push .t21  
pushq -40(%rbp)

#call, klass___init__  
call klass___init__
addq %r13, %rsp
movq -160(%rbp), %rsp

#k = .t21
movq -40(%rbp), %r13
movq %r13, -48(%rbp)

##callnew   
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push z  
pushq -24(%rbp)

#call, temp_sub  
call temp_sub
addq %r13, %rsp
movq -160(%rbp), %rsp

#move8 %rax w 
movq %rax, %r13
movq %r13, -64(%rbp)

#.t24 = 102
movq $102, -72(%rbp)

#.t25 = 33
movq $33, -80(%rbp)

##callnew   
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t25  
pushq -80(%rbp)

#push .t24  
pushq -72(%rbp)

#push k  
pushq -48(%rbp)

#call, foo_sub  
call foo_sub
addq %r13, %rsp
movq -160(%rbp), %rsp

#move8 %rax m 
movq %rax, %r13
movq %r13, -88(%rbp)

##callnew   
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push k  
pushq -48(%rbp)

#call, ompho_say_my_name  
call ompho_say_my_name
addq %r13, %rsp
movq -160(%rbp), %rsp

#move8 %rax l 
movq %rax, %r13
movq %r13, -96(%rbp)

#print, m int 
mov -88(%rbp), %rax
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

#.t28 = "b"
movq $.str2, %r13
movq %r13, -104(%rbp)

#a = .t28
movq -104(%rbp), %r13
movq %r13, -112(%rbp)

#.t29 = "a"
movq $.str3, %r13
movq %r13, -120(%rbp)

#b = .t29
movq -120(%rbp), %r13
movq %r13, -128(%rbp)

#.t30 = a == b
# comparison of strings
movq -112(%rbp), %rdi
movq -128(%rbp), %rsi
call strcmp@PLT
cmpq $0, %rax
sete %al
movzbq %al, %r14
movq %r14, -136(%rbp)

#print, .t30 int 
mov -136(%rbp), %rax
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

#.t31 = a > b
# comparison of strings
movq -112(%rbp), %rdi
movq -128(%rbp), %rsi
call strcmp@PLT
cmp $1, %eax
sete %al
movzbq %al, %r14
movq %r14, -144(%rbp)

#print, .t31 int 
mov -144(%rbp), %rax
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

#.t32 = a < b
# comparison of strings
movq -112(%rbp), %rdi
movq -128(%rbp), %rsi
call strcmp@PLT
test %eax, %eax
setl %al
movzbq %al, %r14
movq %r14, -152(%rbp)

#print, .t32 int 
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

#print, l str 
mov -96(%rbp), %rax
mov %rax, %rsi
movq -96(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -160(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -160(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
