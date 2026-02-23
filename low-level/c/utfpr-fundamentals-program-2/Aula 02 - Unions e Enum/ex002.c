#include <stdio.h>
//#include <stdio_ext.h> //linux para o fpurge
#include <string.h>

/*
Você foi contratado para desenvolver um sistema de cadastro de pessoas que permitirá armazenar e exibir informações essenciais de 5 indivíduos. Seu programa deve solicitar os seguintes dados para cada pessoa:

Nome, Idade, Peso, Data de nascimento (dia, mês e ano), Nacionalidade (Brasileiro ou Estrangeiro), Documento de identificação: Se for brasileiro, deve armazenar o CPF ou se for estrangeiro, deve armazenar o Passaporte

Regras obrigatórias:
Utilize structs para estruturar os dados da pessoa;
Utilize typedef para facilitar a definição de tipos personalizados;
Utilize union para armazenar CPF ou Passaporte, garantindo eficiência na memória;
Utilize enum para representar a nacionalidade da pessoa (Brasileiro ou Estrangeiro).
Após o cadastro, o programa deve exibir todas as informações cadastradas de maneira clara e organizada.
*/

typedef enum{BRASILEIRO=1, ESTRANGEIRO} Nacionalidade;

typedef struct{
    int dia;
    int mes;
    int ano;
}Nascimento;

typedef union{
    char cpf[12];
    char passaporte[12];
}Identificacao;

typedef struct{
    char nome[26];
    int idade;
    float peso;
    Nascimento data_nascimento;
    Nacionalidade nacionalidade;
    Identificacao identificacao;

}Pessoa;

int main(){

    Pessoa pessoas[2];

    for(int i = 0; i < 2; i++){
        printf("Digite seu nome: ");
        setbuf(stdin, NULL);
        getchar();
        //__fpurge(stdin);//linux
        //fflush(stdin); //win
        fgets(pessoas[i].nome, 25, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")]='\0';

        printf("Digite sua idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("Digite seu peso: ");
        scanf("%f", &pessoas[i].peso);

        printf("Digite sua data de nascimento [dd/mm/aaaa]: ");
        scanf("%d/%d/%d", &pessoas[i].data_nascimento.dia, &pessoas[i].data_nascimento.mes, &pessoas[i].data_nascimento.ano);

        int op;
        printf("Digite a sua nacionalidade (1) Brasileiro | (2) Estrangeiro: ");
        scanf("%d", &op);
        pessoas[i].nacionalidade = op;

        getchar();

        switch(pessoas[i].nacionalidade){
            case BRASILEIRO:
                printf("Digite seu CPF: ");
                setbuf(stdin, NULL);
                fgets(pessoas[i].identificacao.cpf, 11, stdin);
                pessoas[i].identificacao.cpf[strcspn(pessoas[i].identificacao.cpf, "\n")]='\0';
                break;

            case ESTRANGEIRO:
                printf("Digite seu Passaporte: ");
                setbuf(stdin, NULL);
                fgets(pessoas[i].identificacao.passaporte, 11, stdin);
                pessoas[i].identificacao.passaporte[strcspn(pessoas[i].identificacao.passaporte, "\n")]='\0';
                break;

            default:
                printf("Nascionalidade inválida!");
                break;
        }
    }


    for(int i = 0; i < 2; i++){
        printf("\n\nNome da %dº Pessoa: %s\n", i+1, pessoas[i].nome);
        printf("Idade da %dº Pessoa: %d\n", i+1, pessoas[i].idade);
        printf("Peso da %dº Pessoa: %.2f\n", i+1, pessoas[i].peso);
        printf("Data de Nascimento da %dº Pessoa: %d/%d/%d\n", i+1, pessoas[i].data_nascimento.dia, pessoas[i].data_nascimento.mes, pessoas[i].data_nascimento.ano);
        
        if(pessoas[i].nacionalidade == BRASILEIRO){
            printf("Nascionalidade da %dº Pessoa: Brasileiro\n", i+1);
            printf("CPF da %dº Pessoa: %s\n", i+1, pessoas[i].identificacao.cpf);
        }else{
            printf("Nascionalidade da %dº Pessoa: Estrangeiro\n", i+1);
            printf("Passaporte da %dº Pessoa: %s\n", i+1, pessoas[i].identificacao.passaporte);
        }
    }
    return 0;
}