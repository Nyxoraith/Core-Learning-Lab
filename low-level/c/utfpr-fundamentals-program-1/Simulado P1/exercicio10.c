#include <stdio.h>
#include <stdlib.h>

/*
10) Desenvolva um programa que receba um valor de 1 a 99 e exiba o valor por extenso
Ex:
Digite um Número: 74
Valor por extenso: setenta e quatro
*/

int main() {
    int num;
    int dezenas, unidades;

    printf("Digite um número entre 1 e 99: ");
    scanf("%d", &num);

    if (num < 1 || num > 99) {
        printf("Número fora do intervalo permitido.\n");
        return 0;
    }

    dezenas = num / 10;
    unidades = num % 10;

    if (dezenas == 1) {
        if (unidades == 0) {
            printf("Valor por extenso: dez\n");
        } else if (unidades == 1) {
            printf("Valor por extenso: onze\n");
        } else if (unidades == 2) {
            printf("Valor por extenso: doze\n");
        } else if (unidades == 3) {
            printf("Valor por extenso: treze\n");
        } else if (unidades == 4) {
            printf("Valor por extenso: quatorze\n");
        } else if (unidades == 5) {
            printf("Valor por extenso: quinze\n");
        } else if (unidades == 6) {
            printf("Valor por extenso: dezesseis\n");
        } else if (unidades == 7) {
            printf("Valor por extenso: dezessete\n");
        } else if (unidades == 8) {
            printf("Valor por extenso: dezoito\n");
        } else if (unidades == 9) {
            printf("Valor por extenso: dezenove\n");
        }
    }
    else {
        if (dezenas == 2) {
            printf("Valor por extenso: vinte");
        } else if (dezenas == 3) {
            printf("Valor por extenso: trinta");
        } else if (dezenas == 4) {
            printf("Valor por extenso: quarenta");
        } else if (dezenas == 5) {
            printf("Valor por extenso: cinquenta");
        } else if (dezenas == 6) {
            printf("Valor por extenso: sessenta");
        } else if (dezenas == 7) {
            printf("Valor por extenso: setenta");
        } else if (dezenas == 8) {
            printf("Valor por extenso: oitenta");
        } else if (dezenas == 9) {
            printf("Valor por extenso: noventa");
        }

        if (unidades > 0) {
            printf(" e ");
            if (unidades == 1) {
                printf("um");
            } else if (unidades == 2) {
                printf("dois");
            } else if (unidades == 3) {
                printf("três");
            } else if (unidades == 4) {
                printf("quatro");
            } else if (unidades == 5) {
                printf("cinco");
            } else if (unidades == 6) {
                printf("seis");
            } else if (unidades == 7) {
                printf("sete");
            } else if (unidades == 8) {
                printf("oito");
            } else if (unidades == 9) {
                printf("nove");
            }
        }
        printf("\n");
    }

    return 0;
}