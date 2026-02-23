#include <stdio.h>

/*
Ao iniciar sua jornada Pokémon, um treinador pode escolher entre três tipos de Pokémon iniciais. Crie um programa que utilize uma enumeração chamada TipoPokemon, com as opções: Fogo, Água e Grama

O programa deve pedir ao usuário para escolher um número (1 para Fogo, 2 para Água e 3 para Grama) e exibir uma mensagem motivadora baseada na escolha, por exemplo:

Fogo: "Você escolheu o caminho ardente da vitória!"
Água: "A correnteza te levará ao topo!"
Grama: "O crescimento e a estratégia são suas armas!"
Caso o usuário escolha um número inválido, o programa deve alertá-lo.
*/

enum TipoPokemon {FOGO=1, AGUA, GRAMA};

int main(){
    enum TipoPokemon tipopokemon;
    int op;
    printf("Escolha um numero (1) Fogo | (2) Água | (3) Grama: ");
    scanf("%d", &op);
    tipopokemon = op;

    switch(tipopokemon){
        case FOGO:
            printf("Você escolheu o caminho ardente da vitória\n");
            break;

        case AGUA:
            printf("A correnteza te levará ao topo!\n");
            break;

        case GRAMA: 
            printf("O crescimento e a estratégia são suas armas!\n");
            break;

        default:
            printf("Número Inválido\n");
            break;
    }
    return 0;
}