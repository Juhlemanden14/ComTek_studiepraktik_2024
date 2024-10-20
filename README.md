# Computerteknologi Studiepraktik 2024

Dette repository indeholder en bunke eksempler på kode, der kan bruges til at løse den beskrevne case fra powerpointen "Comtek_IoT_case.pptx".

## Mappen 'IoT_device_code' indeholder eksempler på følgende:
 - ArduinoJSON_example
     - Brug af ArduinoJson librariet. Det kan bruges til at formattere data med JavaScript Object Notation syntax

 - DHT11_example
     - Brug af en DHT11 sensor. I skal selvfølgelig selv sætte hardwaren op, så jeres ESP32 er forbundet korrekt til DHT11 sensoren. Husk i sofwaren at vælge den pin i har forbundet i hardwaren.

 - ESP32_example
     - Et simpelt eksempel på at skrive arduino kode til en ESP32

 - ESP32_UDP_client_example
     - Et eksempel på at bruge en ESP32 til at sende data via et UDP socket. Sørg for at kende serverens private IP og være på samme WiFi som serveren - på den måde behøver I ikke bruge jeres offentlige IP.

## Mappen 'server_code' indeholder eksempler på følgende:
 - JSON_eksempel.py
     - Eksempel på brug af JSON formattet i python

 - UDP_server_socket.py
     - Oprettelse af en UDP server. Viser hvordan I kan gøre det, men mangler håndtering af JSON-formatterede pakker

 - UDP_client_socket.py
     - Et script I kan bruge til at tjekke at jeres UDP server virker som den skal. I skal huske at have styr på serverens private IP-adresse. Den kan I finde i en kommandopromt (cmd) via kommandoen 'ipconfig' (på windows). Søg evt. på nettet for hvordan I kan finde jeres private IP på andre styresystemer.
