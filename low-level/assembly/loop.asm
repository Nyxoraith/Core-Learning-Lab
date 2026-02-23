section .data
    numbers: db '0123456789'
    newline: db 0xA

section .text

global _start

_start:
xor esi, esi
call loop

loop:
    mov eax, 4
    mov ebx, 1
    lea ecx, [numbers + esi]
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    inc esi
    cmp esi, 0xA
    jle loop

    mov eax, 1
    int 0x80
    ret