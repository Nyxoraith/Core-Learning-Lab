#include <stdio.h>
#include <stdlib.h>

/*
1) Faça um programa que calcule a média para 5 alunos, sendo que
cada aluno tem 2 notas (reais). O programa somente deverá aceitar
notas no intervalo fechado de 0 a 10, solicitando nova digitação
quando necessário.
*/

int main(){
    float nota1, nota2, media;
    int contador = 1;
    do{
        printf("Digite a nota do aluno %d\n", contador);
        do{
            printf("Digite a nota 1: ");
            scanf("%f", &nota1);
        }while(nota1 < 0 || nota1 > 10);


        do{    
            printf("Digite a note 2: ");
            scanf("%f", &nota2);
        }while(nota2 < 0 || nota2 > 10);
        
        media = (nota1 + nota2) / 2;
        
        printf("A meia entre a nota 1 e 2 e: %.2lf\n\n", media);
        contador++;
    }while(contador <= 5);
    return 0;
}