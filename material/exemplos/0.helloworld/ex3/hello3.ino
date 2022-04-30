const int led = 13; //define o apelido led para o valor 13
const int botao = 5; //define o apelido botao para o valor 5

const int ledPwm = 11; //define o apelido ledPwm para o valor 11
const int potAD = A0; //define o apelido potenciometro para o valor A0

void setup(){
  //  Entradas e saidas digitais
  pinMode(led,OUTPUT); //declara o pino13 (led) como saida
  pinMode(botao, INPUT_PULLUP); //declara o pino5 (botao) como entrada

  // Entradas e saidas analógicas
  pinMode(ledPwm,OUTPUT); //declara o pino11 (ledPwm) como saida
  pinMode(potAD, INPUT); //declara o pinoA0 (potenciometro) como entrada

}

void loop(){
  // Faz a leitura do botao
  if(digitalRead(botao) == LOW){
    digitalWrite(led, HIGH); //acende o led
    delay(100); //delay em milisegundos
    digitalWrite(led, LOW); //apaga o led
    delay(100); //delay em milisegundos
  }
  // Faz a leitura analógica do potenciometro
  int pot = analogRead(potAD);
  if(pot >= 500){
    digitalWrite(ledPwm, HIGH); //acende o led
    delay(100); //delay em milisegundos
    digitalWrite(ledPwm, LOW); //apaga o led
    delay(100); //delay em milisegundos
  }

}
