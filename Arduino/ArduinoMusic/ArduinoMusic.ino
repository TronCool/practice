#include "tonedict.h"

int tonePin = A0;

//乒乓变奏曲
String aa = "331122x 1x13212 331122x 1x13231";
String bb = "2222221 2222221 2222221 2222221";

void setup() {
  pinMode(tonePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  play(aa, bb, 120);
  noTone(tonePin);
  delay(5000);
}

void play(String song, String pace, int speed) {
  for (int i = 0; i < song.length(); i++) {
    tone(tonePin, melody(song[i]), duration(pace[i], speed));
    digitalWrite(port(song[i]), HIGH);
    delay(duration(pace[i], speed) + 10);
    digitalWrite(port(song[i]), LOW);
  }
}
