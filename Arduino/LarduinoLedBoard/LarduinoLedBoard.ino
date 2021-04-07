#include <Adafruit_NeoPixel.h>

#define LEDS_NUM       16  //LED数量
#define DATA_PIN       7   //DATA端口
#define COLOR_FORWARD  11  //"颜色+"按钮控制脚
#define COLOR_BACKWARD 12  //"颜色-"按钮控制脚
#define SWITCH_ON_OFF  13  //"开关"按钮控制脚
#define BRIGHT_PLUS    2   //"亮度+"按钮控制脚
#define BRIGHT_MINUS   3   //"亮度-"按钮控制脚
#define SPEED          40  //LED切换颜色的速度（两个LED动作之间间隔毫秒）

//初始化一个LED串
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS_NUM, DATA_PIN, NEO_GRB + NEO_KHZ800);

//初始化颜色,动作,操作符
String action     = "";
String toggle     = "on"; //开关开着
int    bright     = 5;
int    color      = 0;
int    colorList[15][3] = {
          {256,256,256}, //白
          {256,0,0},     //红
          {256,64,0},    //棕
          {256,128,0},   //橙
          {256,256,0},   //黄
          {128,256,0},   //黄绿
          {64,256,0},    //青绿
          {0,256,0},     //绿
          {0,256,256},   //湖蓝
          {0,128,256},   //海蓝
          {0,64,256},    //藏青
          {0,0,256},     //藏青
          {64,0,256},    //深紫
          {128,0,256},   //紫
          {256,0,256}    //洋红
};

void setup() {
  Serial.begin(57600);

  pinMode(COLOR_FORWARD,  INPUT_PULLUP);
  pinMode(COLOR_BACKWARD, INPUT_PULLUP);
  pinMode(SWITCH_ON_OFF,  INPUT_PULLUP);
  pinMode(BRIGHT_PLUS,    INPUT_PULLUP);
  pinMode(BRIGHT_MINUS,   INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {
  checkAction(); //检查按钮
  delay(SPEED);
}

//检查按键
void checkAction() {
  String cmd = !digitalRead(BRIGHT_PLUS) && !digitalRead(BRIGHT_MINUS) ? "show egg" : //亮度 加 减 同时按下，激活彩蛋
               !digitalRead(BRIGHT_PLUS)    ? "bright +" :      //亮度 加 按下
               !digitalRead(BRIGHT_MINUS)   ? "bright -" :      //亮度 减 按下
               !digitalRead(COLOR_FORWARD)  ? "color +" :       //颜色 加 按下
               !digitalRead(COLOR_BACKWARD) ? "color -" :       //亮度 减 按下
               !digitalRead(SWITCH_ON_OFF)  ? "toggle on/off" : //开关 加 按下
                                              "";               //释放按钮
  if (action != cmd) { //消除长按连发
    action = cmd;
    if (action != "") { //按下执行动作,释放没反应
      Serial.println("do action: " + action); //串口调试
      doAction();
    }
  }
}

void doAction(){
  //protect for nothing to do
  if (action == "") return;
  if (action == "show egg")       doEgg();
  if (action == "bright +")       bright = bright >= 10 ? 10 : bright + 1; //10级亮度
  if (action == "bright -")       bright = bright <= 1  ? 1  : bright - 1; //10级亮度
  if (action == "color +")        color  = color >= 14  ? 0   : color + 1; //0-14共15种颜色
  if (action == "color -")        color  = color <= 0   ? 14  : color - 1; //0-14共15种颜色
  if (action == "toggle on/off")  toggle = toggle == "on" ? "off" : "on";

  setupColor();
}

//计算亮度
int calcBright(int i) {
  if (toggle=="off") return 0;
  return int(i / 10 * bright);
}

//刷新LED串颜色
void setupColor() {
  int red   = calcBright(colorList[color][0]);
  int green = calcBright(colorList[color][1]);
  int blue  = calcBright(colorList[color][2]);
  for(uint16_t i=0; i<LEDS_NUM; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue)); //设置单LED颜色
    strip.show();
    delay(SPEED);
  }
  Serial.println("Wipe color: red " + String(red) +" / green " + String(green) + " / blue " + String(blue)); //串口调试
}

//彩蛋, 彩虹色循环，大约1分钟
void doEgg() {
  uint16_t i, j;
  for(j = 0; j < 256*5; j++) { //彩轮转5圈
    for(i = 0; i < LEDS_NUM; i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / LEDS_NUM) + j) & 255));
    }
    strip.show();
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
