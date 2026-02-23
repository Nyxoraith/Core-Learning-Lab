#include <stdio.h>
#include <stdlib.h>

/*
2) Faça um algoritmo que exiba todos números de 100 a 1.
*/

int main(){
    int contador = 100;
    while(contador >= 1){
        printf("%d\n", contador);
        contador--;
    }
    return 0;
}