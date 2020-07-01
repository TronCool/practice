#include <Servo.h>

int DuoJiPin = 8;//10;
int SoundSendPin = 6;
int SoundRecvPin = 7;
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SoundSendPin,OUTPUT);
  pinMode(SoundRecvPin,INPUT);
  myServo.attach(DuoJiPin);
  myServo.write(0);
}

void get_distance()
{
   digitalWrite(SoundSendPin,HIGH);
   delayMicroseconds(100);
   digitalWrite(SoundSendPin,LOW);
   int d = pulseIn(SoundRecvPin,HIGH)/58;
   Serial.print("distance = ");
   Serial.println(d);
   if(d <= 30)
   {
    myServo.write(100);
    delay(3000);
    myServo.write(0);
   }
   
}
void loop() {
  // put your main code here, to run repeatedly:
  get_distance();
  delay(100);
}
