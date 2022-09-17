int ledPin = 11;    // nomeia o pino11 do arduino como ledPin 

void setup() {
  pinMode(ledPin, OUTPUT);            //Pino11 como saida 
  Serial.begin(9600);				   //Inicialica a comunicação serial
}


void loop() {
 
  char dado;							    // Declara dado como variavel local do tipo char

  if(Serial.available() > 0){				// Se tem alguma coisa no buffer da serial
    dado = Serial.read();					// Entao salva em dado
    Serial.print(dado);

    if (dado == 'L'){   					// Se dado igual a 'L'
      digitalWrite(ledPin, HIGH);          // Então acenda o led
      delay(500);                           // delay de 0,5 seg.
    }//end if dado == 'L'

    else if (dado == 'D'){   					// Se dado igual a 'D'
      digitalWrite (ledPin, LOW);          // Então apaga o led
     delay(500);                            // delay de 0,5 seg.
    }//end if dado == 'D'

  }//end if Serial.available

}//end loop