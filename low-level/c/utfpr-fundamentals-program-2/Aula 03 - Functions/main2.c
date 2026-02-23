#include <stdio.h>

void mensagemInterna(){
	printf("--> Dentro da função interna!\n");
	return;
}

void mensagem(){
	printf("-> Dentro da função!\n");
	mensagemInterna();
	printf("-> Dentro da função!\n");
	return;
}

int main(){
	printf("Fora da função!\n");
	mensagem();
	printf("Depois da função!\n");
	return 0;
}