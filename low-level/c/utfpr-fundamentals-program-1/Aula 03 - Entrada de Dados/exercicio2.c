#include <stdio.h>
#include <stdlib.h>

/*
2) Faça um programa que calcule e mostre a idade de uma
pessoa a partir do ano em que a pessoa nasceu e do ano atual.
Os valores serão digitados pelo usuário.
Obs.:Considere que ela já fez aniversário neste ano.
*/

int main(){
    int ano_nasc, ano_atual, idade;

    printf("Digite o ano de nascimento: ");
    scanf("%i", &ano_nasc);
    printf("Digite o ano atual: ");
    scanf("%i", &ano_atual);
    idade = ano_atual - ano_nasc;
    printf("Sua idade é: %i \n", idade);
    return 0;
}