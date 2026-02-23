section .data
    output db "O resultado é: ", 0xA  ; 0xA é o caractere de nova linha
    output_len equ $ - output
    
section .bss
    buffer resb 10

section .text
    global _start

_start:
    ; Coloque 5 em eax
    mov eax, 5
    ; Coloque 5 em ebx
    mov ebx, 5
    ; Adicione ebx a eax
    add eax, ebx
    ; Mova o resultado para esi
    mov esi, eax
    
    ; Exiba a string "O resultado é: "
    mov eax, 4           ; syscall número 4 para sys_write
    mov ebx, 1           ; arquivo descritor 1: saída padrão
    mov ecx, output      ; endereço da string
    mov edx, output_len  ; tamanho da string
    int 0x80             ; chame a interrupção do sistema
    
    ; Converta o valor em esi para uma string
    mov eax, esi
    mov ebx, 10          ; base decimal
    mov ecx, buffer      ; local para armazenar a string
    call itoa
    
    ; Exiba a string convertida
    mov eax, 4           ; syscall número 4 para sys_write
    mov ebx, 1           ; arquivo descritor 1: saída padrão
    mov ecx, buffer      ; endereço da string
    call strlen          ; obtenha o tamanho da string
    int 0x80             ; chame a interrupção do sistema
    
    ; Nova linha
    mov eax, 4           ; syscall número 4 para sys_write
    mov ebx, 1           ; arquivo descritor 1: saída padrão
    mov ecx, 0xA         ; endereço do caractere de nova linha
    mov edx, 1           ; tamanho da nova linha
    int 0x80             ; chame a interrupção do sistema
    
    ; Sair do programa
    mov eax, 1           ; syscall número 1 para sys_exit
    xor ebx, ebx         ; código de saída 0
    int 0x80             ; chame a interrupção do sistema

itoa:                   ; função para converter inteiro para string
    mov edi, ecx        ; edi = endereço do buffer
    add edi, 9          ; move edi para o final do buffer
    mov byte [edi], 0   ; termina a string com null

reverse:
    dec edi             ; move para o próximo byte no buffer
    xor edx, edx        ; clear edx
    div ebx             ; divide eax por 10
    add dl, '0'         ; converte o resto em caractere
    mov [edi], dl       ; armazena o caractere no buffer
    test eax, eax       ; verifica se eax é zero
    jnz reverse         ; se não for zero, continue a divisão
    ret

strlen:                 ; função para calcular o comprimento da string
    xor ecx, ecx        ; inicializa contador de comprimento
repeat:
    cmp byte [ecx], 0   ; verifica se chegou ao final da string
    je end              ; se sim, sai do loop
    inc ecx             ; incrementa o contador
    jmp repeat          ; repete o loop
end:
    ret