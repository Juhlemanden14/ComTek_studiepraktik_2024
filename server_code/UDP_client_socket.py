"""
Dette script indeholder et eksempel på at oprette et client socket (åbne en port, så computeren kan kommunikere derfra).
Scriptet kan bruges til at demonstrere hvordan serveren virker, da dette er en klient, der kan forbinde til og sende ting til serveren
"""

import socket
SERVER_IP = "127.0.0.1"
SERVER_PORT = 9999
BUFFER_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
while True:

    s.sendto(bytes(str(input('skriv noget her: ')),'utf-8'),(SERVER_IP,SERVER_PORT))
    print("Data sent.")

    msg_r, server_addr = s.recvfrom(BUFFER_SIZE)

    print(msg_r.decode(), server_addr)