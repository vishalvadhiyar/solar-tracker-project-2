#include<Servo.h>
const int ledPin = A3;
Servo servo1;
const int ldrPin1 = A0;
const int ldrPin2 = A5;
void setup() {

Serial.begin(9600); 
  servo1.attach(7); 
pinMode(ledPin, OUTPUT);
pinMode(ldrPin1, INPUT);
pinMode(ldrPin2, INPUT);
}

void loop() {

int ldrStatus1 = analogRead(ldrPin1);
int ldrStatus2 = analogRead(ldrPin2);
servo1.write(180);
  
if (ldrStatus1 <= 350 && ldrStatus2 >= 350 )
{
servo1.write(135);
digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus1);
Serial.println(ldrStatus2);
}
  else if (ldrStatus1 >= 350 && ldrStatus2 >= 350 )
{
servo1.write(180);
digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus1);
Serial.println(ldrStatus2);

}
    else if (ldrStatus1 >= 350 && ldrStatus2 <= 350 )
{
servo1.write(45);
digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus1);
      Serial.println(ldrStatus2);

}
  else
  {
servo1.write(180);
digitalWrite(ledPin, LOW);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus1);
Serial.println(ldrStatus2);

}

}
