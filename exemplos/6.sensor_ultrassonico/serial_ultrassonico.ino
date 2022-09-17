#include <Ultrasonic.h>
#include <Servo.h>

//Servo servo1;
//Servo servo2;

HC_SR04 sensor1(4,5); // (trigger, echo)
HC_SR04 sensor2(8,9); // (trigger, echo)

int angle;
int pwm;

int servo1 = 6;
int servo2 = 10;
int dist1, dist2;

void setup() {
  Serial.begin(9600);
  //servo1.attach(6);
  //servo2.attach(10);
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
}

void loop() {
  dist1 = sensor1.distance();
  dist2 = sensor2.distance();
  Serial.println(sensor1.distance() + String(" cm ") + sensor2.distance() + String(" cm"));
  delay(100);
  
  if (dist1 >= 100){
    servoPulse(servo1, 90);
    //servo1.write(200);
  } else {
    //servo1.write(180);
    servoPulse(servo1, 180);
  }

  if (dist2 >= 100){
    servoPulse(servo2, 0);

  } else {
    servoPulse(servo2, 90);
  }

}


void servoPulse (int servo, int angle)
{
  pwm = (angle*11) + 500;      // Convert angle to microseconds
  digitalWrite(servo, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(servo, LOW);
  delay(50);                   // Refresh cycle of servo
}
