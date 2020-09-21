#include <Adafruit_NeoPixel.h>

#define LEDS_NUM  16  //LED数量
#define DATA_PIN  7   //DATA端口
#define RED_PIN   11  //"红"按钮控制脚
#define GREEN_PIN 12  //"绿"按钮控制脚
#define BLUE_PIN  13  //"蓝"按钮控制脚
#define PLUS_PIN  2   //"加"按钮控制脚
#define MINUS_PIN 3   //"减"按钮控制脚
#define SPEED     50  //LED切换颜色的速度（两个LED动作之间间隔毫秒）

//初始化一个LED串
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS_NUM, DATA_PIN, NEO_GRB + NEO_KHZ800);

//初始化颜色，动作，操作符
int    red       = 128;
int    green     = 128;
int    blue      = 128;
String action    = "";
String operation = "plus";
String eggStatus = ""; 

void setup() {
  Serial.begin(57600);

  pinMode(RED_PIN,   INPUT_PULLUP);
  pinMode(GREEN_PIN, INPUT_PULLUP);
  pinMode(BLUE_PIN,  INPUT_PULLUP);
  pinMode(PLUS_PIN,  INPUT_PULLUP);
  pinMode(MINUS_PIN, INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {
  checkAction(); //检查按钮
  delay(100);
}

//检查按键
void checkAction() {
  String cmd = !digitalRead(PLUS_PIN) && !digitalRead(MINUS_PIN) ? "show egg" :
               !digitalRead(PLUS_PIN)  ? "set plus" :
               !digitalRead(MINUS_PIN) ? "set minus" :
               !digitalRead(RED_PIN)   ? operation + " red" :
               !digitalRead(GREEN_PIN) ? operation + " green" :
               !digitalRead(BLUE_PIN)  ? operation + " blue" :
                                         "";
  if (action != cmd) { //消除长按连发
    action = cmd;
    if (action != "") { //按下执行动作，释放没反应
      Serial.println("do action: " + action); //串口调试
      doAction();
    }
  }
}

void doAction(){
  //protect for nothing to do
  if (action == "") return;
  if (action == "show egg")  doEgg();
  if (action == "set plus")  operation = "plus";
  if (action == "set minus") operation = "minus";
  if (action == "plus red")    red   = doPlus(red);
  if (action == "plus green")  green = doPlus(green);
  if (action == "plus blue")   blue  = doPlus(blue);
  if (action == "minus red")   red   = doMinus(red);
  if (action == "minus green") green = doMinus(green);
  if (action == "minus blue")  blue  = doMinus(blue);

  eggStatus = "stop";
  colorWipe();
}

//颜色值增加
int doPlus(int i) {
  return i >=191 ? 255 : i + 64;
}

//颜色值减少
int doMinus(int i) {
  return i <= 64 ? 0 : i - 64;
}

//刷新LED串颜色
void colorWipe() {
  for(uint16_t i=0; i<LEDS_NUM; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue)); //设置单LED颜色
    strip.show();
    delay(SPEED);
  }
  Serial.println("Wipe color: red " + String(red) +" / green " + String(green) + " / blue " + String(blue)); //串口调试
}

//彩蛋，彩虹色循环
void doEgg() {
  uint16_t i, j;
  eggStatus == "go";
  for(j=0; j<256*5; j++) { //彩轮转5圈
    for(i=0; i< LEDS_NUM; i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / LEDS_NUM) + j) & 255));
    }
    strip.show();
    checkAction(); //彩蛋过程中检查有没有按钮
    if (eggStatus == "stop") return; //有按钮就停止彩蛋
    delay(SPEED);
  }
}

//计算彩轮颜色
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
