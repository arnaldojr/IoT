#include <Adafruit_SSD1306.h>

#define SCREEN_ADDRESS 0x3C  //talvez seja 0x3D


Adafruit_SSD1306 oled(128, 64);

void setup(){
  pinMode(11,OUTPUT);
  Serial.begin(9600);


  //config do display OLED
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  oled.clearDisplay();

}



void loop(){
  //digitalWrite(11,HIGH);
  int  potenciometro = analogRead(A0);
  int  potpwm = map(potenciometro, 0,1023,0,255);
  analogWrite(11, potpwm);

  Serial.print("valor pwm: ");
  Serial.println(potpwm);

// escrevendo no display oled

  oled.clearDisplay();
  oled.setTextSize(1); // Draw 2X-scale text
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(30, 0);

  oled.print("valor pot: ");
  oled.println(potpwm);
  oled.display();      // Show initial text


  delay(100);

}




















