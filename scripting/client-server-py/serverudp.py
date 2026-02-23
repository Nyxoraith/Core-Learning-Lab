import socket

serverudp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

ip = "0.0.0.0"
port = 1050

try:
    serverudp.bind((ip, port))
    serverudp.listen(5)
    print "Listening in: " + ip + ":" + str(port)

    (client_socket, address) = serverudp.accept()

    print "Received from: " + address[0]

    while True:
        data = client_socket.recv(1024)
        #file.write(data)
        if data == "codigo123\n":
            client_socket.send("Informacao secreta\n")
            print "Se logou"
        else:
            client_socket.send("Codigo incorreto\n")
            print "Nao logou"

except Exception as erro:
    print "Erro: " + str(erro)
