#include "Tonelib.h"  //LED接线查看Tonelob.h文件的port函数

int tonePin = A2;  //喇叭接一头接GND，另一头接tonePin

String music[] = {  //每三行为一曲, 速度，音调，节拍

  "160", //Jingle Bell
  "x321x0 x321y0y y4325555 654210 333333 351230 444443333 322125 333333 351230 444443333 554210",
  "222211 2222122 22222222 2222a2 221221 22b3a2 22b322233 222211 221221 22b3a2 22b322233 2222a2",

  "120",  //乒乓变奏曲
  "331122x 1x13212 331122x 1x13231",
  "2222221 2222221 2222221 2222221",

  "120",  //国歌
  "0x 11 11xyz 11 03123 55 3313 532 2 65 23 5305 3231 30 xy11 3355 222y 2x 11 33 5 1355 65 3155 3010 x1 3155 3010 x1 x1 x1 10",
  "22 a2 b3233 11 22233 11 b3b3 b31 z 11 11 2222 2331 11 b322 b322 2331 a2 a2 a2 z b322 11 b322 2222 11 b322 2222 11 11 11 11"
};

void setup() {
  pinMode(tonePin, OUTPUT);
}

void loop() {
  play(1);
}

void play(int idx) {
  int baseIndex = (idx - 1) * 3;
  int speed = music[baseIndex].toInt();
  String song = music[baseIndex + 1];
  String pace = music[baseIndex + 2];
  for (int i = 0; i < song.length(); i++) {
    digitalWrite(port(song[i]), HIGH);
    tone(tonePin, melody(song[i]), duration(pace[i], speed));
    delay(duration(pace[i], speed) + 10);
    digitalWrite(port(song[i]), LOW);
  }
  noTone(tonePin);
}
