# 🚀 Parallel TCP Portscanner (Fork-based)

Este projeto é um scanner de portas TCP de alta performance desenvolvido em C para ambientes Linux. Ele utiliza a técnica de *Multiprocessing* para dividir a carga de trabalho entre múltiplos processos, reduzindo drasticamente o tempo total de varredura.

## 🧠 O Desafio: Sequencial vs. Paralelo

Escanear 65.535 portas de forma sequencial é ineficiente devido ao tempo de espera (timeout) de cada tentativa de conexão. Ao utilizar fork(), este programa divide o intervalo total de portas em blocos menores, processando-os simultaneamente.

## 📊 Benchmark de Performance
Nos testes realizados, o ganho de velocidade foi superior a 300%:

* **Sequencial:** ~0.82s
* **Paralelo (100 processos):** ~0.27s

## 🛠️ Características Técnicas

* **Workload Distribution:** O intervalo de 65k portas é fatiado dinamicamente entre o número de processos filhos definidos.
* **TCP Connect Scan:** Utiliza o three-way handshake completo para identificar portas abertas.
* **Process Synchronization:** O processo pai utiliza um loop de `wait(NULL)` para garantir que todos os scans sejam finalizados antes de encerrar o programa, evitando processos órfãos.
* **Socket Recycling:** Criação e fechamento de sockets dentro do loop do filho para evitar estados de erro e exaustão de descritores compartilhados.

## 📂 Estrutura dos Arquivos

* **`portscan_fork.c`:** Implementação principal com a lógica de fatiamento e criação de processos.

## 🚀 Como Executar

1. Compile o binário:

```bash
gcc portscan_fork.c -o portscan
```

2. Execute medindo o tempo:

```bash
time ./portscan
```

## 📈 Aprendizados e Desafios Técnicos

* **Race Conditions de Saída:** Aprendi a importância de separar o loop de criação `(fork)` do loop de espera `(wait)`. Colocar o `wait` dentro do loop de criação destruiria o paralelismo, tornando o programa sequencial novamente.
* **Escalonamento do Kernel:** Observar o uso de CPU subir para >300% no comando time foi uma aula prática sobre como o Linux distribui processos entre os diversos núcleos do processador.
* **Isolamento de Memória:** Como cada filho tem sua própria cópia da memória, a manipulação da variável `targetAddr` é segura e não exige mecanismos de trava *(locks)*, simplificando a lógica inicial.

## ⚙️ Evolução do Lab
Este projeto demonstra o poder do *multiprocessamento* bruto. A próxima evolução deste scanner envolverá o uso de *Threads (pthreads)* para reduzir o consumo de memória do sistema e a implementação de *Stealth Scans (SYN Scan)* para evitar detecção por firewalls.