#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
9) Faça um programa que simule um jogo, onde o usuário
deverá descobrir um número aleatório escolhido pelo
computador (de 1 a 100).
 O usuário poderá realizar até 6 tentativas, o programa deverá
retornar as mensagens “muito alto”, “muito baixo” até o usuário
acertar o número ou esgotar o número máximo de tentativas
*/

int main(){
    srand(time(0));
    int tentativas = 6;
    int random = rand() % 100 + 1;
    int num;

    while(tentativas > 0){
        
        printf("Digite um numero (%d tentativas restantes): ", tentativas);
        scanf("%d", &num);

        if (num == random){
            printf("Parabéns! Você acertou o número: %d\n", random);
            break;
        } else if (num < random) {
            printf("Muito baixo!\n");
        } else {
            printf("Muito alto!\n");
        }

        tentativas--;

        if (tentativas == 0) {
            printf("Acabou suas tentativas. O número era: %d\n", random);
        }
    }
    return 0;
}