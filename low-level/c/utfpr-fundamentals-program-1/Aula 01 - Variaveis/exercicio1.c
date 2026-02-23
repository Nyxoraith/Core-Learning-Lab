#include <stdio.h>
#include <stdlib.h>

/*
1) Elabore um programa que exiba o seu nome na primeira
linha e o seu e-mail segunda. Em seguida, exiba uma
mensagem solicitando para o usuário pressionar uma tecla.
Quando o usuário pressionar, exiba em uma nova linha o nome
do seu amigo e, em outra, o e-mail dele.
*/

int main(){
    char meu_nome[] = "Vinicius";
    char meu_email[] = "Vinicius@outlook.com";
    char nome_amigo[] = "Leonardo";
    char email_amigo[] = "Leonardo@yahoo.com";

    printf("%s\n", meu_nome);
    printf("%s\n", meu_email);

    printf("Pressione uma tecla para continuar.");
    getchar();
    printf("%s\n", nome_amigo);
    printf("%s\n", email_amigo);

    return 0;
}