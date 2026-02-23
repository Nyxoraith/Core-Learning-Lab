#include <stdio.h>

/*
1) Implemente uma função em C que receba três números inteiros como parâmetros e retorne o maior deles. Na função main, chame essa função com diferentes valores de teste e exiba o resultado na tela.
*/

int maiorNumero(int n1, int n2, int n3){
    int maiorValor = n1;

    if(maiorValor < n2){
        maiorValor = n2;
    }if(maiorValor < n3){
        maiorValor = n3;
    }

    return maiorValor;
};

int main(){
    int n1, n2, n3;
    int maiorValor;

    printf("Digite tres numeros inteiros.\n");
    printf("Digite o 1º numero: ");
    scanf("%d", &n1);
    
    printf("Digite o 2º numero: ");
    scanf("%d", &n2);

    printf("Digite o 3º numero: ");
    scanf("%d", &n3);

    maiorValor = maiorNumero(n1, n2, n3);

    printf("Entre os numeros %d, %d, %d o maior numero é: %d\n", n1, n2, n3, maiorValor);

    return 0;
}