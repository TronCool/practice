#include "Tonelib.h"  //LED接线查看Tonelob.h文件的port函数

int tonePin = 9;  //喇叭接一头接GND，另一头接tonePin
int ledPin[] = {2, 3, 4, 5, 6, 7, 8}; //亮灯Pin

int musicNum = 2;  //一共有2首曲子，arduino没有数组长度方法，判断曲子数量比较麻烦，所以hardcode写在这里
String music[] = {  //每三行为一曲, 速度，音调，节拍
  "160",  //Jingle Bell
  "x321x0 x321y0y y4325555 654210 333333 351230 444443333 322125 333333 351230 444443333 554210",
  "222211 2222122 22222222 2222a2 221221 22b3a2 22b322233 222211 221221 22b3a2 22b322233 2222a2",

  "160",  //we wish you a merry christmas
  "5 aaba7 666 bbcba 755 ccdcb a655 6b7 a5 aaa 77 a76 5b cba e555 6b7 a",
  "1 12222 111 12222 111 12222 1122 111 z1 111 z1 111 z1 111 1122 111 y"
};

void setup() {
  pinMode(tonePin, OUTPUT);
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  pinMode(ledPin[4], OUTPUT);
  pinMode(ledPin[5], OUTPUT);
  pinMode(ledPin[6], OUTPUT);
}

void loop() {
  for (int i = 1; i <= musicNum; i++) {  //遍历所有的歌
    play(i);  //播放第i首歌
    delay(1000);  //两首歌之间停1秒
  }
}

void play(int idx) {
  int baseIndex = (idx - 1) * 3;  //每首歌由3个字串定义
  int speed = music[baseIndex].toInt();  //第一个字串表示速度，每分钟多少个节拍
  String song = music[baseIndex + 1];  //第二个字串定义了音调
  String pace = music[baseIndex + 2];  //第三个字串定义了每个单调的节拍长度
  for (int i = 0; i < song.length(); i++) {  //遍历整首歌
    if(song[i]==' '){
      for (int j = 0; j < 7; j++){
        digitalWrite(j, random(2));  //随机亮灭LED
      }
    } else {
      tone(tonePin, melody(song[i]), duration(pace[i], speed));  //发音
      delay(duration(pace[i], speed) + 10);  //延时等待发音结束，加10ms为了断开连续两个相同的音符
    }
  }
}
