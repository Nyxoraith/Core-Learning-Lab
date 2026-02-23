#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[25];
    float nota;
}Aluno;

int main(){
    Aluno alunos[5];

    for(int i = 0; i < 4; i++){
        printf("Digite a %dº nome: ", i+1);
        setbuf(stdin, NULL);
        fgets(alunos[i].nome, 24, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")]='\0';

        printf("Digite a %dº nota: ", i+1);
        scanf("%f", &alunos[i].nota);
    }

    for(int i = 0; i < 4; i++){
        printf("|%-20s| %4.1f|\n", alunos[i].nome, alunos[i].nota);
    }

    return 0;
}