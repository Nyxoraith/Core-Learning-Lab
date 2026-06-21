# 🧵 Multithreading Lab (Pthread-based Sockets)

Este diretório contém experimentos avançados de rede utilizando **Threads (pthread)** no Linux. O objetivo aqui é alcançar performance máxima de varredura e comunicação reduzindo o uso de recursos do sistema operacional.

> "High concurrency with minimal overhead."

## 🧠 Por que Multithreading?
Enquanto o modelo de [*Multiprocessing (Fork)*](../Multiprocessing/) cria clones pesados do processo atual, o **Multithreading** cria novos fluxos de execução que compartilham o mesmo espaço de memória. Isso resulta em:

* **Leveza Extrema:** O consumo de memória RAM despenca, pois não há duplicação de tabelas de páginas.
* **Troca de Contexto Rápida:** O Kernel do Linux gerencia threads de forma muito mais rápida do que processos inteiros.
* **Compartilhamento de Dados Direto:** A comunicação entre threads é nativa através do escopo global, eliminando a necessidade de complexos mecanismos de IPC.

## 📂 Projetos no Lab
### 💬 [Multi-Threaded Chat Server & Client](./ChatServer/)

Um sistema de chat em tempo real baseado na arquitetura Cliente-Servidor de alto desempenho e escalabilidade ao utilizar Multithreading para gerenciar múltiplos clientes simultâneos e Variáveis de Condição síncronas para desacoplar a entrega de mensagens e a escrita de logs.

### 🚀 [Asynchronous Threaded Portscanner](./PortScanner/)

Otimização de varredura TCP. Combina a divisão de carga em 100 threads com sockets não-bloqueantes e gerenciamento fino de timeout individual por porta.

---
## 🛠️ Desafios Avançados Superados Neste Lab
### ⚡ Sockets Não-Bloqueantes & Timeouts Customizados (Portscanner)
Para evitar o congelamento das threads ao escanear hosts remotos protegidos por firewalls (onde o `connect()` convencional trava por até 20 segundos), implementamos a transição do socket para o modo assíncrono usando `fcntl(sockFD, F_SETFL, flags | O_NONBLOCK)`.

### 🔄 Arquitetura Produtor-Consumidor com Variáveis de Condição (Chat)
Para evitar o gargalo clássico de I/O de rede e disco no servidor de chat, desacoplamos o recebimento de mensagens do seu processamento. As threads dos clientes atuam como **Produtoras**, injetando dados em filas circulares. Threads **Consumidoras** dedicadas operam em background manipulando o broadcast de rede e a escrita de logs em disco. A sincronização fina é feita via `pthread_cond_wait()` e `pthread_cond_signal()`, eliminando o desperdício de CPU por *busy-waiting*.

### 🔒 Sincronização de Memória Compartilhada & Mutex (Chat & Portscanner)
Diferente de processos isolados, threads compartilham a mesma memória, gerando o risco crítico de *Race Conditions* (condições de corrida). Implementamos travas de exclusão mútua (**Mutexes**) com `pthread_mutex_lock()` em cenários vitais:
* **No Portscanner:** Blindando o acesso concorrente à saída padrão (`stdout`) para evitar corrupção visual no terminal.
* **No Chat:** Protegendo ponteiros globais e arrays dinâmicos de conexões (`clientSockets` e `userList`) durante realocações de memória com `realloc()` em tempo de execução.