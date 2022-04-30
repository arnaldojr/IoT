///////display

#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64);

/////Json

#include <ArduinoJson.h>
const int TAMANHO = 200;



//Declara pinos do arduino
const int led = 3;
const int sensor = A0; 

void setup() {

  //inicializa comunicação serial
  Serial.begin(115200);

  //inicializa display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x64
  display.clearDisplay();

  //texto de boot 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 30);
  display.println("Iniciando...");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

  //configura pinos de saida do arduinos
  pinMode(led, OUTPUT);
  
}

void loop() {
  
  StaticJsonDocument<TAMANHO> json; //cria o objeto Json
    
  int sensorValue = analogRead(sensor);
  int sensorValue2 = map(sensorValue,0,1023,0,255); 

  analogWrite(led, sensorValue2);

//formato de leitura no node-red
  json["topic"] = "sensor";
  json["payload"] = sensorValue;

  serializeJson(json, Serial);
  Serial.println();

// exibe no display 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("valor do sensor: ");
  display.setCursor(100, 10);
  display.println(sensorValue);
  display.setCursor(0, 25);
  display.println("Brilho: ");
  display.setCursor(100, 25);
  display.println(sensorValue2);
  display.display();

//delay
  delay(500);


}