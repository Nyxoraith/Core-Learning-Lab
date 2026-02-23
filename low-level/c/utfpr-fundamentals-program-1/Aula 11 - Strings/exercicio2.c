#include <stdio.h>
#include <stdlib.h>

/*
2) Faça um programa que armazene o nome e salário de 5
empregados. Em seguida calcule um aumento de 8% nos
salários e exiba a nova folha de pagamentos.
*/

int main(){
    char nomes[5][50];
    float salarios[5];
    float novos_salarios[5];
    int c;

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do empregado %d: ", i + 1);
        fgets(nomes[i], 50, stdin);
        printf("Digite o salário do empregado %d: ", i + 1);
        scanf("%f", &salarios[i]);    
        while ((c = getchar()) != '\n' && c != EOF);
    }

    for (int i = 0; i < 5; i++) {
        novos_salarios[i] = salarios[i] * 1.08; 
    }

    printf("\nNova folha de pagamentos:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %s, Salário Atualizado: R$ %.2f\n", nomes[i], novos_salarios[i]);
    }
    printf("---------------------------------\n");

    return 0;
}