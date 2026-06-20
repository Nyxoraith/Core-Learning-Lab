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
#define MAX_SIZE_TMP 2048
#define LOG_SIZE 100
#define CMD_SIZE 3

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
    int qt;
    LogEntry args[LOG_SIZE];
} QueueLog;

typedef struct {
    int flag;
    int senderSocket;
    char username[32];
    char message[MAX_SIZE_MSG];
} MsgEntry;

typedef struct {
    int init;
    int final;
    int qt;
    MsgEntry args[LOG_SIZE];
} QueueMsg;

typedef struct {
    int qtClients;
    int nClients;
    int *clientSockets;
    char **userList;
    QueueLog *queueLog;
    QueueMsg *queueMsg;
    pthread_mutex_t logLock;
    pthread_mutex_t msgLock;
    pthread_mutex_t clientSocketsLock;
    pthread_cond_t queueMsgLogArrived;
    pthread_cond_t queueMsgArrived;
} ServerContext;

typedef struct {
    int id;
    int port;
    int socket;
    int indexMemory;
    char addr[20];
    char username[32];
    ServerContext *serverContext;
} DataClient;

int chatServer();
QueueLog* InitQueueLog();
QueueMsg* InitQueueMsg();
ServerContext* InitServer(QueueLog *queueLog, QueueMsg *queueMsg);
void* threadClient(void *threadArgs);
void* threadSendMsg(void *threadArgs);
void* threadLogger(void *threadArgs);
int serverCommands(const char *commands[], int size, char *buffer, DataClient *client);

int main(){
    if(chatServer()==1){
        return 1;
    }
    
    return 0;
}

int chatServer(){
    int sockFD, newSocket, clientID = 0, oldCapacity;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t addrlenServer = sizeof(serverAddr);
    socklen_t addrlenClient = sizeof(clientAddr);

    QueueLog *queueLog = InitQueueLog();
    if(queueLog == NULL){
        return 1;
    }

    QueueMsg *queueMsg = InitQueueMsg();
    if(queueMsg == NULL){
        free(queueLog);
        return 1;
    }

    ServerContext *server = InitServer(queueLog, queueMsg);
    if(server == NULL){
        free(queueLog);
        free(queueMsg);
        return 1;
    }

    pthread_mutex_init(&server->logLock, NULL);
    pthread_mutex_init(&server->msgLock, NULL);
    pthread_mutex_init(&server->clientSocketsLock, NULL);
    pthread_cond_init(&server->queueMsgLogArrived, NULL);
    pthread_cond_init(&server->queueMsgArrived, NULL);

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

    pthread_t sendMsgThread;
    pthread_create(&sendMsgThread, NULL, threadSendMsg, (void*) server);
    pthread_detach(sendMsgThread);

    while(1){
        if((newSocket = accept(sockFD, (struct sockaddr*) &clientAddr, &addrlenClient)) < 0){
            perror("[ERRO] Erro no Accept!");
            continue;
        }

        int indexMemory = -1;
        pthread_mutex_lock(&server->clientSocketsLock);
        for(int i=0; i<server->qtClients; i++){
            if(server->clientSockets[i] == 0){
                indexMemory = i;
                server->clientSockets[i] = newSocket;
                server->nClients++;

                if(server->nClients >= server->qtClients){
                    oldCapacity = server->qtClients;
                    server->qtClients += 5;

                    int *tmpClientSockets = realloc(server->clientSockets, sizeof(int) * server->qtClients);
                    if(tmpClientSockets == NULL){
                        perror("[ERRO]: Erro ao re-alocar memória!");
                        pthread_mutex_unlock(&server->clientSocketsLock);
                        close(newSocket);
                        return 1;
                    }
                    server->clientSockets = tmpClientSockets;

                    char **tmpUserList = realloc(server->userList, sizeof(char *) * server->qtClients);
                    if(tmpUserList == NULL){
                        perror("[ERRO]: Erro ao re-alocar memória!");
                        pthread_mutex_unlock(&server->clientSocketsLock);
                        close(newSocket);
                        return 1;
                    }
                    server->userList = tmpUserList;

                    for(int j=oldCapacity; j<server->qtClients; j++){
                        server->clientSockets[j] = 0;
                        server->userList[j] = 0;
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
        
        clientID++;
        client->id = clientID;
        client->port = ntohs(clientAddr.sin_port);
        client->socket = newSocket;
        client->indexMemory = indexMemory;
        client->addr[sizeof(client->addr) - 1] = '\0';
        strncpy(client->addr, inet_ntoa(clientAddr.sin_addr), sizeof(client->addr) - 1);
        client->serverContext = server;

        pthread_t tID;
        pthread_create(&tID, NULL, threadClient, (void*) client);
        pthread_detach(tID);
    }

    close(sockFD);
    pthread_mutex_destroy(&server->logLock);
    pthread_mutex_destroy(&server->msgLock);
    pthread_mutex_destroy(&server->clientSocketsLock);
    pthread_cond_destroy(&server->queueMsgLogArrived);
    pthread_cond_destroy(&server->queueMsgArrived);
    free(server->clientSockets);
    free(server->userList);
    free(server->queueLog);
    free(server->queueMsg);
    free(server);
    return 0;
}

QueueLog* InitQueueLog(){
    QueueLog *queueLog = malloc(sizeof(QueueLog));
    if(queueLog == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        return NULL;
    }

    queueLog->init = 0;
    queueLog->final = 0;
    queueLog->qt = 0;

    return queueLog;
}

QueueMsg* InitQueueMsg(){
    QueueMsg *queueMsg = malloc(sizeof(QueueMsg));
    if(queueMsg == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        return NULL;
    }

    queueMsg->init = 0;
    queueMsg->final = 0;
    queueMsg->qt = 0;

    return queueMsg;
}

ServerContext* InitServer(QueueLog *queueLog, QueueMsg *queueMsg){
    ServerContext *server = malloc(sizeof(ServerContext));
    if(server == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        return NULL;
    }

    server->qtClients = 5;
    server->nClients = 0;
    server->clientSockets = NULL;
    server->queueLog = queueLog;
    server->queueMsg = queueMsg;

    server->clientSockets = (int *) calloc(server->qtClients, sizeof(int));
    if(server->clientSockets == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        free(server);
        return NULL;
    }

    server->userList = (char**) calloc(server->qtClients, sizeof(char*));
    if(server->userList == NULL){
        perror("[ERRO] Erro ao Alocar Memória!");
        free(server->clientSockets);
        free(server);
        return NULL;
    }

    return server;
}

void* threadClient(void *threadArgs){
    int bytesRead;
    char buffer[MAX_SIZE_MSG];
    const char *commands[CMD_SIZE] = {"/nick", "/list", "/quit"};

    DataClient *client = (DataClient*) threadArgs;
    ServerContext *server = client->serverContext;
    QueueLog *queueLog = server->queueLog;
    QueueMsg *queueMsg = server->queueMsg;
    
    if((bytesRead = recv(client->socket, buffer, MAX_SIZE_MSG - 1, 0)) > 0){
        buffer[bytesRead] = '\0';
        buffer[strcspn(buffer, "\r\n")] = '\0';
        strcpy(client->username, buffer);
    }
    
    printf("[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Conectado]\n", client->addr, client->port, client->id, client->username);

    // Guarda o username do cliente na userList
    pthread_mutex_lock(&server->clientSocketsLock);
    server->userList[client->indexMemory] = client->username;
    pthread_mutex_unlock(&server->clientSocketsLock);

    // Guardar o log de conexão do cliente
    pthread_mutex_lock(&server->logLock);
    if(queueLog->qt < LOG_SIZE){
        LogEntry *newLog = &queueLog->args[queueLog->final];
        
        newLog->flag = 1;
        newLog->id = client->id;
        newLog->port = client->port;
        strcpy(newLog->addr, client->addr);
        strcpy(newLog->username, client->username);
        queueLog->final = (queueLog->final + 1) % LOG_SIZE;
        queueLog->qt++;

        pthread_cond_signal(&server->queueMsgLogArrived);
    }
    pthread_mutex_unlock(&server->logLock);

    // Guardar a mensagem de conexão na fila de mensagens para envio aos outros clientes
    pthread_mutex_lock(&server->msgLock);
    if(queueMsg->qt < LOG_SIZE){
        MsgEntry *newMsg = &queueMsg->args[queueMsg->final];
        
        newMsg->flag = 1;
        newMsg->senderSocket = client->socket;
        strcpy(newMsg->username, client->username);
        queueMsg->final = (queueMsg->final + 1) % LOG_SIZE;
        queueMsg->qt++;

        pthread_cond_signal(&server->queueMsgArrived);
    }
    pthread_mutex_unlock(&server->msgLock);


    // Loop para receber mensagens do cliente
    while((bytesRead = recv(client->socket, buffer, MAX_SIZE_MSG - 1, 0)) > 0){
        buffer[bytesRead] = '\0';
        buffer[strcspn(buffer, "\r\n")] = '\0';

        int cmdStatus = serverCommands(commands, CMD_SIZE, buffer, client);
        if(cmdStatus == 0){
            continue;
        }else if (cmdStatus == -1){
            break;
        }

        printf("[%s]: %s\n", client->username, buffer);

        // Guardar o log da mensagem do cliente
        pthread_mutex_lock(&server->logLock);
        if(queueLog->qt < LOG_SIZE){
            LogEntry *newLog = &queueLog->args[queueLog->final];
            
            newLog->flag = 2;
            newLog->id = client->id;
            newLog->port = client->port;
            strcpy(newLog->addr, client->addr);
            strcpy(newLog->username, client->username);
            strcpy(newLog->message, buffer);
            queueLog->final = (queueLog->final + 1) % LOG_SIZE;
            queueLog->qt++;

            pthread_cond_signal(&server->queueMsgLogArrived);
        }
        pthread_mutex_unlock(&server->logLock);

        // Guardar a mensagem na fila de mensagens para envio aos outros clientes
        pthread_mutex_lock(&server->msgLock);
        if(queueMsg->qt < LOG_SIZE){
            MsgEntry *newMsg = &queueMsg->args[queueMsg->final];
            
            newMsg->flag = 2;
            newMsg->senderSocket = client->socket;
            strcpy(newMsg->username, client->username);
            strcpy(newMsg->message, buffer);
            queueMsg->final = (queueMsg->final + 1) % LOG_SIZE;
            queueMsg->qt++;

            pthread_cond_signal(&server->queueMsgArrived);
        }
        pthread_mutex_unlock(&server->msgLock);
    }

    printf("%s saiu do chat.\n", client->username);
    
    // Remover o cliente da lista de clientes conectados
    pthread_mutex_lock(&server->clientSocketsLock);
    server->clientSockets[client->indexMemory] = 0;
    server->userList[client->indexMemory] = NULL;
    server->nClients--;
    pthread_mutex_unlock(&server->clientSocketsLock);

    // Guardar o log de desconexão do cliente
    pthread_mutex_lock(&server->logLock);
    if(queueLog->qt < LOG_SIZE){
        LogEntry *newLog = &queueLog->args[queueLog->final];
        
        newLog->flag = 0;
        newLog->id = client->id;
        newLog->port = client->port;
        strcpy(newLog->addr, client->addr);
        strcpy(newLog->username, client->username);
        queueLog->final = (queueLog->final + 1) % LOG_SIZE;
        queueLog->qt++;

        pthread_cond_signal(&server->queueMsgLogArrived);
    }
    pthread_mutex_unlock(&server->logLock);

    // Guardar a mensagem de desconexão na fila de mensagens para envio aos outros clientes
    pthread_mutex_lock(&server->msgLock);
    if(queueMsg->qt < LOG_SIZE){
        MsgEntry *newMsg = &queueMsg->args[queueMsg->final];
        
        newMsg->flag = 0;
        newMsg->senderSocket = client->socket;
        strcpy(newMsg->username, client->username);
        queueMsg->final = (queueMsg->final + 1) % LOG_SIZE;
        queueMsg->qt++;

        pthread_cond_signal(&server->queueMsgArrived);
    }
    pthread_mutex_unlock(&server->msgLock);

    close(client->socket);
    free(client);
    pthread_exit(NULL);
}

void* threadSendMsg(void *threadArgs){
    char tmpBuffer[MAX_SIZE_TMP];
    ServerContext *server = (ServerContext*) threadArgs;
    QueueMsg *queueMsg = server->queueMsg;
    MsgEntry newMsg;

    while(1){
        pthread_mutex_lock(&server->msgLock);
        while(queueMsg->qt == 0){
            pthread_cond_wait(&server->queueMsgArrived, &server->msgLock);
        }
        newMsg = queueMsg->args[queueMsg->init];
        queueMsg->init = (queueMsg->init + 1) % LOG_SIZE;
        queueMsg->qt--;
        pthread_mutex_unlock(&server->msgLock);

        if(newMsg.flag == 0){ 
            snprintf(tmpBuffer, sizeof(tmpBuffer), "%s saiu no chat.\n", newMsg.username);
        }else if(newMsg.flag == 1){
            snprintf(tmpBuffer, sizeof(tmpBuffer), "%s entrou no chat.\n", newMsg.username);
        }else if(newMsg.flag == 2){
            snprintf(tmpBuffer, sizeof(tmpBuffer), "[%s]: %s\n", newMsg.username, newMsg.message);
        }
        
        // Enviar a mensagem para os outros clientes
        pthread_mutex_lock(&server->clientSocketsLock);
        for(int i=0; i<server->qtClients; i++){
            if(server->clientSockets[i] != 0){
                if(newMsg.flag == 2 && server->clientSockets[i] == newMsg.senderSocket){
                    continue;
                }
                send(server->clientSockets[i], tmpBuffer, strlen(tmpBuffer), 0);
            }
        }
        pthread_mutex_unlock(&server->clientSocketsLock);
    }
    pthread_exit(NULL);
}

void* threadLogger(void *threadArgs){
    ServerContext *server = (ServerContext*) threadArgs;
    QueueLog *queueLog = server->queueLog;
    LogEntry *newLog;

    while(1){
        pthread_mutex_lock(&server->logLock);
        while(queueLog->qt == 0){
            pthread_cond_wait(&server->queueMsgLogArrived, &server->logLock);
        }
        newLog = &queueLog->args[queueLog->init];
        queueLog->init = (queueLog->init + 1) % LOG_SIZE;   
        queueLog->qt--;
        pthread_mutex_unlock(&server->logLock);

        FILE *logFile = fopen("logs.txt", "a");
        if (logFile == NULL) {
            perror("[ERRO] Erro ao abrir ou criar o arquivo.\n");
            pthread_exit(NULL);
        }

        if(newLog->flag == 0){
            fprintf(logFile, "[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Desconectado]\n", newLog->addr, newLog->port, newLog->id, newLog->username);
        }else if(newLog->flag == 1){
            fprintf(logFile, "[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Conectado]\n", newLog->addr, newLog->port, newLog->id, newLog->username);
        }else if (newLog->flag == 2){
            fprintf(logFile, "[IP]: %s - [PORT]: %d - [ClientID]: %d - [Username]: %s - [Mensagem]: %s\n", newLog->addr, newLog->port, newLog->id, newLog->username, newLog->message);
        }

        fclose(logFile);
    }
    pthread_exit(NULL);
}

int serverCommands(const char *commands[], int size, char *buffer, DataClient *client){
    char tmpBuffer[MAX_SIZE_MSG];
    ServerContext *server = client->serverContext;

    for(int i=0; i<size; i++){
        if(strcmp(commands[i], buffer) == 0){
            if(i == 0){ //Nick
                snprintf(tmpBuffer, sizeof(tmpBuffer), "Seu usuário é: %s\n", client->username);
                send(client->socket, tmpBuffer, strlen(tmpBuffer), 0);
                return 0;
            }else if(i == 1){ //List
                pthread_mutex_lock(&server->clientSocketsLock);
                strcpy(tmpBuffer, "--- Usuários Online ---\n"); 
                for(int j=0; j<server->qtClients; j++){
                    if(server->userList[j] != NULL){
                        strcat(tmpBuffer, "-> ");
                        strcat(tmpBuffer, server->userList[j]);
                        strcat(tmpBuffer, "\n");
                    }
                }
                pthread_mutex_unlock(&server->clientSocketsLock);
                send(client->socket, tmpBuffer, strlen(tmpBuffer), 0);
                return 0;
            }else if(i == 2){ //Quit
                strcpy(tmpBuffer,"Desconectando do servidor... Até logo!\n");
                send(client->socket, tmpBuffer, strlen(tmpBuffer), 0);
                return -1;
            }
        }
    }
    return 1;
}