#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa com 2 variáveis, A e B, onde A terá
o valor 40 e B terá o valor -1. Imprima o valor de A+B, A-B,
AxB e A/B. Em seguida, faça B incrementar de uma
unidade e repita as 4 operações. 
*/

int main(){
    int A = 40;
    int B = -1;
    int resultado = A + B;
    printf("O Resultado da soma entre A e B é: %i\n", resultado);

    resultado = A - B;
    printf("O Resultado da subtração entre A e B é: %i\n", resultado);

    resultado = A * B;
    printf("O Resultado da multiplicação entre A e B é: %i\n", resultado);

    resultado = A / B;
    printf("O Resultado da divisão entre A e B é: %i\n", resultado);

    //Operações Pos Incremento

    B++;
    printf("O Valor B agora vale: %i\n", B);

    resultado = A + B;
    printf("O Resultado da soma entre A e B é: %i \n", resultado);
    
    resultado = A - B;
    printf("O Resultado da subtração entre A e B é: %i \n", resultado);

    resultado = A * B;
    printf("O Resultado da multiplicação entre A e B é: %i \n", resultado);

    //resultado = A / B; 
    printf("Não é possivel realizar uma divisão por 0 \n");
    return 0;
}