section .data
msg: db 'Ola mundo!'

section .text

%macro print 4

    mov eax, %1
    mov ebx, %2
    mov ecx, %3
    mov edx, %4
    int 0x80

%endmacro

global _start

_start:
    print 4, 1, msg, 10

    mov eax, 1
    int 0x80
