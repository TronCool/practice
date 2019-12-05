#include "tonedict.h"


int tonePin = 11; // 蜂鸣器pin, 支持PWM
int senserPin = 24; // 传感器pin, 支持analog输入

// library 是个结构体
// library = [
//   { // music 1
//     speed: 120,
//     tones: [[声调,节拍],[声调,节拍],[声调,节拍],[声调,节拍],[声调,节拍],[声调,节拍]]
//   },
//   { // music 2
//     speed: 120,
//     tones: [[声调,节拍],[声调,节拍],[声调,节拍],[声调,节拍],[声调,节拍],[声调,节拍]]
//   }
// ];
float library[][][] = {
  {
    {声调, 节拍}, {声调, 节拍}, {声调, 节拍}, {声调, 节拍}, {声调, 节拍}, {声调, 节拍}, {声调, 节拍}
  }
}

void setup()
{
  pinMode(tonePin, OUTPUT);
  pinMode(senserPin, INTPUT);
}

void loop()
{
  if (analogRead(senserPin)>700) { // 等待传感器事件
    play(libiary[随机数]);
  }
}

void play(music)
{
  float ratio = 60 * 1000 / speed; // 每一拍的基准时间
  for i = 遍历(music) {
    tone(tonePin, music[i][0], music[i][1]*ratio);
  }
}
