from scapy.all import *

data = 'Oi Google'

pacote = IP(dst=['google.com', 'facebook.com'])/TCP(dport=[80,8080,22], flags='S')

recebido, nao_recebido = sr(pacote, timeout=1)

print recebido.show()
print nao_recebido.show()