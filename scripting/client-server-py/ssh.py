import paramiko

host = '127.0.0.1'
user = 'teste'
passwd = 'teste'

client = paramiko.SSHClient()
client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
client.connect(host, username=user, password=passwd)

while True:
    comando = raw_input('Comando: ')    
    entrada, saida, erros = client.exec_command(comando)
    print saida.readlines()
    print erros.readlines()
