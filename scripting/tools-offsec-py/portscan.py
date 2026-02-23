import socket

ip = raw_input("Digite o IP ou Endereco: ")
ports = range(65535)

for port in ports:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.settimeout(0.02)
    code = client.connect_ex((ip, port))

    if code == 0:
        print str(port) + " -> Porta Aberta"
    else:
        print str(port) + " -> Porta Fechada"