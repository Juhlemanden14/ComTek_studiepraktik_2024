#include <ArduinoJson.h>

void setup() {
  // Initialiser seriel kommunikation
  Serial.begin(115200);

  // JSON-strengen du vil parse
  const char* jsonString = "{\n   \"temp_data\":20.5,\n   \"hum_data\":52.5\n}";

  // Initialiser et statisk JSON-dokument
  // Du skal vælge den rette kapacitet baseret på det data du skal håndtere.
  StaticJsonDocument<200> doc;

  // Parse JSON-strengen
  DeserializationError error = deserializeJson(doc, jsonString);

  // Udpak data fra JSON-objektet
  float temp = doc["temp_data"];  // Hent temp_data
  float hum = doc["hum_data"];    // Hent hum_data

  // Print værdierne for at sikre, at de er læst korrekt
  Serial.print("Temperatur: ");
  Serial.println(temp);
  Serial.print("Fugtighed: ");
  Serial.println(hum);

  // Hvis du vil serialisere JSON-objektet igen til en ny JSON-streng:
  String outputJson;
  serializeJson(doc, outputJson); // Serialiser JSON-dokumentet til en streng

  // Print den serialiserede JSON-streng
  Serial.println("Serialiseret JSON:");
  Serial.println(outputJson);
}

void loop() {
  // Ikke noget i loop
}