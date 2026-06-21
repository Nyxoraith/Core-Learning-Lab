# 💬 Multi-Threaded Chat Server & Client (POSIX Sockets & Condition Variables)

Este projeto consiste em um sistema de chat em tempo real baseado na arquitetura Cliente-Servidor desenvolvido em C para ambientes Linux. Ele atinge alto desempenho e escalabilidade ao utilizar Multithreading para gerenciar múltiplos clientes simultâneos e Variáveis de Condição síncronas para desacoplar a entrega de mensagens e a escrita de logs.

## 🧠 O Desafio: Evitar Gargalos de I/O em Chats Concorrentes

Em um servidor de chat multithread convencional, se a thread que escuta um cliente específico tentar repassar a mensagem recebida para todos os outros usuários conectados ou gravá-la em disco imediatamente, ela ficará travada esperando operações de I/O de rede e disco terminarem. Se um único cliente tiver uma conexão lenta, todo o fluxo do servidor congela.

A solução aplicada aqui adota o padrão **Producer-Consumer** (Produtor-Consumidor). As threads dos clientes apenas produzem dados rapidamente e os inserem em duas **filas circulares** estáticas (QueueLog e QueueMsg). Threads especializadas em background **(threadSendMsg e threadLogger)** consomem essas filas de forma *assíncrona*, notificadas via Variáveis de Condição, garantindo que o recebimento de mensagens nunca seja bloqueado por gargalos de I/O.

## 🛠️ Características Técnicas

* **Desacoplamento por Filas Síncronas:** Implementação de duas filas circulares protegidas por *Mutexes* independentes: uma focada no broadcast de mensagens de rede e outra dedicada ao log em disco (logs.txt).

* **Sinalização Dinâmica por Variáveis de Condição:** Uso de *pthread_cond_wait()* e *pthread_cond_signal()* para colocar as threads de broadcast e logging em modo de espera de baixo consumo de CPU até que novas mensagens ou conexões cheguem.

* **Gerenciamento Dinâmico de Clientes:** O servidor monitora a capacidade máxima de conexões e realoca memória em tempo de execução via *realloc()* para expandir o array de descritores de sockets e a lista de usuários online (userList) em blocos de 5 slots.

* **Isolamento de Regiões Críticas:** Aplicação rigorosa de três travas de exclusão mútua *(logLock, msgLock e clientSocketsLock)* para blindar estruturas globais compartilhadas contra **Race Conditions** (condições de corrida).

* **Varredura ANSI no Cliente:** O cliente utiliza sequências de escape *ANSI (\033[A\r\033[K)* para manipular o terminal em tempo de execução, permitindo que mensagens recebidas de outros usuários atualizem a tela sem corromper o prompt de digitação atual do usuário (Digite sua mensagem: ).

## 🕹️ Comandos Suportados no Chat

O servidor intercepta mensagens iniciadas por barras e as processa como comandos de controle:

* **/nick** - Retorna ao cliente o seu nome de usuário atualmente registrado no servidor.

* **/list** - Lista em tempo real todos os usernames dos usuários que estão online no chat.

* **/quit** - Envia uma mensagem de despedida, fecha o descritor de arquivo do socket e desconecta o cliente com segurança.

## 📂 Estrutura dos Arquivos
* [**server.c:**](./server.c) Motor do servidor. Responsável pelo ciclo de vida dos sockets *(socket, bind, listen, accept)*, gerência de memória das filas, monitoramento de comandos internos e despacho das threads operacionais.

* [**client.c:**](./client.c) Interface do usuário. Opera de maneira bidirecional dividindo-se entre o fluxo principal de envio de mensagens do teclado e uma thread dedicada **(threadRecvMsg)** exclusiva para escuta de rede.

### 🚀 Como Executar

1. Compilação
Compile o servidor e o cliente linkando a biblioteca POSIX Threads (-pthread):

```Bash
# Compilar o Servidor
gcc server.c -o server -pthread

# Compilar o Cliente
gcc client.c -o client -pthread
```
2. Execução
Inicie o servidor em um terminal (ele escutará na porta padrão 4444):

```Bash
./server
```

Em outros terminais, instancie quantos clientes desejar para iniciar a conversação:

```Bash
./client
```

---

## 📈 Aprendizados e Desafios Técnicos

* **Thread Detachment (Desacoplamento):** Compreendi o uso de *pthread_detach()*. Ao marcar as threads como desacopladas, o Kernel libera automaticamente todos os recursos de memória associados a elas assim que terminam a execução, eliminando a necessidade de um *pthread_join()* bloqueante na thread principal.

* **Mecânica do Produtor-Consumidor com Variáveis de Condição:** Entendi que o *pthread_cond_wait* libera o Mutex associado temporariamente enquanto espera o sinal *(signal)*, reativando a trava imediatamente ao acordar. Isso evita o consumo de 100% de CPU que ocorreria em um loop de **busy-waiting** (espera ativa).

* **Gerenciamento de Concorrência em Estruturas de Dados:** Vivenciei o desafio de coordenar múltiplas threads acessando o mesmo array de sockets. Sem a trava *clientSocketsLock*, a realocação de memória por uma thread enquanto outra tenta enviar mensagens causaria falhas de segmentação (Segmentation Fault).

* **Tratamento de Strings em Protocolos de Texto:** A manipulação de buffers brutos recebidos via TCP exigiu cuidados como a remoção de quebras de linha (\r\n) geradas por diferentes sistemas operacionais utilizando strcspn, garantindo que strings comparadas via strcmp fossem validadas corretamente nos comandos.