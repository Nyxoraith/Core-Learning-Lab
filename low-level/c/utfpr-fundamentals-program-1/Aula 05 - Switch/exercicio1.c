#include <stdio.h>
#include <stdlib.h>

/*
1) Crie um programa que forneça um menu com duas
opções. Caso o usuário digite 1, o programa solicitará um
número e verificará se o valor é par ou impar. Caso o
usuário digite 2, o programa solicitará uma idade e
verificará se pessoa é maior ou menor de idade.
Veja o exemplo de menu abaixo:
*/

int main(){
    int opcao, valor_opcao;

    printf("Menu do programa:\n");
    printf("1 - Verifica par/imapar\n");
    printf("2 - Verifica maior/menor de idade\n");
    printf("Digite a sua opção: ");
    scanf("%i", &opcao);
    
    switch(opcao){
        case 1:
            
            printf("Digite um valor para verificar se é par ou impar: ");
            scanf("%i", &valor_opcao);
            
            if(valor_opcao % 2 == 0){
                printf("O valor: %i é PAR.\n", valor_opcao);
            }else{
                printf("O valor: %i é IMPAR.\n", valor_opcao);
            }

            break;

        case 2:

            printf("Digite uma idade para verificar se a pessoa é maior ou menor de idade: ");
            scanf("%i", &valor_opcao);

            if (valor_opcao >= 18){
                printf("Com %i anos a pessoa já é MAIOR de idade.\n", valor_opcao);
            }else{
                printf("Com %i anos a pessoa ainda é MENOR de idade.\n", valor_opcao);
            }
            
            break;

        default:
            printf("Opção Inválida");
    }
    return 0;
}