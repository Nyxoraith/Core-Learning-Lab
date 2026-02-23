#include <stdio.h>
#include <string.h>
/*
4) Faça um programa que controla o consumo de energia dos
eletrodomésticos de uma casa e:
 Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras),
potência (real, em kW) e tempo ativo por dia (real, em horas).
 Leia um tempo t (em dias), calcule e mostre o consumo total na casa e
o consumo relativo de cada eletrodoméstico (consumo/consumo total)
nesse período de tempo. Apresente este último dado em porcentagem.
*/

typedef struct{ 
    char nome[16];
    float potencia;
    float tempo;
}Eletrodomestico;

int main(){
    Eletrodomestico eletrodomesticos[5];
    float consumoTotal = 0, consumoEletro, percentual;
    int t;

    for(int i = 0; i < 5; i++){

        setbuf(stdin, NULL);
        printf("Digite o nome do %dº Eletrodomestico: ", i+1);
        fgets(eletrodomesticos[i].nome, 15, stdin);
        eletrodomesticos[i].nome[strcspn(eletrodomesticos[i].nome, "\n")]='\0';

        printf("Digite a potencia do %dº Eletrodomestico: ", i+1);
        scanf("%f", &eletrodomesticos[i].potencia);

        printf("Digite o tempo ativo do %dº Eletrodomestico: ", i+1);
        scanf("%f", &eletrodomesticos[i].tempo);
    }

    printf("Digite o tempo t (em dias): ");
    scanf("%d", &t);

    for (int i = 0; i < 5; i++) {
        consumoTotal += eletrodomesticos[i].potencia * eletrodomesticos[i].tempo * t;
    }

    printf("Consumo total da casa em %d dias: %.2f kWh\n", t, consumoTotal);
    printf("Consumo relativo de cada eletrodoméstico:\n");

    for (int i = 0; i < 5; i++) {
        consumoEletro = eletrodomesticos[i].potencia * eletrodomesticos[i].tempo * t;
        percentual = (consumoEletro / consumoTotal) * 100;
        printf("%s: %.2f kWh (%.2f%%)\n", eletrodomesticos[i].nome, consumoEletro, percentual);
    }

    return 0;
}