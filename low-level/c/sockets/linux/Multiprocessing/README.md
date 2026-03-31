# 🔱 Multiprocessing Lab (Fork-based Sockets)

Este diretório centraliza experimentos de rede que utilizam a criação de *Processos Filhos (fork)* para alcançar concorrência e isolamento no Linux.

> "Isolation is the best form of stability."

## 🧠 Por que Multiprocessing?
Diferente da [*multiplexação de I/O (Select)*](../IOMultiplexing/), o modelo de *Multiprocessing* delega cada tarefa a um novo processo independente. Isso oferece:

* **Isolamento Total:** Se um processo filho sofrer um crash (ex: Segmentation Fault), o servidor pai e os outros clientes permanecem intactos.
* **Paralelismo Real:** O Kernel do Linux distribui os processos entre os múltiplos núcleos do CPU, permitindo que tarefas pesadas (como centenas de conexões de rede) ocorram simultaneamente.
* **Simplicidade de Memória:** Cada processo possui seu próprio espaço de endereçamento, eliminando a necessidade inicial de travas de sincronização (locks/mutexes).

## 📂 Projetos no Lab
### 📡 Portscanner
Um scanner TCP de alta performance que divide o range de 65.535 portas entre múltiplos processos.

* **Destaque:** Redução de tempo de scan de 0.82s para 0.27s utilizando 100 processos simultâneos.
* **Conceitos:** Divisão de carga (workload balance), sincronização com `wait()` e medição de performance de CPU.

### 🤖 Forking C2 Prototype

Um protótipo de infraestrutura de Comando e Controle (C2) para execução remota de comandos.

* **Destaque:** Uso de `popen()` para *shell reverso* e tratamento de sinais para evitar processos zumbis.
* **Conceitos:** *SIGCHLD management*, `_exit()` vs `exit()`, e comunicação via *Pipes*.

---

## 🛠️ Desafios de Engenharia Superados

* **Zombie Process Management:** Implementação de estratégias para limpar a tabela de processos do sistema utilizando `signal(SIGCHLD, SIG_IGN)`.
* **Resource Leak Prevention:** Gerenciamento rigoroso de *File Descriptors (FDs)*, garantindo que sockets não utilizados sejam fechados tanto no pai quanto no filho para evitar exaustão de recursos do sistema.
* **Kernel Overhead:** Estudo do custo de criação de processos e o impacto das trocas de contexto (context switching) na performance global da aplicação.

## 📈 Próximos Passos
Após dominar o isolamento via processos, este laboratório evoluirá para o estudo de *Multithreading (pthreads)*, visando reduzir o consumo de memória e facilitar a comunicação entre tarefas concorrentes através de memória compartilhada.