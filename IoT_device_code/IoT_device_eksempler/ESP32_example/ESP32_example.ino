// definer globale variable her
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  // kommenter med '//'
 
  Serial.begin(115200);   // Serial gør at vi kan skrive til output terminalen (Serial monitor øverst i højre hjørne)

  Serial.println("Hello, World!");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Gentagelse nr: " + String(cnt));  // print noget
  cnt ++; // increment cnt så den bliver 1 større
  delay(2000);  // vent i 2 sekunder = 2000 milisekunder
}
