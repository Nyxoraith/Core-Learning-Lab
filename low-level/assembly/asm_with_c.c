#include <stdio.h>

int soma(int a, int b);

int main(){
    int a = 15;
    int b = 45;
    int resultadoOperacao = soma(a,b);
    printf("Resultado: %i", resultadoOperacao);
    return 0;
}

int soma(int a, int b){
    int resultado;
    __asm__(
        "mov eax, %[a]\n"
        "add eax, %[b]\n"
        "mov %[resultadoSoma], eax"
        :[resultadoSoma] "=r" (resultado)
        :[a] "r" (a), [b] "r" (b)
    );
    return resultado;
}