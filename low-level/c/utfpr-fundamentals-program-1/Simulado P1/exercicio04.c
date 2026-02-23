#include <stdio.h>
#include <stdlib.h>

/*
4)Faça um programa que receba 3 idades distintas e mostre:
a idade da pessoa mais velha; 
a idade da pessoa mais nova e a média das 3 idades .
O programa deve considerar e informar o caso de 2 ou 3 pessoas terem a mesma idade.
*/

int main() {
    int idade_pessoa1, idade_pessoa2, idade_pessoa3;
    int mais_velha, mais_nova;
    float media;

    printf("Digite a idade da primeira pessoa: ");
    scanf("%d", &idade_pessoa1);

    printf("Digite a idade da segunda pessoa: ");
    scanf("%d", &idade_pessoa2);

    printf("Digite a idade da terceira pessoa: ");
    scanf("%d", &idade_pessoa3);

    media = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3.0;

    if (idade_pessoa1 >= idade_pessoa2 && idade_pessoa1 >= idade_pessoa3) {
        mais_velha = idade_pessoa1;
    } else if (idade_pessoa2 >= idade_pessoa1 && idade_pessoa2 >= idade_pessoa3) {
        mais_velha = idade_pessoa2;
    } else {
        mais_velha = idade_pessoa3;
    }

    if (idade_pessoa1 <= idade_pessoa2 && idade_pessoa1 <= idade_pessoa3) {
        mais_nova = idade_pessoa1;
    } else if (idade_pessoa2 <= idade_pessoa1 && idade_pessoa2 <= idade_pessoa3) {
        mais_nova = idade_pessoa2;
    } else {
        mais_nova = idade_pessoa3;
    }

    if (idade_pessoa1 == idade_pessoa2 && idade_pessoa1 == idade_pessoa3) {
        printf("As três pessoas têm a mesma idade: %d anos.\n", idade_pessoa1);
    } else if (idade_pessoa1 == idade_pessoa2 || idade_pessoa1 == idade_pessoa3 || idade_pessoa2 == idade_pessoa3) {
        printf("Duas pessoas têm a mesma idade.\n");
    } else {
        printf("Todas as idades são distintas.\n");
    }

    printf("A idade da pessoa mais velha é: %d\n", mais_velha);
    printf("A idade da pessoa mais nova é: %d\n", mais_nova);
    printf("A média das idades é: %.2f\n", media);

    return 0;
}
