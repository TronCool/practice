#include "Mouse.h"
//#include "Keyboard.h"

bool isPressed = false; //初始化未按下鼠标左键
void setup() {
  pinMode(2, INPUT_PULLUP); //D2为读模式
  Mouse.begin(); //开始模拟鼠标
  //Keyboard.begin();
}

void loop() {
  Mouse.move(readAxis(A0), readAxis(A1), 0); //读出XY轴，并移动

  if (digitalRead(2) == LOW){ //发现按钮按下了
    if (!isPressed) { //如果还没模拟过左键按下
      Mouse.press(); //模拟鼠标左键按下
      isPressed = true; //模拟状态为按下状态
      //Keyboard.print("pressing!\n"); //调试用
    }
  } else if(isPressed) { //按钮放开了，并且在模拟状态
    Mouse.release(); //模拟鼠标抬起   
    isPressed = false; //模拟状态为非按下状态
    //Keyboard.print("released!\n"); //调试用
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
