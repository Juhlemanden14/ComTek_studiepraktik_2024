"""
Dette script indeholder et eksempel på at oprette et client socket (åbne en port, så computeren kan kommunikere derfra).
Scriptet kan bruges til at demonstrere hvordan serveren virker, da dette er en klient, der kan forbinde til og sende ting til serveren
"""

import socket
from time import sleep

SERVER_IP = "127.0.0.0"     # se 'UDP_server_socket.py' for forklaring af de her 3 linjer
SERVER_PORT = 13000
BUFFER_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)    # IPv4, UDP
while True:     # kør for evigt (stop processen med ctrl + c i terminalen)

    message = bytes("very important message",'utf-8')
    s.sendto(message,(SERVER_IP,SERVER_PORT))   # send besked
    print("Data sent.")

    msg_r, server_addr = s.recvfrom(BUFFER_SIZE)    # modtag et svar

    print(msg_r.decode(), server_addr)

    sleep(10)   # vent i 10 sekunder før vi gør det igen