#include <WiFi.h>
#include <WiFiUdp.h>
#include <DHT11.h>
#include <ArduinoJson.h>

// Dit WiFi-netværks navn (SSID) og adgangskode (password)
const char* ssid = "xxxxxxxxxxx";        // Skift dette til dit netværksnavn (SSID)
const char* password = "xxxxxxxxxx"; // Skift dette til din WiFi-adgangskode

// IP-adresse og port for serveren
const char* udpAddress = "172.26.19.58"; // IP-adressen på serveren, du vil sende beskeder til
const int udpPort = 12000;                 // Porten, som serveren lytter på


DHT11 dht11(7); // opret DHT11 object med data-pin 7 (eller anden brugbar pin)
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

  // Når WiFi er forbundet, printes IP-adressen
  Serial.println("Forbundet til WiFi!");
  Serial.print("ESP32 IP-adresse: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  // ---------- lav målinger ----------
  int temperature = 0;
  int humidity = 0;
  int result = dht11.readTemperatureHumidity(temperature, humidity);  // Attempt to read the temperature and humidity values from the DHT11 sensor.
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\tHumidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  // !---------- lav målinger ----------!


  // ---------- konstruer pakke ----------
  // Initialiser et statisk JSON-dokument
  StaticJsonDocument<40> doc;    // Du skal vælge den rette kapacitet baseret på det data du skal håndtere.
  doc["temp_data"] = temperature;
  doc["hum_data"] = humidity;

  String outputJson;      // Serialiser JSON-objektet til en ny JSON-streng:
  serializeJson(doc, outputJson);
  // !---------- konstruer pakke ----------!


  // ---------- Send pakke med UDP ----------
  // Sender beskeden til serveren via UDP
  int begin_status = udp.beginPacket(udpAddress, udpPort);  // Begynd at oprette en UDP-pakke til serverens IP-adresse og port
  // Serial.println("begin_status: " + String(begin_status));
  udp.print(outputJson);                      // Tilføjer beskeden til UDP-pakken
  int end_status = udp.endPacket();           // Sender UDP-pakken
  // Serial.println("end_status: " + String(end_status));

  // Udskriver en statusbesked i seriemonitoren, så vi ved, at beskeden er sendt
  Serial.println("Besked sendt til serveren: " + String(outputJson));
  // !---------- Send pakke med UDP ----------!


  // Venter i 5 sekunder (5000 millisekunder) før næste besked sendes
  delay(5000);
}
