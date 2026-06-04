# 🧵 Multithreading Lab (Pthread-based Sockets)

Este diretório contém experimentos avançados de rede utilizando **Threads (pthread)** no Linux. O objetivo aqui é alcançar performance máxima de varredura e comunicação reduzindo o uso de recursos do sistema operacional.

> "High concurrency with minimal overhead."

## 🧠 Por que Multithreading?

Enquanto o modelo de [*Multiprocessing (Fork)*](../Multiprocessing/) cria clones pesados do processo atual, o **Multithreading** cria novos fluxos de execução que compartilham o mesmo espaço de memória. Isso resulta em:

* **Leveza Extrema:** O consumo de memória RAM despenca, pois não há duplicação de tabelas de páginas.

* **Troca de Contexto Rápida:** O Kernel do Linux gerencia threads de forma muito mais rápida do que processos inteiros.

* **Compartilhamento de Dados Direto:** A comunicação entre threads é nativa através do escopo global, eliminando a necessidade de complexos mecanismos de IPC.

## 📂 Projetos no Lab

### 🚀 [Asynchronous Threaded Portscanner](./PortScanner/)

O ápice da otimização de varredura TCP. Combina a divisão de carga em 100 threads com sockets não-bloqueantes e gerenciamento fino de timeout individual por porta.

---
## 🛠️ Desafios Avançados Superados Neste Lab

### ⚡ Non-blocking Sockets & Custom Timeouts
Para evitar o congelamento das threads ao escanear hosts remotos protegidos por firewalls (onde o `connect()` trava por até 20 segundos), implementamos a transição do socket para o modo assíncrono usando `fcntl(sockFD, F_SETFL, flags | O_NONBLOCK)`. O controle do tempo limite foi delegado à multiplexação de I/O via `select()` monitorando o descritor de escrita (`write_fds`).

### 🔒 Sincronização de Threads (Race Conditions & Mutex)
Com múltiplas threads escrevendo simultaneamente na saída padrão (`stdout`), haveria o risco de colisões de dados no terminal. Para garantir a integridade dos alertas visuais, implementamos travas de exclusão mútua (**Mutexes**) com `pthread_mutex_lock()`, blindando a função `printf()`.