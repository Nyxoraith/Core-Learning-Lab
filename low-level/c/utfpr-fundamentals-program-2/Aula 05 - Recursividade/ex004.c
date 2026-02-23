#include <stdio.h>

/*
4) Faça uma função recursiva que retorne o n-ésimo termo da sequência de Fibonacci, sendo que n é recebido por parâmetro. Utilize essa função para desenvolver um programa que mostre no main() os n termos dessa sequência na tela, a partir do valor de n recebido pelo teclado. Sabe-se que o 1º termo é 0 e o 2º termo é 1.
*/

int fibonacci(int n){
    int teste;
    if(n == 0){
        return 0;
    }if(n == 1){
        return 1;
    }

    teste = fibonacci(n-1) + fibonacci(n-2);
    return teste;
}

int main(){
    int resultado, n;

    printf("Digite o valor: ");
    scanf("%d", &n);

    resultado = fibonacci(n);
    printf("0 1 ");
    for(int i = 0, a = 0, b = 1, aux = 0; i < n - 2; i++){
        aux = a + b;
        a = b;
        b = aux;
        printf("%d ", aux);
    }
    printf("\n\n%d\n", resultado);
    return 0;
}