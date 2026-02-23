#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa para determinar a quantidade de litros
de combustível gastos em uma viagem por um automóvel que
faz 12 km/litro. Para isso, sabe-se que o tempo gasto na viagem
é de 35 min e a velocidade média do automóvel é 80 km/h.
*/

int main(){
    float velocidade = 80;
    float autonomia = 12;
    float tempo = (float) 35 / 60;
    float distancia = velocidade * tempo;
    float litros = distancia / autonomia;
    
    printf("A distancia percorrida pelo carro neste trajeto foi de %.2f KM e a quantidade de litros de gasolina utilizadas foram %.2f L \n", distancia, litros);
    return 0;
}