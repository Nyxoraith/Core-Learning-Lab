#include <stdio.h>
#include <stdlib.h>

/*
1) Faça um algoritmo que exiba todos números de 1 a 100.
*/

int main(){
    int contador = 1;
    while(contador <= 100){
        printf("%d\n", contador);
        contador++;
    }
    return 0;
}