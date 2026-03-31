# 🏗️ I/O Multiplexing Chat (Select)

Este módulo faz parte do laboratório de **Low-Level Sockets** e consiste em um Sistema de Chat Cliente-Servidor desenvolvido em C, utilizando a API de Sockets do Linux. O foco principal é a implementação de *I/O Multiplexing*, permitindo que o servidor gerencie múltiplas conversas simultâneas sem a necessidade de múltiplas threads ou processos.

---

## 🧠 O Conceito: Por que select()?

Diferente de um servidor simples que trava *(block)* esperando uma mensagem de um único cliente, o `select()` permite que o kernel monitore vários *File Descriptors (FDs)* ao mesmo tempo. O programa só "acorda" quando há dados prontos para serem lidos ou escritos.

## 🛠️ Características Técnicas:

* **Chat Multi-Client:** Suporte a múltiplas conexões simultâneas com broadcast de mensagens.
* **Single-Process Concurrency:** Gerencia múltiplos clientes sem o overhead de criar novos *processos (fork)* ou *threads*.
* **FD_SET Management:** Manipulação manual dos conjuntos de descritores para monitorar *stdin* (teclado) e *sockets* de rede simultaneamente.
* **Dynamic Memory:** Uso de `realloc` para expandir a lista de clientes conectados em tempo de execução.
* **Non-blocking feel:** O servidor permanece responsivo para comandos do administrador enquanto atende aos clientes.

## 📂 Estrutura dos Arquivos
* **`server.c`:** O núcleo do chat. Implementa a lógica de escuta, aceitação de novos clientes, expansão de memória e redistribuição de mensagens.

* **`client.c`:** Cliente interativo que também utiliza multiplexação para conseguir ler do servidor e do teclado ao mesmo tempo sem travar a interface.


## 🚀 Como Executar

Compile o Servidor e o Cliente:

1. Compile o Servidor e o Cliente:
```bash
gcc server.c -o server
gcc client.c -o client
```

2. Inicie o Servidor:
```bash
./server
```

3. Conecte múltiplos Clientes (em diferentes terminais):
```bash
./client
```

## 📈 Aprendizados e Desafios Técnicos
Nesta etapa do laboratório, os principais desafios superados foram:

* **Estado do FD_SET:** Aprendi que o `select()` modifica o conjunto de descritores original. Por isso, é necessário reconstruir o *FD_SET* a cada iteração do loop `while(1)`, garantindo que todos os sockets ativos continuem sendo monitorados.

* **Gestão de Memória Dinâmica:** Implementei o redimensionamento do array de sockets usando `realloc()`. Isso foi fundamental para entender como sistemas de baixo nível lidam com escalabilidade sem desperdiçar RAM.

* **ANSI Escape Codes:** Usei sequências como `\r\033[K` para limpar a linha do terminal e manter a interface do chat limpa (evitando que a mensagem recebida "atropele" o que o usuário está digitando).

* **Multiplexação no Cliente:** Percebi que o cliente também precisa do select(), caso contrário, ele ficaria travado no fgets() e não exibiria as mensagens recebidas do servidor até que o usuário pressionasse Enter.

---
## ⚙️ Evolução do Lab
Este projeto demonstra a base da comunicação síncrona. O próximo passo neste laboratório é a transição para modelos de [*Multiprocessing (Fork)*](../Multiprocessing/) e *Multithreading (Pthread)* para comparar performance e isolamento de recursos.