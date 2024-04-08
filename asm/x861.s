.data
        integer_format:	.asciz,	"%ld\n"
.global	main
.text
movq 0(%r1) %r2
movq 8(%r1) %r3
add %r2 %r3
movq %r2 16(%r1)
mov     $60, %rax
xor     %rdi, %rdi
syscall
