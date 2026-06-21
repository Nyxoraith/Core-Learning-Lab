# 🐧 Linux Low-Level Development Lab
Este diretório funciona como um laboratório de engenharia de sistemas focado em programação de baixo nível utilizando a API de Sockets do Linux e concorrência nativa em C.

O objetivo central deste repositório não é apenas construir aplicações de rede, mas sim investigar como o Kernel do Linux gerencia recursos, escala conexões, troca contextos e lida com concorrência sob diferentes paradigmas de arquitetura.

> "To understand software architecture, you must first understand how it talks to the Kernel."

## 🧠 A Linha de Evolução do Lab
Escrever servidores funcionais em rede é simples; torná-los performáticos, tolerantes a falhas e eficientes no consumo de hardware é o verdadeiro desafio de engenharia. Este repositório está dividido em três abordagens arquiteturais distintas para resolver o problema da concorrência:

### 📂 Paradigmas Investigados
#### [🏍 I/O Multiplexing (Event-Driven System)](./IOMultiplexing/)

* **Foco:** Concorrência em um único processo e uma única thread.
* **Mecânica:** Utilização do `select()` para monitorar múltiplos *File Descriptors (FDs)* de forma síncrona. O programa delega ao Kernel a tarefa de avisar quando a rede ou o teclado têm dados prontos, eliminando loops de espera ativa.
* **Ideal para:** Sistemas que precisam de baixo overhead de memória e lidam com muitas conexões que passam a maior parte do tempo ociosas.

#### [✈ Multiprocessing (Isolamento via Fork)](./Multiprocessing/)

* **Foco:** Tolerância a falhas e paralelismo real.
* **Mecânica:** Divisão de carga duplicando o espaço de endereçamento do processo através do `fork()`. Cada cliente ou fatia de carga ganha um ambiente de memória completamente isolado e gerenciado de forma independente pelo *scheduler* do Linux.
* **Ideal para:** Tarefas que demandam alto uso de CPU e sistemas onde o crash de um cliente (ex: Segmentation Fault) jamais pode derrubar o servidor principal.

#### [🚀 Multithreading (Concorrência Baseada em Pthreads)](./Multithreading/)

* **Foco:** Performance máxima, latência mínima e comunicação ágil.
* **Mecânica:** Criação de fluxos de execução paralelos dentro do mesmo espaço de memória usando a biblioteca *pthread*. Introduz a complexidade de sincronização fina através de *Mutexes* e Variáveis de Condição para evitar condições de corrida *(Race Conditions)* ao manipular recursos globais compartilhados.
* **Ideal para:** Sistemas de altíssima performance que trocam dados constantemente entre si e precisam de uma comunicação direta sem o custo pesado de mecanismos de *IPC (Inter-Process Communication)*.

### 🛠️ Conceitos de Core Linux Explorados
Ao navegar pelas subpastas, os projetos cobrem e demonstram na prática conceitos fundamentais do sistema operacional:

* **File Descriptors & Sockets:** Ciclo de vida completo de comunicação de rede TCP *(socket, bind, listen, accept, connect)*.
* **Sinais do Sistema:** Captura e tratamento de sinais de baixo nível como *SIGCHLD* para evitar processos zumbis na tabela do Kernel.
* **Gerenciamento de Memória Dinâmica:** Controle manual de buffers e arrays dinâmicos de conexões expandidos em tempo de execução através de `realloc()` e `calloc()`.
* **Manipulação de Terminais:** Uso de sequências de escape *ANSI (\033)* para renderização assíncrona limpa diretamente no terminal *(stdout)*.
