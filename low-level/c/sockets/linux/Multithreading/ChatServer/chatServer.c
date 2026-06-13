#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define PORT 4444
#define MAX_SIZE_MSG 1048 
#define MAX_SIZE_TMP 2048 
#define LOG_SIZE 100

typedef struct {
    int flag;
    int id;
    int port;
    char addr[20];
    char username[32];
    char message[MAX_SIZE_MSG];
} LogEntry;

typedef struct {
    int init;
    int final;
    int qtd;
    LogEntry args[LOG_SIZE];
} FilaLog;

typedef struct {
    int *clientSockets;
    int qtClients;
    int nClients;
    FilaLog *filaLog;
    pthread_mutex_t clientSocketsLock;
    pthread_mutex_t logLock;
    pthread_cond_t filaMensagemChegou;
} ServerContext;

typedef struct {
    int id;
    int port;
    int socket;
    char addr[20];
    char username[32];
    ServerContext *serverContext;
} DataClient;

void* clientThread(void *threadArgs);
void* threadLogger(void *threadArgs);

int main(){
    int sockFD, newSocket, clientID = 0, oldCapacity;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t addrlenServer = sizeof(serverAddr);
    socklen_t addrlenClient = sizeof(clientAddr);

    FilaLog *fila = malloc(sizeof(FilaLog));
    if(fila == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        return 1;
    }
    fila->init = 0;
    fila->final = 0;
    fila->qtd = 0;

    ServerContext *server = malloc(sizeof(ServerContext));
    if(server == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        return 1;
    }
    server->qtClients = 5;
    server->nClients = 0;
    server->clientSockets = NULL;
    server->filaLog = fila;

    pthread_mutex_init(&server->logLock, NULL);
    pthread_mutex_init(&server->clientSocketsLock, NULL);
    pthread_cond_init(&server->filaMensagemChegou, NULL);

    server->clientSockets = (int *) calloc(server->qtClients, sizeof(int));
    if(server->clientSockets == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        return 1;
    }

    sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if(sockFD < 0){
        perror("[ERRO]: Erro ao criar o socket!");
        return 1;
    }

    memset(&serverAddr, 0, addrlenServer);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if(bind(sockFD, (struct sockaddr *) &serverAddr, addrlenServer) < 0){
        perror("[ERRO] Erro no Bind!");
        return 1;
    }

    if((listen(sockFD, 5)) < 0){
        perror("[ERRO] Erro no Listen!");
        return 1;
    }

    printf("Aguardando conexão na porta %d...\n\n", PORT);

    pthread_t logThread;
    pthread_create(&logThread, NULL, threadLogger, (void*) server);
    pthread_detach(logThread);

    while(1){
        if((newSocket = accept(sockFD, (struct sockaddr*) &clientAddr, &addrlenClient)) < 0){
            perror("[ERRO] Erro no Accept!");
            continue;
        }

        clientID++;
        pthread_mutex_lock(&server->clientSocketsLock);
        for(int i=0; i<server->qtClients; i++){
            if(server->clientSockets[i] == 0){
                server->clientSockets[i] = newSocket;
                server->nClients++;

                if(server->nClients >= server->qtClients){
                    oldCapacity = server->qtClients;
                    server->qtClients += 5;

                    int *tmpClientSockets = realloc(server->clientSockets, sizeof(int) * server->qtClients);
                    if(tmpClientSockets == NULL){
                        perror("[ERRO]: Erro ao re-alocar memória!");
                        pthread_mutex_unlock(&server->clientSocketsLock);
                        return 1;
                    }
                    server->clientSockets = tmpClientSockets;

                    for(int j=oldCapacity; j<server->qtClients; j++){
                        server->clientSockets[j] = 0;
                    }
                }
                break;
            }
        }
        pthread_mutex_unlock(&server->clientSocketsLock);

        DataClient *client = malloc(sizeof(DataClient));
        if(client == NULL){
            perror("[ERRO] Erro ao Alocar Memória!");
            return 1;
        }

        client->id = clientID;
        client->port = ntohs(clientAddr.sin_port);
        client->socket = newSocket;
    
        client->addr[sizeof(client->addr) - 1] = '\0';
        strncpy(client->addr, inet_ntoa(clientAddr.sin_addr), sizeof(client->addr) - 1);

        client->serverContext = server;

        pthread_t tID;
        pthread_create(&tID, NULL, clientThread, (void*) client);
        pthread_detach(tID);
    }

    close(sockFD);
    pthread_mutex_destroy(&server->logLock);
    pthread_mutex_destroy(&server->clientSocketsLock);
    pthread_cond_destroy(&server->filaMensagemChegou);
    free(server->clientSockets);
    free(server->filaLog);
    free(server);
    return 0;
}

void* clientThread(void *threadArgs){
    DataClient *client = (DataClient*) threadArgs;
    ServerContext *server = client->serverContext;
    FilaLog *fila = server->filaLog;

    char buffer[MAX_SIZE_MSG];
    char tmpBuffer[MAX_SIZE_TMP];
    int bytesRead;

    if((bytesRead = recv(client->socket, buffer, MAX_SIZE_MSG - 1, 0)) > 0){
        buffer[bytesRead] = '\0';
        buffer[strcspn(buffer, "\r\n")] = '\0';
        strcpy(client->username, buffer);
    }
    
    pthread_mutex_lock(&server->logLock);
    if(fila->qtd < LOG_SIZE){
        LogEntry *newLog = &fila->args[fila->final];
        
        newLog->flag = 1;
        newLog->id = client->id;
        newLog->port = client->port;
        strcpy(newLog->addr, client->addr);
        strcpy(newLog->username, client->username);

        fila->final = (fila->final + 1) % LOG_SIZE;
        fila->qtd++;

        pthread_cond_signal(&server->filaMensagemChegou);
    }
    pthread_mutex_unlock(&server->logLock);
    
    pthread_mutex_lock(&server->clientSocketsLock);
    printf("[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Conectado]\n", client->addr, client->port, client->id, client->username);
    snprintf(buffer, sizeof(buffer), "[%s] entrou no chat.\n", client->username);
    for(int i=0; i<server->qtClients; i++){
        if (server->clientSockets[i] != 0 && server->clientSockets[i] != client->socket) {
            send(server->clientSockets[i], buffer, strlen(buffer), 0);
        }
    }
    pthread_mutex_unlock(&server->clientSocketsLock);

    while((bytesRead = recv(client->socket, buffer, MAX_SIZE_MSG - 1, 0)) > 0){
        buffer[bytesRead] = '\0';
        buffer[strcspn(buffer, "\r\n")] = '\0';
        printf("[%s]: %s\n", client->username, buffer);

        pthread_mutex_lock(&server->logLock);
        if(fila->qtd < LOG_SIZE){
            LogEntry *newLog = &fila->args[fila->final];
            
            newLog->flag = 2;
            newLog->id = client->id;
            newLog->port = client->port;
            strcpy(newLog->addr, client->addr);
            strcpy(newLog->username, client->username);
            strcpy(newLog->message, buffer);

            fila->final = (fila->final + 1) % LOG_SIZE;
            fila->qtd++;

            pthread_cond_signal(&server->filaMensagemChegou);
        }
        pthread_mutex_unlock(&server->logLock);


        pthread_mutex_lock(&server->clientSocketsLock);
        for(int i=0; i<server->qtClients; i++){
            if(server->clientSockets[i] != 0 && server->clientSockets[i] != client->socket){
                buffer[strcspn(buffer, "\n")] = '\0';
                snprintf(tmpBuffer, sizeof(tmpBuffer), "[%s]: %s\n", client->username, buffer);
                send(server->clientSockets[i], tmpBuffer, strlen(tmpBuffer), 0);
            }
        }
        pthread_mutex_unlock(&server->clientSocketsLock);
    }

    printf("%s saiu do chat.\n", client->username);

    pthread_mutex_lock(&server->clientSocketsLock);
    for(int i=0; i<server->qtClients; i++){
        if(server->clientSockets[i] == client->socket){
            server->clientSockets[i] = 0;
            server->nClients--;
            break;
        }
    }
    pthread_mutex_unlock(&server->clientSocketsLock);


    pthread_mutex_lock(&server->logLock);
    if(fila->qtd < LOG_SIZE){
        LogEntry *newLog = &fila->args[fila->final];
        
        newLog->flag = 0;
        newLog->id = client->id;
        newLog->port = client->port;
        strcpy(newLog->addr, client->addr);
        strcpy(newLog->username, client->username);

        fila->final = (fila->final + 1) % LOG_SIZE;
        fila->qtd++;

        pthread_cond_signal(&server->filaMensagemChegou);
    }
    pthread_mutex_unlock(&server->logLock);
         
    pthread_mutex_lock(&server->clientSocketsLock);
    snprintf(buffer, sizeof(buffer), "%s saiu do chat.\n", client->username);
    for(int i=0; i<server->qtClients; i++){
        if(server->clientSockets[i] != 0){
            send(server->clientSockets[i], buffer, strlen(buffer), 0);
        }
    }
    pthread_mutex_unlock(&server->clientSocketsLock);

    close(client->socket);
    free(client);
    pthread_exit(NULL);
}

void* threadLogger(void *threadArgs){
    ServerContext *server = (ServerContext*) threadArgs;
    FilaLog *fila = server->filaLog;
    LogEntry newLog;

    while(1){
        pthread_mutex_lock(&server->logLock);

        while(fila->qtd == 0){
            pthread_cond_wait(&server->filaMensagemChegou, &server->logLock);
        }

        LogEntry *tmpLogs = &fila->args[fila->init];

        newLog = *tmpLogs;

        fila->init = (fila->init + 1) % LOG_SIZE;   
        fila->qtd--;
        pthread_mutex_unlock(&server->logLock);

        FILE *logFile = fopen("logs.txt", "a");
        if (logFile == NULL) {
            perror("[ERRO] Erro ao abrir ou criar o arquivo.\n");
            pthread_exit(NULL);
        }

        if(newLog.flag == 0){
            fprintf(logFile, "[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Desconectado]\n", newLog.addr, newLog.port, newLog.id, newLog.username);
        }else if(newLog.flag == 1){
            fprintf(logFile, "[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Conectado]\n", newLog.addr, newLog.port, newLog.id, newLog.username);
        }else if (newLog.flag == 2){
            fprintf(logFile, "[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Mensagem]: %s\n", newLog.addr, newLog.port, newLog.id, newLog.username, newLog.message);
        }

        fclose(logFile);
    }
    pthread_exit(NULL);
}