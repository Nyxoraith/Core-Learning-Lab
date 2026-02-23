#include <stdio.h>

/*
4) Escreva uma função em C que receba a média final de um aluno (número real) como parâmetro e retorne seu conceito de acordo com a seguinte escala:

Média entre 9 e 10: Conceito A
Média entre 7 e 8.9: Conceito B
Média entre 5 e 6.9: Conceito C
Média entre 0 e 4.9: Conceito D
Na função main, solicite ao usuário que informe a média final, chame a função e exiba o conceito correspondente.
*/

char conceito(float mediaFinal){
    char conceito;
    if(mediaFinal >= 0 && mediaFinal <= 4.99){
        conceito = 'D';
    }else if(mediaFinal >= 5 && mediaFinal <= 6.99){
        conceito = 'C';
    }else if(mediaFinal >= 7 && mediaFinal <= 8.99){
        conceito = 'B';
    }else if(mediaFinal >= 9 && mediaFinal <= 10){
        conceito = 'A';
    }
    return conceito;
}

int main(){
    float mediafinal;
    char notaConceito;

    printf("Digite a média final do aluno: ");
    scanf("%f", &mediafinal);

    notaConceito = conceito(mediafinal);

    printf("A nota conceito do aluno que tirou uma nota de %.2f é: Conceito %c\n", mediafinal, notaConceito);
    return 0;
}