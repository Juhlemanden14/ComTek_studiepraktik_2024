"""
Dette script indeholder et eksempel på at oprette et socket (åbne en port, så computeren kan kommunikere derfra).
Måden det virker på:
 - opret server socket      (sæt en postkasse op)
 - lyt på socket            (lad postmanden komme med post)
 - accepter forbindelser    (--||--)
 - modtag beskeder/pakker   (læs posten, som postmanden kommer med)
"""

import socket

# Giver jeres locale IP-addresse
def get_local_ip():
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.connect(('8.8.8.8', 80))
        local_ip = s.getsockname()[0]
    return local_ip

HOST = ''           # Symbolsk navn for enhver tilgængelig interface
PORT = 12000         # Arbitrær, ikke-reserveret port. Bare vælg noget der ikke er 0-5000 ish
CONN_COUNTER = 0    # Tæller antallet af forbindelser
BUFFER_SIZE = 1024  # Receive Buffer størrelse (power of 2)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # IPv4, UDP
s.bind((HOST, PORT))    # Bind sockect til adressen
print('UDP server running...')
print(f'Listening for incoming connections at host ' + get_local_ip() + " and port " + str(PORT))

while True: # Server uendeligt loop
    CONN_COUNTER = CONN_COUNTER + 1
    r,a = s.recvfrom(BUFFER_SIZE)    # modtag pakke
    # r er den modtagede data
    # a er den adresse der er bundet til et socket på den anden side af kommunikationen.
    print('* Connection {} received from {}'.format(CONN_COUNTER,a))
    print('\tIncoming text: {}'.format(r))

    ans = f'The server recieved your message. It was {len(r)} bytes long'

    s.sendto(bytes(ans, encoding='utf-8'), a)
    print("answer sent")
    