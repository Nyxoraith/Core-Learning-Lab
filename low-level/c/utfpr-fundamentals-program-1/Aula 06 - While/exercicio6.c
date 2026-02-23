#include <stdio.h>
#include <stdlib.h>

/*
5) Faça um programa que receba um número real, calcule e
exiba o quadrado dele. O programa deverá repetir esse
procedimento para 10 números, um de cada vez.
*/

int main(){
    float num, quadrado;

    while (1){
        
        printf("Digite um numero para calcular o quadrado (negativo ou zero para sair): ");
        scanf("%f", &num);

        if(num <= 0){
            printf("Encerrando programa...\n");
            break;
        }

        quadrado = num * num;
        printf("O quadrado de %.2f é: %.2f\n", num, quadrado);
    }
    
    return 0;
}