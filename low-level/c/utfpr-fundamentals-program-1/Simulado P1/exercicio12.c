#include <stdio.h>
#include <stdlib.h>

/*
12) Técnicos analisam a perda da massa do Xenônio-135 e descobriram que o tempo de meia vida desse radioisótopo é de 9h. Crie um algoritmo para receber a massa inicial em gramas e retorne o tempo necessário para que a massa deste material seja menor que 1 grama. Caso o tempo exceda 24h a resposta deve ser dada em dias (Ex.: 2 dias e 6 horas).
Obs.: O algoritmo deve calcular o tempo para várias massas, finalizando ao receber uma massa igual a zero ou negativa.
*/

int main() {
    double massa, tempo_horas, tempo_restante;
    int dias, horas;

    while (1) {
        printf("Digite a massa inicial (em gramas): ");
        scanf("%lf", &massa);

        if (massa <= 0) {
            break;
        }

        tempo_horas = 0;
        tempo_restante = massa;

        while (tempo_restante >= 1) {
            tempo_restante /= 2;
            tempo_horas += 9;
        }

        dias = tempo_horas / 24;
        horas = (int)tempo_horas % 24;

        if (dias > 0) {
            printf("%d dias e %d horas\n", dias, horas);
        } else {
            printf("%d horas\n", horas);
        }
    }

    return 0;
}