section .data
msg: db 'Ola mundo!'

section .text
%define stdout mov ebx, 1
%define write mov eax, 4

global _start

_start:
    write
    stdout
    mov ecx, msg
    mov edx, 10
    int 0x80

    mov eax, 1
    int 0x80
    ret