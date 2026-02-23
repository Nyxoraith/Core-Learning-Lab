#include <stdio.h>

/*
6) Considere a funcaox abaixo. O que essa função faz? Escreva
uma função não-recursiva que resolve o mesmo problema

int funcaox(int a){
 if(a <= 0) return 0;
 else return a + funcaox(a-1);
}//funcaox
*/

int funcaox(int a){
    int resultado = 0;

    for(int i = 0; i <= a; i++){
        resultado += i;
    }

    return resultado;
}

int main(){
    int resultado, a;

    printf("Digite um valor para a função x: ");
    scanf("%d", &a);
    
    resultado = funcaox(a);
    printf("O retorno da função x é: %d\n", resultado);

    return 0;
}