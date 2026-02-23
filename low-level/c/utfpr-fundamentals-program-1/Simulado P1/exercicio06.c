#include <stdio.h>
#include <stdlib.h>

/*
6) Um professor maluco da UTFPR avalia seus alunos da seguinte maneira:

3 provas (com peso 20 cada)
1 conjunto de trabalhos menores durante o semestre (com peso 10)
1 projeto de um jogo com peso 30

A média regular do aluno será dada pela média ponderada das notas das 3 provas, 
nos projetos menores e do projeto do game. 
O aluno que atingir a nota igual ou superior a 60 estará aprovado, 
caso contrário, o aluno deverá realizar um exame onde a nota mínima necessária será dada pela fórmula:

NotaMinima = 120 – Média regular

O aluno aprovado via exame terá média final igual a 60 registrado no sistema.

Faça um programa que receba a nota das 3 provas, 1 nota dos projetos menores e 1 nota do projeto do game (todas as notas entre 0 e 100)
e informe se o aluno está aprovado ou terá que realizar o exame.
Em caso de exame o sistema deverá solicitar a nota do exame e informar se o aluno está aprovado ou reprovado e qual sua nota final (com uma casa decimal).

*/

int main(){
    int p1, p2, p3, game, trabalhos;
    float media_regular, nota_exame, nota_minima;

    printf("Digite a nota da P1: ");
    scanf("%d", &p1);
    printf("Digite a nota da P2: ");
    scanf("%d", &p2);
    printf("Digite a nota da P3: ");
    scanf("%d", &p3);    
    printf("Digite a nota dos Projetos menores: ");
    scanf("%d", &trabalhos);
    printf("Digite a nota do Projeto do Game: ");
    scanf("%d", &game);

    media_regular = ((p1 * 20) + (p2 * 20) + (p3 * 20) + (trabalhos * 10) + (game * 30)) / 100.0;
    printf("Média Regular: %.1f\n", media_regular);

    if (media_regular >= 60){
        printf("Você foi APROVADO com média: %.1f\n", media_regular);
    }else{
        nota_minima = 120 - media_regular;
        printf("Você precisará realizar o exame.\n");
        printf("Nota mínima necessária no exame: %.1f\n", nota_minima);

        printf("Digite a nota obtida no exame: ");
        scanf("%f", &nota_exame);
        
        if (nota_exame >= nota_minima) {
            printf("Você foi APROVADO, sua média final é 60.0.\n");
        } else {
            printf("Você foi REPROVADO. sua média final é %.1f.\n", media_regular);
        }
    }
    return 0;
}