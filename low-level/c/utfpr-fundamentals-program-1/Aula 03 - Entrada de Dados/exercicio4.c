#include <stdio.h>
#include <stdlib.h>

/*
4) Calcule a média aritmética de 4 números reais que o usuário
digitar. Imprima a média na tela apenas com 2 casas decimais.
*/

int main(){
    float numero1, numero2, numero3, numero4, media;
    printf("Digite quatro numeros reais para realizar o cálculo de média\n\n");
    printf("Digite o primeiro numero: ");
    scanf("%f", &numero1);
    
    printf("Digite o segundo numero: ");
    scanf("%f", &numero2);

    printf("Digite o terceiro numero: ");
    scanf("%f", &numero3);

    printf("Digite o quarto numero: ");
    scanf("%f", &numero4);

    printf("Você digitou os seguintes numeros: Primeiro: %.2f | Segundo: %.2f | Terceiro: %.2f | Quarto: %.2f\n", numero1, numero2, numero3, numero4);
    media = (numero1 + numero2 + numero3 + numero4) / 4;
    printf("A média entre esses numero é: %.2f\n", media);
    return 0;
}