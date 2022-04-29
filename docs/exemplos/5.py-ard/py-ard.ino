void setup() {

//inicializa comunicação serial
  Serial.begin(115200);

}

void loop() {
  float valor = random(100);
  Serial.println(valor);
  delay(200);
}
