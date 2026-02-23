#include <stdio.h>

/*
5) Um problema típico em ciência da computação consiste em
converter um número da sua forma decimal para binária. Crie um
algoritmo recursivo para resolver esse problema.
 Solução trivial: x=0 quando o número inteiro já foi convertido para
binário
 Passo da recursão: saber como x/2 é convertido. Depois, imprimir um
dígito (0 ou 1) dado o sucesso da divisão.
*/

int converteBin(int n){
    int teste;
    if(n == 0){
        return 0;
    }

    teste = converteBin(n - 1) % 2;
    printf("%d", teste);
    return teste;
}

int main(){
    int resultado, n;

    printf("Digite o numero a ser convertido: ");
    scanf("%d", &n);

    resultado = converteBin(n);
    printf("%d\n", resultado);

    return 0;
}