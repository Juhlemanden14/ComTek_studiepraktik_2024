"""
Dette script er et eksempel på hvordan serveren kunne se ud.
"""

import socket
import json

HOST = ''           # Symbolsk navn for enhver tilgængelig interface
PORT = 12000         # Arbitrær, ikke-reserveret port. Bare vælg noget der ikke er 0-5000 ish
CONN_COUNTER = 0    # Tæller antallet af forbindelser
BUFFER_SIZE = 1024  # Receive Buffer størrelse (power of 2)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # IPv4, UDP
s.bind((HOST, PORT))    # Bind socket til adressen
print('UDP server running...')
print(f'Listening for incoming connections in port '+str(PORT))

while True: # Server uendeligt loop
    CONN_COUNTER = CONN_COUNTER + 1
    r,a = s.recvfrom(BUFFER_SIZE)    # modtag pakke
    # r er den modtagede data
    # a er den adresse der er bundet til et socket på den anden side af kommunikationen.
    print()
    print('* Forbindelse {} modtaget fra {}'.format(CONN_COUNTER,a))
    print('\tRå tekst: {}'.format(r))
    print()

    # antager at r er i serialiseret json-format
    læst_json = json.loads(r)
    # print(f"læst_json print: {læst_json}")

    # udtræk af data
    for key in læst_json:
        print(f"læst_json['{key}'] = {læst_json[key]}")




    # ans = f'The server recieved your message. It was {len(r)} bytes long'
    # s.sendto(bytes(ans, encoding='utf-8'), a)
    # print("answer sent")
    