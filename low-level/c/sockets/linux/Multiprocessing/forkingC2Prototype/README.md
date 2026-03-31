# 🔱 Forking C2 Prototype (Remote Command Execution)

Este módulo demonstra a implementação de um modelo simplificado de *Command & Control (C2)* utilizando a técnica de *Multiprocessing* no Linux. O objetivo é estabelecer uma conexão reversa onde o servidor envia comandos do sistema e o agente os executa remotamente, devolvendo o output.

## 🧠 O Conceito: Multiprocessing no C2

Nesta implementação, o servidor utiliza a syscall `fork()` para cada nova conexão recebida. Isso garante que cada "vítima" *(beacon)* seja tratada em um processo isolado. Se uma conexão cair ou travar, o servidor principal continua ouvindo novas conexões sem interrupções.

## 🛠️ Características Técnicas

* **Process Isolation:** Cada *beacon* conectado possui seu próprio espaço de memória e *PID* dedicado.

* **Remote Execution:** O beacon utiliza `popen()` para criar um *pipe* com o shell do sistema, permitindo a execução de comandos como `whoami`, `ls`, `ifconfig`, etc.

* **Zombie Prevention:** Implementação de `signal(SIGCHLD, SIG_IGN)` para garantir que o Kernel limpe automaticamente os processos filhos finalizados, evitando a poluição da tabela de processos.

* **Automated Handshake:** O servidor está programado para enviar um comando inicial `(whoami)` assim que a conexão é estabelecida.

## 📂 Estrutura dos Arquivos

* **`c2-server.c`:** O servidor C2 *(Painel)*. Gerencia as conexões e dispara processos filhos para interagir com cada *agente*.

* **`beacon.c`:** O agente *(Beacon)*. Conecta-se ao servidor, aguarda comandos, executa-os no shell local e transmite o resultado de volta.

## 🚀 Como Executar

1. Compile os binários:
```bash
gcc c2-server.c -o c2-server
gcc beacon.c -o beacon
```

2. Inicie o Servidor C2:
```bash
./c2-server
```

3. Execute o Beacon (em outra máquina ou terminal):
```bash
./agent
```

## 📈 Aprendizados e Desafios Técnicos

* **Manipulação de Pipes:** O uso de `popen()` e `pclose()` foi essencial para capturar o *stdout* de comandos do sistema e transformá-los em *buffers* de texto para envio via *socket*.

* **Gerenciamento de Processos:** Entendi a importância de fechar os *file descriptors* desnecessários no processo filho `close(sockFD)` e no pai `close(newSocket)` para evitar vazamento de recursos.

* **Invisibilidade Operacional:** A técnica de *SIG_IGN* para *SIGCHLD* é um "truque sujo" eficiente em *Red Team* para manter o sistema limpo de processos zumbis `<defunct>`, que são sinais claros de atividade maliciosa para administradores.

* **Escalabilidade Simples:** O modelo de *fork* é robusto para poucos *agentes*, mas me permitiu visualizar a necessidade futura de *Threads* ou [*I/O Multiplexing*](../../IOMultiplexing/) para gerenciar milhares de conexões com menor consumo de RAM.

---

## ⚙️ Evolução do Lab

Este protótipo foca em estabilidade via isolamento. Os próximos passos incluem a implementação de criptografia no tráfego (para evitar detecção por IDS/Wireshark) e a transição para um modelo de *Multithreading* para otimização de performance.