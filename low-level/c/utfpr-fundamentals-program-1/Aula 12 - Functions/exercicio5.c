#include <stdio.h>

/*
5) Crie uma função que que receba o valor de um inteiro
positivo N, calcule e retorne o fatorial desse número.
*/

int calcFatorial(int num);

int main(){
    int num;
    int fatorial;

    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d",&num);

    if(num >= 0){
        fatorial = calcFatorial(num);
        printf("O fatorial de %d é: %d", num, fatorial);
    }else{
        printf("O numero informado não é positivo.");
    }
    

    return 0;
}

int calcFatorial(int num){
    int fatorial = 1;
    for(int i = 1; i <= num; i++){
        fatorial *= i;
    }
    return fatorial;
}