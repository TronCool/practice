#include "Mouse.h"
//#include "Keyboard.h"

bool isPressed = false; //初始化未按下鼠标健
void setup() {
  pinMode(2, INPUT_PULLUP); //D2为读模式
  Mouse.begin(); //开始模拟鼠标
//  Keyboard.begin();
}

void loop() {
  Mouse.move(readAxis(A0), readAxis(A1), 0); //读出XY轴，并移动

  if (digitalRead(2) == LOW){
    if (!isPressed) {
      Mouse.press(); //模拟鼠标左键按下
      isPressed = true; //按下状态
//      Keyboard.print("pressing!\n");
    }
  } else if(isPressed) {
    Mouse.release(); //如果已经按下过，放开   
    isPressed = false; //放开状态
//    Keyboard.print("released!\n");
  }

  delay(10); //延时10毫秒
}

int readAxis(int thisAxis) {
  int reading = analogRead(thisAxis); //读指定口数值，就是手掰摇杆的程度
  int distance = reading - 512; //轴的取值范围是 -512 到 512，没有动的时候是512
  if (abs(distance) < 100) { //如果只动了微微一点
    distance = 0; //就当作没有动（防止漂移）
  }
  return int(distance/64); //返回掰摇杆的数值,动得太快放慢64倍
}
