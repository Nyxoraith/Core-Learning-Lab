# 🚀 Asynchronous Threaded Portscanner (Pthread + Non-Blocking)

Este projeto é um scanner de portas TCP de alta performance desenvolvido em C para ambientes Linux. Ele eleva o nível de concorrência ao combinar [**Multithreading**](../../Multiprocessing/) para divisão de carga de trabalho e [**I/O Multiplexing**](../../IOMultiplexing/) com *sockets não-bloqueantes* para gerenciar timeouts de forma ultra-eficiente.

## 🧠 O Desafio: O Gargalo do Timeout de Rede
Em um scanner convencional (bloqueante), se uma porta na rede estiver protegida por um firewall que descarta *(DROP)* os pacotes, a função `connect()` fica travada esperando pela resposta por até 20 segundos (timeout padrão do sistema operacional).

Mesmo usando threads, se várias delas pegarem portas filtradas, o scanner inteiro congela. A solução aplicada aqui foi transformar os sockets em Não-Bloqueantes *(O_NONBLOCK)*.

## 🛠️ Características Técnicas

* **Workload Distribution:** O intervalo completo de 65.535 portas é fatiado matematicamente entre as 100 threads sem sobreposição de portas nas bordas.

* **Non-Blocking Connect:** Uso de `fcntl()` para forçar o socket a não esperar a resposta da rede, capturando o estado *EINPROGRESS* via *errno*.

* **Socket State Investigation:** Uso de `getsockopt()` com a flag *SOL_SOCKET* e *SO_ERROR* para abrir a caixa-preta do socket após o alarme do select e verificar se a conexão foi bem-sucedida (0) ou rejeitada.

* **Thread Synchronization (Mutex):** Implementação de travas exclusivas com `pthread_mutex_lock()` para blindar a região crítica de saída `(printf)`, garantindo que o terminal não sofra corrupção visual com 100 threads escrevendo juntas.

## 📂 Estrutura dos Arquivos
* [**threadScanner.c:**](./threadScanner.c) Implementação principal unificando a lógica de particionamento, criação de threads, controle assíncrono de sockets e proteção de memória via *Mutex*.

### 🚀 Como Executar
Compile o binário linkando a biblioteca POSIX Threads:

```Bash
gcc threadScanner.c -o threadScanner -pthread
```
Execute medindo o tempo e consumo de recursos:

```Bash
time ./threadScanner
```

---

## 📈 Aprendizados e Desafios Técnicos

* **Estados Síncronos vs. Assíncronos:** Entendi o comportamento do Kernel quando um socket é assíncrono. O `connect()` retornar -1 não significa falha, mas sim que o pacote *SYN* já foi injetado na rede e o SO está processando a resposta em background.

* **Escopo de Memória Compartilhada:** Diferente do `fork()`, onde as variáveis eram duplicadas de forma segura, nas *threads* a memória é compartilhada. Foi necessário criar um array de structs estável no main para passar os argumentos de intervalo de portas de forma que uma thread não atropele os dados da outra.

* **Proteção de Região Crítica:** Vivenciei a necessidade real de um Mutex. Sem ele, a concorrência brutal de 100 threads tentando acessar a tela ao mesmo tempo causaria colisões e linhas quebradas no terminal.