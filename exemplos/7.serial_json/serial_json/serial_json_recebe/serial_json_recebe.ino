#include <ArduinoJson.h>
const int LED = 3;
const int TAMANHO = 200;
void setup() {
  Serial.begin(9600);
  //O valor padrão de 1000ms é muito tempo
  Serial.setTimeout(10);
  pinMode(LED,OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {
    //Lê o JSON disponível na porta serial:
    StaticJsonDocument<TAMANHO> json;
    deserializeJson(json, Serial);
    if(json.containsKey("led")) {
      int valor = json["led"];
      analogWrite(LED, valor);
    }
  } 
  delay(300);
}
