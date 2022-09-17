/////Json

#include <ArduinoJson.h>
const int TAMANHO = 100;

/////Config Sensor de temperatura
int TermistorPin = A1;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf, temp;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; //valores constante para calculo

/////Config Sensor de UV simulado com o sensor LDR
int UVPin = A0;

float uv;

void setup() {
  //configura pinos de saida do arduinos
  pinMode(UVPin, INPUT);
  pinMode(TermistorPin, INPUT);

  //inicializa comunicação serial
  Serial.begin(9600);

}

void loop() {
  
  StaticJsonDocument<TAMANHO> json; //cria o objeto Json
    
  temp = readTemp(TermistorPin);

  uv = readUV(UVPin);

//formato de leitura no node-red
  json["sensortemp"] = temp;
  json["sensoruv"] = uv;


  serializeJson(json, Serial);
  Serial.println();

//delay
  delay(1000);
}



//função que faz leitura da temperatura e retorna o valor em graus celcius
float readTemp(int ThermistorPin){
  
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculo R2, demonstração no arquivo pdf da aula
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));// Equação de Steinhart–Hart 
  Tc = T - 273.15; //temp em Graus celcius
  //Tf = (Tc * 9.0)/ 5.0 + 32.0; // temp em fahrenheit
  return Tc;
}


//Função que faz a leitura de lux com o sensor LDR
float readUV (int UVPin){
  float Vout,RLDR,Lux;
  int ADC;
  float Rdark = 127410.0;

  ADC = analogRead(UVPin);
  RLDR = R1 * (1023.0 / (float)ADC - 1.0); //calculo R2, demonstração no arquivo pdf da aula
  Lux = pow(Rdark/RLDR,1/0.8582);
  
  return Lux;
}
