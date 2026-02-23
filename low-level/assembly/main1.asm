section .data
    msg: db "Resultado: ",0

section .bss
    sum resd 1

section .text

global _start

soma:
    xor esi, esi
    mov esi, 5
    mov edi, 5
    add esi, edi
    mov eax, esi
    mov [sum], eax
    ret

_start:
    call soma

    mov eax, [sum]
    add eax, 0
    mov [sum], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, sum
    mov edx, 2
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80