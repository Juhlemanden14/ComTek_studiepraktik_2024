#include <WiFi.h>
#include <WiFiUdp.h>

// Dit WiFi-netværks navn (SSID) og adgangskode (password)
const char* ssid = "Dit_Netværks_Navn";        // Skift dette til dit netværksnavn (SSID)
const char* password = "Dit_Netværks_Password"; // Skift dette til din WiFi-adgangskode

// IP-adresse og port for serveren
const char* udpAddress = "192.168.1.100"; // IP-adressen på serveren, du vil sende beskeder til
const int udpPort = 1234;                 // Porten, som serveren lytter på

WiFiUDP udp;  // Opretter en UDP-forbindelse

void setup() {
  // Starter seriemonitoren, så vi kan se statusbeskeder
  Serial.begin(115200);

  // Forbinder ESP32 til WiFi-netværket
  Serial.print("Forbinder til WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Venter på, at ESP32 opretter forbindelse til WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);  // Venter et sekund
    Serial.println("Forbinder...");
  }

  // Når WiFi er forbundet, printes WiFi-adressen
  Serial.println("Forbundet til WiFi!");
  Serial.print("ESP32 IP-adresse: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Beskeden, der skal sendes til serveren
  const char *message = "Hello, server!";
  
  // Sender beskeden til serveren via UDP
  udp.beginPacket(udpAddress, udpPort);  // Begynd at oprette en UDP-pakke til serverens IP-adresse og port
  udp.print(message);                    // Tilføjer beskeden til UDP-pakken
  udp.endPacket();                       // Sender UDP-pakken
  
  // Udskriver en statusbesked i seriemonitoren, så vi ved, at beskeden er sendt
  Serial.println("Besked sendt til serveren: " + String(message));

  // Venter i 5 sekunder (5000 millisekunder) før næste besked sendes
  delay(5000);
}
