bool isBtnPressed = false; //按钮状态
int mode = 1; //模式
int pinInt = 1; //中断引脚

int pins1[] = {2, 3, 4}; //第一组红绿灯引脚
int pins2[] = {5, 6, 7}; //第二组红绿灯引脚
int pins3[] = {8, 9, 10}; //第三组红绿灯引脚
int pins4[] = {15, 14, 16}; //第四组红绿灯引脚


void setup() {
  //初始化设置
  //初始化四组红绿灯引脚
  for (int i = 0; i < 3; i++) {
    pinMode(pins1[i], OUTPUT);
    pinMode(pins2[i], OUTPUT);
    pinMode(pins3[i], OUTPUT);
    pinMode(pins4[i], OUTPUT);
  }

  //初始化中断引脚
  pinMode(pinInt, INPUT_PULLUP);
  //注册中断
  attachInterrupt(digitalPinToInterrupt(pinInt), selfAdd, HIGH);
}

void loop() {
  //主循环

  //关所有灯
  allOff();

  //判断当前在哪个模式
  switch (mode) {
    case 1: //模式一：所有黄灯闪烁
      flashAllYellow();
      break;
    case 2: //模式二：所有灯闪烁
      flashAll();
      break;
    case 3: //模式三：正常红黄绿循环
      normalMode();
      break;
    default:
      allOff();
      break;
  }
}

//4个灯亮duration时间段
void light4(int pin1, int pin2, int pin3, int pin4, int duration) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  delay(duration);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

//四灯同时闪烁若干(times)次
void blinkPin4(int pin1, int pin2, int pin3, int pin4, int times) {
  int i;
  for (i = 0; i < times; i++) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, HIGH);
    delay(300);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    delay(200);
  }
}

//黄灯持续闪烁
void flashAllYellow() {
  blinkPin4(pins1[1], pins2[1], pins3[1], pins4[1], 3);
}

//正常模式
void normalMode() {
  light4(pins1[0], pins2[2], pins3[2], pins4[0], 5000);
  blinkPin4(pins1[1], pins2[1], pins3[1], pins4[1], 3);
  light4(pins1[2], pins2[0], pins3[0], pins4[2], 5000);
  blinkPin4(pins1[1], pins2[1], pins3[1], pins4[1], 3);
}

//中断时执行的函数，切换模式
void selfAdd() {

  /*  由于cpu检测按键的探测速度太快(每秒1600万个时钟周期）
   *  我们按一次按钮，cpu会检测到非常多次的按钮按下的输入
   *  所以需要以下逻辑和 isBtnPressed 标志位来处理按钮操作
   */
  
  //如果中断按钮输入为低电平
  if (digitalRead(pinInt) == LOW) {
    //如果是第一次检测到按钮被按下
    if (!isBtnPressed) {
      //这里是需要执行的按钮按下操作（循环切换模式）
      mode++;
      if (mode > 3) {
        mode = 1;
      }
      //将标志位置为true，表示已经处理过这次按键操作
      isBtnPressed = true;
    } else {
      //如已经处理过这次按键按下的操作，那么重置标志位
      if (isBtnPressed) {
        isBtnPressed = false;
      }
    }
  }
  delay(10);
}

void allOff() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins1[i], LOW);
    digitalWrite(pins2[i], LOW);
    digitalWrite(pins3[i], LOW);
    digitalWrite(pins4[i], LOW);
  }
}

void flashAll() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins1[i], HIGH);
    digitalWrite(pins2[i], HIGH);
    digitalWrite(pins3[i], HIGH);
    digitalWrite(pins4[i], HIGH);
  }

  delay(300);
  allOff();
  delay(200);
}


void light2(int pin, int pin2, int duration) {
  digitalWrite(pin, HIGH);
  digitalWrite(pin2, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  digitalWrite(pin2, LOW);
}

void light(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
}

void blinkPin2(int pin, int pin2, int times) {
  int i;
  for (i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    digitalWrite(pin2, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
    digitalWrite(pin2, LOW);
    delay(200);
  }
}

void blinkPin(int pin, int times) {
  int i;
  for (i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
    delay(200);
  }
}
