#include <stdio.h>
#include <stdlib.h>

/*
Tendo a Altura da pessoa definida como uma constante,
calcule seu peso ideal utilizando a seguinte fórmula:
peso ideal = 72.7 x altura – 58
*/

int main(){
    const float altura = 1.78;
    float peso = 72.7 * altura - 58;
    printf("Peso ideal: %.2f\n", peso);
    return 0;
}