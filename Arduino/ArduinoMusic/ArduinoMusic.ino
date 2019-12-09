#include "Tonelib.h"  //LED接线查看Tonelob.h文件的port函数

int tonePin = A2;  //喇叭接一头接GND，另一头接tonePin
int musicNum = 2;
String music[] = {  //每三行为一曲, 速度，音调，节拍
  "160", //Jingle Bell
  "x321x0 x321y0y y4325555 654210 333333 351230 444443333 322125 333333 351230 444443333 554210",
  "222211 2222122 22222222 2222a2 221221 22b3a2 22b322233 222211 221221 22b3a2 22b322233 2222a2",

  "160", //we wish you a merry christmas
  "5 aaba7 666 bbcba 755 ccdcb a655 6b7 a5 aaa 77 a76 5b cba e555 6b7 a",
  "1 12222 111 12222 111 12222 1122 111 z1 111 z1 111 z1 111 1122 111 y"
};

void setup() {
  pinMode(tonePin, OUTPUT);
}

void loop() {
  for (int i = 1; i <= musicNum; i++) {
    play(i);
    delay(1000);
  }
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
