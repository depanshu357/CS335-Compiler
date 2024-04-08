# global data  #
    .data
format: .asciz "%d\n"    
.text
    .global main
main:
movq -0(%r15), %r13
movq -8(%r15), %r14
addq %r13, %r14
movq %r14, -16(%r15)
# exit syscall
mov $60, %rax
xor %rdi, %rdi
syscall
