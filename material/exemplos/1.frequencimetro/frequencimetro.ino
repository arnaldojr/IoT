const int ledPin1 = 11;


volatile unsigned long cont = 0; //declarar como volatile
unsigned long tempo = 0;
float v;
void setup(){
  //-------------- Confitura pinos de saida -----//

  pinMode(ledPin1,OUTPUT);                             //  Configura o pino 13 do arduino como saida(OUTPUT)              
 
  //---------------Configura pinos de entrada ------//

  pinMode(2,INPUT_PULLUP);                        //  Configura o pino 2 do arduino como entrada com resistor de pullup interno (assim não precisa mais colocar o resistor no pino)              
 
 //---------------Inicializa serial~ ------//  
  Serial.begin(9600); 

  //-----------  Configuração da Interrução ------------------- //                                 

  attachInterrupt(digitalPinToInterrupt(2),interrupcaoPino2,RISING);  //  Configura o pino2 como interrupção externa do tipo Rising (borda de LOW para HIGH)
  
}

void loop(){  
  //------- Programa pricipal -----//

  if ((millis() - tempo) > 999) {
    tempo = millis();
	Serial.println(cont);
	cont = 0;
  }
   
}

void interrupcaoPino2()           //funcão de interrupção do pino2, é executado quando o botao do pino2 pressionado
{                    
  digitalWrite(ledPin1,!digitalRead(ledPin1));
  cont++;
}
