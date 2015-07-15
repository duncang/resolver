#include <TimerOne.h>




int ledPin = 13;


int leftRightPin = 10;
int upDownPin = 11;

void setup()
{
  Serial.begin(9600);
  

  // setup 400 Hz timer 
  pinMode(ledPin,OUTPUT);
  Timer1.initialize(1250);
  Timer1.pwm(9,512);
  Timer1.attachInterrupt(callback);
 
 
  // setup deviation pwm
  pinMode(leftRightPin,OUTPUT);
  pinMode(upDownPin,OUTPUT);
  
}


void callback()
{
  static int counter;
  
  ++counter;
   digitalWrite(ledPin,digitalRead(ledPin)^1); 
   
   analogWrite(leftRightPin,counter);
   analogWrite(upDownPin,counter);
}

void loop()
{
  

}
