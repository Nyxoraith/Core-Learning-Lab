#include <stdio.h>
#include <stdlib.h>

/*
Desenvolva um programa que receba um numero
tamanho e exiba um quadrado de tamanho tamanho
utilizando o carácter #
*/

int main(){
    int number;
    printf("Digite o tamanho do quadrado: ");
    scanf("%d", &number);
    for(int i = 1; i <= number; i++){
        for(int b = 1; b <= number; b++){
            printf("# ");
        }
            printf("\n");

    }
    return 0; 
}