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
.str11:
        .string "CSK\n"
        .text
.str12:
        .string "DC\n"
        .text
.str13:
        .string "GL\n"
        .text
.str14:
        .string "KKR\n"
        .text
.str15:
        .string "LSG\n"
        .text
.str16:
        .string "MI\n"
        .text
.str17:
        .string "PK\n"
        .text
.str18:
        .string "RCB\n"
        .text
.str19:
        .string "RR\n"
        .text
.str2:
        .string "SRH,2024\n"
        .text
.str20:
        .string "SRH\n"
        .text
.str21:
        .string "RCB\n"
        .text
.str22:
        .string "Index of RCB in sorted array is:\n"
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

#binary_search:   
binary_search:
pushq %rbp
movq %rsp, %rbp
subq $224, %rsp
pushq %rbx
pushq %rdi
pushq %rsi
pushq %r12
pushq %r13
pushq %r14
pushq %r15

#move8 16(%rbp) arr 
movq 16(%rbp), %r13
movq %r13, -8(%rbp)

#move8 24(%rbp) x 
movq 24(%rbp), %r13
movq %r13, -16(%rbp)

#.t21 = 0
movq $0, -40(%rbp)

#low = .t21
movq -40(%rbp), %r13
movq %r13, -48(%rbp)

#.t22 = -8
movq $-8, %r13
movq %r13, -56(%rbp)

#.t23 = arr[.t22]
movq -8(%rbp), %r10
movq -56(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -64(%rbp)

#.t24 = 1
movq $1, -72(%rbp)

#.t25 = .t23 - .t24
movq -64(%rbp), %r13
movq -72(%rbp), %r14
subq %r14, %r13
movq %r13, -80(%rbp)

#high = .t25
movq -80(%rbp), %r13
movq %r13, -88(%rbp)

#.label1:   
.label1:

#.t26 = low <= high
movq -48(%rbp), %r13
movq -88(%rbp), %r14
cmpq %r13, %r14
setge %al
movzbq %al, %r14
movq %r14, -96(%rbp)

#if_false .t26 goto .label2
mov -96(%rbp), %rax
cmp $0, %rax
je .label2

#.t27 = high - low
movq -88(%rbp), %r13
movq -48(%rbp), %r14
subq %r14, %r13
movq %r13, -104(%rbp)

#.t28 = 2
movq $2, -112(%rbp)

#.t29 = .t27 // .t28
movq -104(%rbp), %rax
movq -112(%rbp), %r14
cqto
idivq %r14
movq %rax, -120(%rbp)

#.t30 = low + .t29
movq -48(%rbp), %r13
movq -120(%rbp), %r14
addq %r13, %r14
movq %r14, -128(%rbp)

#mid = .t30
movq -128(%rbp), %r13
movq %r13, -136(%rbp)

#.t32 = mid * 8
movq -136(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -144(%rbp)

#.t33 = arr[.t32] == x
# comparison of strings
movq -8(%rbp), %r10
movq -144(%rbp), %r11
movq ( %r10, %r11 ), %rdi
movq -16(%rbp), %rsi
call strcmp@PLT
cmpq $0, %rax
sete %al
movzbq %al, %r14
movq %r14, -152(%rbp)

#if_false .t33 goto .label4
mov -152(%rbp), %rax
cmp $0, %rax
je .label4

#move8 mid %rax 
movq -136(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $224, %rsp
popq %rbp
movq $16, %r13
ret

#goto .label3  
jmp .label3

#.label4:   
.label4:

#.t35 = mid * 8
movq -136(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -168(%rbp)

#.t36 = arr[.t35] < x
# comparison of strings
movq -8(%rbp), %r10
movq -168(%rbp), %r11
movq ( %r10, %r11 ), %rdi
movq -16(%rbp), %rsi
call strcmp@PLT
test %eax, %eax
setl %al
movzbq %al, %r14
movq %r14, -176(%rbp)

#if_false .t36 goto .label5
mov -176(%rbp), %rax
cmp $0, %rax
je .label5

#.t37 = 1
movq $1, -184(%rbp)

#.t38 = mid + .t37
movq -136(%rbp), %r13
movq -184(%rbp), %r14
addq %r13, %r14
movq %r14, -192(%rbp)

#low = .t38
movq -192(%rbp), %r13
movq %r13, -48(%rbp)

#goto .label3  
jmp .label3

#.label5:   
.label5:

#.t39 = 1
movq $1, -200(%rbp)

#.t40 = mid - .t39
movq -136(%rbp), %r13
movq -200(%rbp), %r14
subq %r14, %r13
movq %r13, -208(%rbp)

#high = .t40
movq -208(%rbp), %r13
movq %r13, -88(%rbp)

#.label3:   
.label3:

#goto .label1  
jmp .label1

#.label2:   
.label2:

#.t41 = 1
movq $1, -216(%rbp)

#.t42 = .t41 * -1
movq -216(%rbp), %r13
movq $-1, %r14
imulq %r13, %r14
movq %r14, -224(%rbp)

#move8 .t42 %rax 
movq -224(%rbp), %r13
movq %r13, %rax

#ret   
popq %r15
popq %r14
popq %r13
popq %r12
popq %rsi
popq %rdi
popq %rbx
addq $224, %rsp
popq %rbp
movq $16, %r13
ret

#main:   
main:
pushq %rbp
movq %rsp, %rbp
subq $432, %rsp

##callnew   
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, highest  
call highest
addq %r13, %rsp
movq -432(%rbp), %rsp

#move8 %rax .t43 
movq %rax, %r13
movq %r13, -8(%rbp)

#runs_highest = .t43
movq -8(%rbp), %r13
movq %r13, -24(%rbp)

##callnew   
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, highest_against  
call highest_against
addq %r13, %rsp
movq -432(%rbp), %rsp

#move8 %rax .t44 
movq %rax, %r13
movq %r13, -32(%rbp)

#runs_highest_against = .t44
movq -32(%rbp), %r13
movq %r13, -40(%rbp)

##callnew   
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, lowest  
call lowest
addq %r13, %rsp
movq -432(%rbp), %rsp

#move8 %rax .t45 
movq %rax, %r13
movq %r13, -48(%rbp)

#runs_lowest = .t45
movq -48(%rbp), %r13
movq %r13, -56(%rbp)

##callnew   
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#call, lowest_against  
call lowest_against
addq %r13, %rsp
movq -432(%rbp), %rsp

#move8 %rax .t46 
movq %rax, %r13
movq %r13, -64(%rbp)

#runs_lowest_against = .t46
movq -64(%rbp), %r13
movq %r13, -72(%rbp)

#.t47 = "IPL Stats : RCB highest runs in a match"
movq $.str7, %r13
movq %r13, -80(%rbp)

#print, .t47 str 
mov -80(%rbp), %rax
mov %rax, %rsi
movq -80(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t48 = 0
movq $0, -88(%rbp)

#i = .t48
movq -88(%rbp), %r13
movq %r13, -96(%rbp)

#.t49 = 0
movq $0, -104(%rbp)

#.t50 = -8
movq $-8, %r13
movq %r13, -112(%rbp)

#.t51 = runs_highest[.t50]
movq -24(%rbp), %r10
movq -112(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -120(%rbp)

#.t49 = .t49 - 1
movq -104(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -104(%rbp)

#.t52 = .t49
movq -104(%rbp), %r13
movq %r13, -128(%rbp)

#.label7:   
.label7:

#.t52 = .t52 + 1
movq -128(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -128(%rbp)

#.t53 = .t52 < .t51
movq -128(%rbp), %r13
movq -120(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -136(%rbp)

#if_false .t53 goto .label6
mov -136(%rbp), %rax
cmp $0, %rax
je .label6

#i = .t52
movq -128(%rbp), %r13
movq %r13, -96(%rbp)

#.t55 = i * 8
movq -96(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -144(%rbp)

#print, runs_highest[.t55] int 
movq -24(%rbp), %r8
movq -144(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t56 = "against - "
movq $.str8, %r13
movq %r13, -152(%rbp)

#print, .t56 str 
mov -152(%rbp), %rax
mov %rax, %rsi
movq -152(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t58 = i * 8
movq -96(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -160(%rbp)

#print, runs_highest_against[.t58] str 
movq -40(%rbp), %r8
movq -160(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
movq ( %r8, %r9 ), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t59 = 1
movq $1, -168(%rbp)

#.t60 = i + .t59
movq -96(%rbp), %r13
movq -168(%rbp), %r14
addq %r13, %r14
movq %r14, -176(%rbp)

#i = .t60
movq -176(%rbp), %r13
movq %r13, -96(%rbp)

#goto .label7  
jmp .label7

#.label6:   
.label6:

#.t61 = "IPL Stats : RCB lowest runs in a match"
movq $.str9, %r13
movq %r13, -184(%rbp)

#print, .t61 str 
mov -184(%rbp), %rax
mov %rax, %rsi
movq -184(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t62 = 0
movq $0, -192(%rbp)

#j = .t62
movq -192(%rbp), %r13
movq %r13, -200(%rbp)

#.t63 = 0
movq $0, -208(%rbp)

#.t64 = -8
movq $-8, %r13
movq %r13, -216(%rbp)

#.t65 = runs_lowest[.t64]
movq -56(%rbp), %r10
movq -216(%rbp), %r11
movq ( %r10, %r11 ), %r13
movq %r13, -224(%rbp)

#.t63 = .t63 - 1
movq -208(%rbp), %r13
movq $1, %r14
subq %r14, %r13
movq %r13, -208(%rbp)

#.t66 = .t63
movq -208(%rbp), %r13
movq %r13, -232(%rbp)

#.label9:   
.label9:

#.t66 = .t66 + 1
movq -232(%rbp), %r13
movq $1, %r14
addq %r13, %r14
movq %r14, -232(%rbp)

#.t67 = .t66 < .t65
movq -232(%rbp), %r13
movq -224(%rbp), %r14
cmpq %r13, %r14
setg %al
movzbq %al, %r14
movq %r14, -240(%rbp)

#if_false .t67 goto .label8
mov -240(%rbp), %rax
cmp $0, %rax
je .label8

#j = .t66
movq -232(%rbp), %r13
movq %r13, -200(%rbp)

#.t69 = j * 8
movq -200(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -248(%rbp)

#print, runs_lowest[.t69] int 
movq -56(%rbp), %r8
movq -248(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t70 = "against - "
movq $.str10, %r13
movq %r13, -256(%rbp)

#print, .t70 str 
mov -256(%rbp), %rax
mov %rax, %rsi
movq -256(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t72 = j * 8
movq -200(%rbp), %r13
movq $8, %r14
imulq %r13, %r14
movq %r14, -264(%rbp)

#print, runs_lowest_against[.t72] str 
movq -72(%rbp), %r8
movq -264(%rbp), %r9
mov ( %r8, %r9 ), %rax
mov %rax, %rsi
movq ( %r8, %r9 ), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#.t73 = 1
movq $1, -272(%rbp)

#.t74 = j + .t73
movq -200(%rbp), %r13
movq -272(%rbp), %r14
addq %r13, %r14
movq %r14, -280(%rbp)

#j = .t74
movq -280(%rbp), %r13
movq %r13, -200(%rbp)

#goto .label9  
jmp .label9

#.label8:   
.label8:

#.t75 = "CSK"
movq $.str11, %r13
movq %r13, -288(%rbp)

#.t76 = "DC"
movq $.str12, %r13
movq %r13, -296(%rbp)

#.t77 = "GL"
movq $.str13, %r13
movq %r13, -304(%rbp)

#.t78 = "KKR"
movq $.str14, %r13
movq %r13, -312(%rbp)

#.t79 = "LSG"
movq $.str15, %r13
movq %r13, -320(%rbp)

#.t80 = "MI"
movq $.str16, %r13
movq %r13, -328(%rbp)

#.t81 = "PK"
movq $.str17, %r13
movq %r13, -336(%rbp)

#.t82 = "RCB"
movq $.str18, %r13
movq %r13, -344(%rbp)

#.t83 = "RR"
movq $.str19, %r13
movq %r13, -352(%rbp)

#.t84 = "SRH"
movq $.str20, %r13
movq %r13, -360(%rbp)

#.t85 = alloc_mem(88) 
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
movq $88, %rdi
call malloc@plt
movq -432(%rbp), %rsp
movq %rax, -368(%rbp)

#.t86 = 0
movq $0, -376(%rbp)

#.t85[.t86] = 10
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq $10, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t75
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -288(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t76
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -296(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t77
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -304(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t78
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -312(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t79
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -320(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t80
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -328(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t81
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -336(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t82
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -344(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t83
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -352(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85[.t86] = .t84
movq -368(%rbp), %r8
movq -376(%rbp), %r9
movq -360(%rbp), %r13
movq %r13, ( %r8, %r9 )

#.t86 = .t86 + 8
movq -376(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -376(%rbp)

#.t85 = .t85 + 8
movq -368(%rbp), %r13
movq $8, %r14
addq %r13, %r14
movq %r14, -368(%rbp)

#arr = .t85
movq -368(%rbp), %r13
movq %r13, -392(%rbp)

#.t87 = "RCB"
movq $.str21, %r13
movq %r13, -400(%rbp)

##callnew   
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp

#push .t87  
pushq -400(%rbp)

#push arr  
pushq -392(%rbp)

#call, binary_search  
call binary_search
addq %r13, %rsp
movq -432(%rbp), %rsp

#move8 %rax .t88 
movq %rax, %r13
movq %r13, -408(%rbp)

#index = .t88
movq -408(%rbp), %r13
movq %r13, -416(%rbp)

#.t89 = "Index of RCB in sorted array is:"
movq $.str22, %r13
movq %r13, -424(%rbp)

#print, .t89 str 
mov -424(%rbp), %rax
mov %rax, %rsi
movq -424(%rbp), %rdi
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

#print, index int 
mov -416(%rbp), %rax
mov %rax, %rsi
lea .note0(%rip), %rax
mov %rax, %rdi
xor %rax, %rax
movq %rsp, -432(%rbp)
shr $4, %rsp
sub $1, %rsp
shl $4, %rsp
call printf@plt
movq -432(%rbp), %rsp

pop %rbx
mov $60, %rax       # System call number for exit
xor %rdi, %rdi      # Exit code is 0
syscall
