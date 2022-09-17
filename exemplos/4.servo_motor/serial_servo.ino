#include <Servo.h>	//importa a biblioteca do servo motor

Servo myservo1;  		// cria o objeto meuservo
Servo myservo2;  		// cria o objeto meuservo

int pos=0;    			// variavel que vai receber o valor lido do potenciometro

void setup() {
  myservo1.attach(10);  // configura o pino 9 do arduino para o servo motor
  myservo2.attach(11);  // configura o pino 9 do arduino para o servo motor
 
}

void loop() {

 for (pos = 0; pos <=180; pos += 1 ){

    myservo1.write(pos);                 // aciona o servo motor na posição valor
    myservo2.write(pos);                 // aciona o servo motor na posição valor
    delay(15);                           	// delay para esperar o servo chegar na posição. 
  }

  for (pos = 180; pos >=0; pos -= 1){

    myservo1.write(pos);                 // aciona o servo motor na posição valor
    myservo2.write(pos);                 // aciona o servo motor na posição valor
    delay(15);                           	// delay para esperar o servo chegar na posição. 
  }
}