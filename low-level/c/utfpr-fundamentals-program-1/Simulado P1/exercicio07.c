#include <stdio.h>
#include <stdlib.h>

/*
7) Considerando uma aplicação de renda fixa, faça um programa que receba o capital investido, a taxa (em %) e a quantidade de meses. O programa deverá retornar o montante final considerando o desconto do imposto de renda segundo regras abaixo:

22,5% - prazo inferior a 6 meses
20% - de 6 a 12 meses
17,5% - de 12 a 24 meses
15% - igual ou superior a 24 meses

Obs: O imposto é calculado apenas sobre o lucro da aplicação.
*/

int main() {
    float capital, taxa, montante, lucro, imposto, montante_final;
    int meses;

    printf("Digite o capital investido: ");
    scanf("%f", &capital);
    printf("Digite a taxa mensal: ");
    scanf("%f", &taxa);
    printf("Digite a quantidade de meses: ");
    scanf("%d", &meses);

    montante = capital * pow((1 + taxa / 100.0), meses);

    lucro = montante - capital;

    if (meses < 6) {
        imposto = 0.225 * lucro;
    } else if (meses <= 12) {
        imposto = 0.20 * lucro;
    } else if (meses <= 24) {
        imposto = 0.175 * lucro;
    } else {
        imposto = 0.15 * lucro;
    }

    montante_final = montante - imposto;

    printf("Montante bruto: R$ %.2f\n", montante);
    printf("Lucro: R$ %.2f\n", lucro);
    printf("Imposto de renda: R$ %.2f\n", imposto);
    printf("Montante final após imposto: R$ %.2f\n", montante_final);

    return 0;
}
