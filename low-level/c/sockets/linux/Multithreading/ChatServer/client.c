#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define PORT 4444
#define MAX_SIZE_MSG 1048

typedef struct {
    int socket;
} DataClient;

//Separar em 2 threads 1 envia a outra recebe.
int chatClient();
void* threadRecvMsg(void *threadArgs);

int main(){
    if(chatClient()==1){
        return 1;
    }
    return 0;
}

int chatClient(){
    int sockFD;
    char username[32];
    char bufferMsg[MAX_SIZE_MSG];
    struct sockaddr_in clientAddr;
    socklen_t addrlenClient = sizeof(clientAddr);

    sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if(sockFD < 0){
        perror("[ERRO]: Erro ao criar o socket!");
        return 1;
    }

    memset(&clientAddr, 0, addrlenClient);
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &clientAddr.sin_addr) < 0){
        perror("[ERRO] Erro ao converter o endereço!");
        return 1;
    }

    printf("Digite seu nome de usuário: ");
    fflush(stdout);
    fgets(username, 32, stdin);
    username[strcspn(username, "\n")]='\0';
    printf("\n");
    if(connect(sockFD, (struct sockaddr *) &clientAddr, sizeof(clientAddr)) < 0){
        perror("[ERRO]: Erro ao realizar a conexão!");
        return 1;
    }

    if(send(sockFD, username, strlen(username), 0) < 0){
        perror("[ERRO]: Erro ao enviar o username!");
        return 1;
    }
    
    DataClient *client = malloc(sizeof(DataClient));
    if(client == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        return 1;
    }
    client->socket = sockFD;

    pthread_t tID;
    pthread_create(&tID, NULL, threadRecvMsg, (void*) client);
    pthread_detach(tID);

    while(1){    
        //Escrever
        printf("Digite sua mensagem: ");
        memset(bufferMsg, 0, sizeof(bufferMsg));
        fgets(bufferMsg, MAX_SIZE_MSG, stdin);
        bufferMsg[strcspn(bufferMsg, "\n")]='\0';
        printf("\033[A\r\033[K[Você]: %s\n", bufferMsg);
        fflush(stdout);

        if(send(sockFD, bufferMsg, strlen(bufferMsg), 0) < 0){
            printf("[ERRO]: Erro ao enviar o conteúdo!");
            break;
        }
    }

    close(sockFD);
    return 0;
}

//Receber
void* threadRecvMsg(void *threadArgs){
    int valueRead;
    char bufferMsg[MAX_SIZE_MSG];
    DataClient *client = (DataClient*) threadArgs;

    while(1){
        memset(bufferMsg, 0, sizeof(bufferMsg));
        if((valueRead = recv(client->socket, bufferMsg, sizeof(bufferMsg) -1, 0)) <= 0){
            printf("\r\033[KConexão perdida com o servidor.\n");
            break;
        }
        if(valueRead > 0){
            printf("\r\033[K%s\nDigite sua mensagem: ", bufferMsg);
            fflush(stdout);
        }
    }

    free(client);
    pthread_exit(NULL);
}