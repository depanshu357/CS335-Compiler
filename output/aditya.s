.section .data
.section .text
.section .rodata
.note0:
        .string "%ld\n"
        .text
.str1:
        .string "PWI,2013\n"
        .text
.str10:
        .string "against - \n"
        .text
.str2:
        .string "SRH,2024\n"
        .text
.str3:
        .string "GL,2016\n"
        .text
.str4:
        .string "KKR, 2017\n"
        .text
.str5:
        .string "SRH, 2022\n"
        .text
.str6:
        .string "RR,2014 and CSK, 2019\n"
        .text
.str7:
        .string "IPL Stats : RCB highest runs in a match\n"
        .text
.str8:
        .string "against - \n"
        .text
.str9:
        .string "IPL Stats : RCB lowest runs in a match\n"
        .text
.global main

#highest:   
highest:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#.t1 = 263
movq $263, -8(%rbp)

#.t2 = 262
movq $262, -16(%rbp)

#.t3 = 248
movq $248, -24(%rbp)

#.t4 = alloc_mem(32) 
movq %rsp, -64(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $32, %rdi
call malloc@plt
movq -64(%rbp), %rsp
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

#move8 .t4 %rax 
movq -32(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $56, %rsp
popq %rbp
movq $0, %r13
ret

#highest_against:   
highest_against:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#.t6 = "PWI,2013"
movq $.str1, %r13
movq %r13, -8(%rbp)

#.t7 = "SRH,2024"
movq $.str2, %r13
movq %r13, -16(%rbp)

#.t8 = "GL,2016"
movq $.str3, %r13
movq %r13, -24(%rbp)

#.t9 = alloc_mem(32) 
movq %rsp, -64(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $32, %rdi
call malloc@plt
movq -64(%rbp), %rsp
movq %rax, -32(%rbp)

#.t10 = 0
movq $0, -40(%rbp)

#.t9[.t10] = 3
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq $3, ( %r8, %r9 )

#.t10 = .t10 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t9[.t10] = .t6
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -8(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t10 = .t10 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t9[.t10] = .t7
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -16(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t10 = .t10 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t9[.t10] = .t8
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -24(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t10 = .t10 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t9 = .t9 + 8
movq -32(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -32(%rbp)

#move8 .t9 %rax 
movq -32(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $56, %rsp
popq %rbp
movq $0, %r13
ret

#lowest:   
lowest:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#.t11 = 49
movq $49, -8(%rbp)

#.t12 = 68
movq $68, -16(%rbp)

#.t13 = 70
movq $70, -24(%rbp)

#.t14 = alloc_mem(32) 
movq %rsp, -64(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $32, %rdi
call malloc@plt
movq -64(%rbp), %rsp
movq %rax, -32(%rbp)

#.t15 = 0
movq $0, -40(%rbp)

#.t14[.t15] = 3
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq $3, ( %r8, %r9 )

#.t15 = .t15 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t14[.t15] = .t11
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -8(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t15 = .t15 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t14[.t15] = .t12
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -16(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t15 = .t15 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t14[.t15] = .t13
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -24(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t15 = .t15 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t14 = .t14 + 8
movq -32(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -32(%rbp)

#move8 .t14 %rax 
movq -32(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $56, %rsp
popq %rbp
movq $0, %r13
ret

#lowest_against:   
lowest_against:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#.t16 = "KKR, 2017"
movq $.str4, %r13
movq %r13, -8(%rbp)

#.t17 = "SRH, 2022"
movq $.str5, %r13
movq %r13, -16(%rbp)

#.t18 = "RR,2014 and CSK, 2019"
movq $.str6, %r13
movq %r13, -24(%rbp)

#.t19 = alloc_mem(32) 
movq %rsp, -64(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $32, %rdi
call malloc@plt
movq -64(%rbp), %rsp
movq %rax, -32(%rbp)

#.t20 = 0
movq $0, -40(%rbp)

#.t19[.t20] = 3
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq $3, ( %r8, %r9 )

#.t20 = .t20 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t19[.t20] = .t16
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -8(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t20 = .t20 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t19[.t20] = .t17
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -16(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t20 = .t20 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t19[.t20] = .t18
movq -32(%rbp), %r8
movq -40(%rbp), %r9
movq -24(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t20 = .t20 + 8
movq -40(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -40(%rbp)

#.t19 = .t19 + 8
movq -32(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -32(%rbp)

#move8 .t19 %rax 
movq -32(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $56, %rsp
popq %rbp
movq $0, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $288, %rsp

##callnew   
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, highest  
call highest
addq %r13, %rsp
movq -288(%rbp), %rsp

#move8 %rax .t21 
movq %rax, %r13
movq %r13, -8(%rbp)

#runs_highest = .t21
movq -8(%rbp), %r13
movq %r13, -24(%rbp)

##callnew   
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, highest_against  
call highest_against
addq %r13, %rsp
movq -288(%rbp), %rsp

#move8 %rax .t22 
movq %rax, %r13
movq %r13, -32(%rbp)

#runs_highest_against = .t22
movq -32(%rbp), %r13
movq %r13, -40(%rbp)

##callnew   
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, lowest  
call lowest
addq %r13, %rsp
movq -288(%rbp), %rsp

#move8 %rax .t23 
movq %rax, %r13
movq %r13, -48(%rbp)

#runs_lowest = .t23
movq -48(%rbp), %r13
movq %r13, -56(%rbp)

##callnew   
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, lowest_against  
call lowest_against
addq %r13, %rsp
movq -288(%rbp), %rsp

#move8 %rax .t24 
movq %rax, %r13
movq %r13, -64(%rbp)

#runs_lowest_against = .t24
movq -64(%rbp), %r13
movq %r13, -72(%rbp)

#.t25 = "IPL Stats : RCB highest runs in a match"
movq $.str7, %r13
movq %r13, -80(%rbp)

#print, .t25 str 
mov -80(%rbp), %rax
mov %rax, %rsi
movq -80(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t26 = 0
movq $0, -88(%rbp)

#i = .t26
movq -88(%rbp), %r13
movq %r13, -96(%rbp)

#.t27 = 0
movq $0, -104(%rbp)

#.t28 = -8
movq $-8, %r13
movq %r13, -112(%rbp)

#.t29 = runs_highest[.t28]
movq -24(%rbp), %r10
movq -112(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -120(%rbp)

#.t27 = .t27 - 1
movq -104(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -104(%rbp)

#.t30 = .t27
movq -104(%rbp), %r13
movq %r13, -128(%rbp)

#.label2:   
.label2:

#.t30 = .t30 + 1
movq -128(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -128(%rbp)

#.t31 = .t30 < .t29
movq -128(%rbp), %r13
movq -120(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -136(%rbp)

#if_false .t31 goto .label1
mov -136(%rbp), %rax
cmp $0, %rax
je .label1

#i = .t30
movq -128(%rbp), %r13
movq %r13, -96(%rbp)

#.t33 = i * 8
movq -96(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -144(%rbp)

#print, runs_highest[.t33] int 
movq -24(%rbp), %r8
movq -144(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t34 = "against - "
movq $.str8, %r13
movq %r13, -152(%rbp)

#print, .t34 str 
mov -152(%rbp), %rax
mov %rax, %rsi
movq -152(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t36 = i * 8
movq -96(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -160(%rbp)

#print, runs_highest_against[.t36] str 
movq -40(%rbp), %r8
movq -160(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
movq ( %r8, %r9 ), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t37 = 1
movq $1, -168(%rbp)

#.t38 = i + .t37
movq -96(%rbp), %r13
movq -168(%rbp), %r14
addq %r13, %r14
movq %r14, -176(%rbp)

#i = .t38
movq -176(%rbp), %r13
movq %r13, -96(%rbp)

#goto .label2  
jmp .label2

#.label1:   
.label1:

#.t39 = "IPL Stats : RCB lowest runs in a match"
movq $.str9, %r13
movq %r13, -184(%rbp)

#print, .t39 str 
mov -184(%rbp), %rax
mov %rax, %rsi
movq -184(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t40 = 0
movq $0, -192(%rbp)

#j = .t40
movq -192(%rbp), %r13
movq %r13, -200(%rbp)

#.t41 = 0
movq $0, -208(%rbp)

#.t42 = -8
movq $-8, %r13
movq %r13, -216(%rbp)

#.t43 = runs_lowest[.t42]
movq -56(%rbp), %r10
movq -216(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -224(%rbp)

#.t41 = .t41 - 1
movq -208(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -208(%rbp)

#.t44 = .t41
movq -208(%rbp), %r13
movq %r13, -232(%rbp)

#.label4:   
.label4:

#.t44 = .t44 + 1
movq -232(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -232(%rbp)

#.t45 = .t44 < .t43
movq -232(%rbp), %r13
movq -224(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -240(%rbp)

#if_false .t45 goto .label3
mov -240(%rbp), %rax
cmp $0, %rax
je .label3

#j = .t44
movq -232(%rbp), %r13
movq %r13, -200(%rbp)

#.t47 = j * 8
movq -200(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -248(%rbp)

#print, runs_lowest[.t47] int 
movq -56(%rbp), %r8
movq -248(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t48 = "against - "
movq $.str10, %r13
movq %r13, -256(%rbp)

#print, .t48 str 
mov -256(%rbp), %rax
mov %rax, %rsi
movq -256(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t50 = j * 8
movq -200(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -264(%rbp)

#print, runs_lowest_against[.t50] str 
movq -72(%rbp), %r8
movq -264(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
movq ( %r8, %r9 ), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -288(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -288(%rbp), %rsp

#.t51 = 1
movq $1, -272(%rbp)

#.t52 = j + .t51
movq -200(%rbp), %r13
movq -272(%rbp), %r14
addq %r13, %r14
movq %r14, -280(%rbp)

#j = .t52
movq -280(%rbp), %r13
movq %r13, -200(%rbp)

#goto .label4  
jmp .label4

#.label3:   
.label3:

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
