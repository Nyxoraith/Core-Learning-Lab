#include <stdio.h>
#include <string.h>
/*
1) Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.
*/

typedef struct{
    char nome[26], esporte[26];
    int idade;
    float altura;

}Atleta;

int main(){
    Atleta atletas[5];
    int indiceVelho, indiceAlto;

    for(int i = 0; i < 5; i++){
        printf("Digite o nome do %dº atleta: ", i+1);
        fgets(atletas[i].nome, 25, stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")]='\0';
        setbuf(stdin, NULL);

        printf("Digite o esporte do %dº atleta: ", i+1);
        fgets(atletas[i].esporte, 25, stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")]='\0';
        setbuf(stdin, NULL);

        printf("Digite a idade do %dº atleta: ", i+1);
        scanf("%d", &atletas[i].idade);
        getchar();

        printf("Digite a altura do %dº atleta: ", i+1);     
        scanf("%f", &atletas[i].altura);
        getchar();

        printf("\n");
    }

    
    for(int i = 0; i < 5; i++){    

        int maisVelho = atletas[0].idade;
        float maisAlto = atletas[0].altura;
        
        if(atletas[i].idade > maisVelho){
            maisVelho = atletas[i].idade;
            indiceVelho = i;
        }

        if(atletas[i].altura > maisAlto){
            maisAlto = atletas[i].altura;
            indiceAlto = i;
        }
        

    }

    printf("\n\nDados do atleta mais velho.\n\n");
    printf("Nome: %s\n", atletas[indiceVelho].nome);
    printf("Esporte: %s\n", atletas[indiceVelho].esporte);
    printf("Idade: %d\n", atletas[indiceVelho].idade);
    printf("Altura: %.2f\n", atletas[indiceVelho].altura);

    printf("\n\nDados do atleta mais alto.\n\n");
    printf("Nome: %s\n", atletas[indiceAlto].nome);
    printf("Esporte: %s\n", atletas[indiceAlto].esporte);
    printf("Idade: %d\n", atletas[indiceAlto].idade);
    printf("Altura: %.2f\n", atletas[indiceAlto].altura);

    return 0;
}