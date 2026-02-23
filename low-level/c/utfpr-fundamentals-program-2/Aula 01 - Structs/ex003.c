#include <stdio.h>
#include <string.h>
/*
3) Construa uma estrutura aluno com nome, curso e 4 notas,
média e situação. Leia as informações nome, curso e notas do
teclado, calcule a média e armazene a situação do aluno.
 media ≥ 7 → Aprovado;
 3 ≤ media < 7 → Exame;
 media < 3 → Reprovado;
*/

typedef struct {
    char nome[26];
    char curso[26];
    float notas[4];
    float media;
    char situacao[13];
}Aluno;

int main(){
    Aluno aluno;

    setbuf(stdin, NULL);
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, 25, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")]='\0';

    setbuf(stdin, NULL);
    printf("Digite o curso do aluno: ");
    fgets(aluno.curso, 25, stdin);
    aluno.curso[strcspn(aluno.curso, "\n")]='\0';

    for(int i = 0; i < 4; i++){
        printf("Digite a %dº nota do aluno: ", i+1);
        scanf("%f", &aluno.notas[i]);
    }
    
    aluno.media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2] + aluno.notas[3]) / 4;
    
    if (aluno.media >= 7){
        strcpy(aluno.situacao, "Aprovado");
    }else if (aluno.media >= 3){
        strcpy(aluno.situacao, "Exame");
    }else if (aluno.media < 3){
        strcpy(aluno.situacao, "Reprovado");
    }
    
    printf("Nome do Aluno: %s\n", aluno.nome);
    printf("Curso do Aluno: %s\n", aluno.curso);
    printf("Media do Aluno: %.1f\n", aluno.media);
    printf("Situação do Aluno: %s\n", aluno.situacao);
    return 0;
}