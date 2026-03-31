#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 4444
#define MAX_SIZE 1024

int main(){
    int sockFD, newSocket, valueRead, maxFD, nClients, qtClients, oldCapacity;
    int* clientSockets;
    int* tmpClientSockets;
    char sendMsg[1024];
    char recvMsg[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t addrlenClient = sizeof(clientAddr);
    socklen_t addrlenServer = sizeof(serverAddr);
    fd_set readFDs;

    qtClients = 10;
    nClients = 0;
    clientSockets = (int*) malloc(sizeof(int) * qtClients);
    if(clientSockets == NULL){
        printf("[ERRO]: Erro ao alocar memória!");
        return 1;
    }

    sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if(sockFD < 0){
        printf("[ERRO]: Erro ao criar o socket!");
        return 1;
    }

    memset(&serverAddr, 0, addrlenServer);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if(bind(sockFD, (struct sockaddr *) &serverAddr, addrlenServer) < 0){
        printf("[ERRO] Erro no Bind!");
        return 1;
    }

    if((listen(sockFD, 5)) < 0){
        printf("[ERRO] Erro no Listen!");
        return 1;
    }

    printf("Aguardando conexão na porta %d...\n", PORT);
    while(1){
        FD_ZERO(&readFDs);
        FD_SET(0, &readFDs);
        FD_SET(sockFD, &readFDs);
        maxFD = sockFD;

        for(int i=0; i<qtClients; i++){
            if(clientSockets[i]>0){
                FD_SET(clientSockets[i], &readFDs);
            }

            if(clientSockets[i] > maxFD){
                maxFD = clientSockets[i];
            }
        }

        if (select(maxFD + 1, &readFDs, NULL, NULL, NULL) < 0) {
            perror("Erro no select");
            break;
        }

        if(FD_ISSET(sockFD, &readFDs)){
            if((newSocket = accept(sockFD, (struct sockaddr *) &clientAddr, &addrlenClient)) < 0){
                printf("[ERRO] Erro ao aceitar a conexão!");
                return 1;
            }

            for(int i=0; i<qtClients; i++){
                if(clientSockets[i]==0){
                    clientSockets[i] = newSocket;
                    printf("\r\033[K\nCliente %d conectado\n[IP]: %s\n[PORTA]: %d\n\n", i+1, inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
                    nClients++;
                    if(nClients >= qtClients){
                        oldCapacity = qtClients;
                        qtClients += 10;
                        tmpClientSockets = realloc(clientSockets, sizeof(int) * qtClients);
                        if(tmpClientSockets == NULL){
                            printf("[ERRO]: Erro ao re-alocar memória!");
                            return 1;
                        }
                        clientSockets = tmpClientSockets;

                        for(int i=oldCapacity; i<qtClients; i++){
                            clientSockets[i] = 0;
                        }
                    }
                    break;
                }
            }
            printf("\r\033[KDigite sua mensagem: ");
            fflush(stdout);
        }

        for(int i=0; i<qtClients; i++){
            int sd = clientSockets[i];

            if(sd > 0 && FD_ISSET(sd, &readFDs)){
                memset(recvMsg, 0, sizeof(recvMsg));
                valueRead = recv(sd, recvMsg, sizeof(recvMsg) -1, 0);

                if (valueRead == 0) {
                    getpeername(sd, (struct sockaddr*)&clientAddr, &addrlenClient);
                    printf("\r\033[K\nCliente %d desconectado\n[IP]: %s\n[PORTA]: %d\n\n", i+1, inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
                    close(sd);
                    clientSockets[i] = 0;
                    nClients--;
                }

                if (valueRead > 0){
                    printf("\r\033[K[CLIENTE %d]: %s\n", i+1, recvMsg);
                }

                printf("Digite sua mensagem: ");
                fflush(stdout);
            }
        }

        if(FD_ISSET(0, &readFDs)){
            fgets(sendMsg, MAX_SIZE, stdin);
            sendMsg[strcspn(sendMsg, "\n")]='\0';
            printf("\033[A\r\033[K");
            fflush(stdout);
            for (int i=0; i <qtClients; i++) {
                if (clientSockets[i] > 0) {
                    if(send(clientSockets[i], sendMsg, strlen(sendMsg), 0) < 0){
                        printf("[ERRO]: Erro ao enviar o conteúdo!");
                        break;
                    }
                }
            }

            printf("[Você]: %s\n", sendMsg);

            if(strcmp(sendMsg, "/quit")==0){
                printf("Saindo...\n");
                free(clientSockets);
                break;
            }

            printf("Digite sua mensagem: ");
            fflush(stdout);
        }
    }

    close(sockFD);
    return 0;
}
