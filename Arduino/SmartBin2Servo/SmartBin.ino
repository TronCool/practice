#include <Servo.h>

int Duo1Pin = 5;
int Duo2Pin = 6;
int SoundSendPin = 8;
int SoundRecvPin = 9;
Servo duo1;
Servo duo2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SoundSendPin, OUTPUT);
  pinMode(SoundRecvPin, INPUT);
  duo1.attach(Duo1Pin);
  duo2.attach(Duo2Pin);
  duo1.write(0);
  duo2.write(0);
}

void get_distance()
{
   digitalWrite(SoundSendPin,HIGH);
   delayMicroseconds(100);
   digitalWrite(SoundSendPin,LOW);
   int d = pulseIn(SoundRecvPin,HIGH)/58;
   Serial.print("distance = ");
   Serial.println(d);
   if(d <= 10)
   {
    duo1.write(69);
    duo2.write(73);
    delay(3000);
    duo1.write(0);
    duo2.write(0);
   }
   
}
void loop() {
  // put your main code here, to run repeatedly:
  get_distance();
  delay(100);
}
