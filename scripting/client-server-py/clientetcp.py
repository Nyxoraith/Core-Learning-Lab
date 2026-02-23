import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.settimeout(1)

try:
    client.connect(("127.0.0.1", 1050))
    #client.send("GET / HTTP/1.1\nHost: google.com\n\n\n")

    pacotes_recebidos = client.recv(1024)

    print pacotes_recebidos
except:
    print "Conexao falhou"
