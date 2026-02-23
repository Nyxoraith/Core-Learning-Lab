#include <stdio.h>

int soma(int n1, int n2){
    return n1 + n2;
}

int main(){
    int resultado;
    resultado = soma(5,8);

    printf("A soma entre 5 e 8 é: %d\n", resultado);
    return 0;
}