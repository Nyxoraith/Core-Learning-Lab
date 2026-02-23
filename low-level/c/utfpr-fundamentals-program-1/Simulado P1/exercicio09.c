#include <stdio.h>
#include <stdlib.h>

/*
9) Faça um programa que receba o dia, mês e ano de uma data e informe se é uma data válida ou não
*/

int main() {
    int dia, mes, ano;

    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mês: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    if (mes < 1 || mes > 12) {
        printf("Data inválida! Mês inválido.\n");
    }
    else if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) {
        printf("Data inválida! Dia inválido para o mês %d.\n", mes);
    }
    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)) {
        printf("Data inválida! Dia inválido para o mês %d.\n", mes);
    }
    else if (mes == 2 && (dia < 1 ||  dia > 28)){
        printf("Data inválida! Dia inválido para o mês de Fevereriro.\n");
    } else {
        printf("Data válida!\n");
    }

    return 0;
}
