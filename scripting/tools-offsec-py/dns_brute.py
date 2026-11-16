import dns.resolver
import sys

try:
    dominio = sys.argv[1]
    nome_arquivo = sys.argv[2]
except:
    print "Argumentos invalidos"
    print "Usage: dnsbrute.py <dominio> <wordlist>"
    sys.exit(1)

try:
    arquivo = open (nome_arquivo)
    subdominios = arquivo.read().splitlines()
except:
    print "Arquivo nao encontrado"
    sys.exit(1)

for subdominio in subdominios:
    try:
       domesub = subdominio + '.' + dominio
       resultados = dns.resolver.query(domesub, 'a')
       for resultado in resultados:
          print domesub, resultado
    except:
       pass
