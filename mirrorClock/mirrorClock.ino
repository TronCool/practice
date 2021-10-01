#include <Adafruit_NeoPixel.h>

#define LEDS_NUM       60   //LED数量，60个点，对应钟面上的60个点
#define DATA_PIN       2    //DATA端口
#define BRIGHTNESS     100  //整体亮度0-255

#define BDOT            0   //大点点
#define SDOT            1   //小点点
#define HOUR            2   //时针
#define MIN             3   //分针
#define SEC             4   //秒针

int time_h = 1;  //初始，1:20，12小时制
int time_m = 20;
int time_s = 0;

//初始化一个LED串
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS_NUM, DATA_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); //不设参数把灯串全关
  Serial.begin(9600);
}

uint32_t getColor(int obj) {  // 调整颜色
  if(obj == BDOT) {
    return strip.Color(20, 20, 20); //亮点
  }
  if(obj == SDOT) {
    return strip.Color(5, 5, 5); //暗点
  }
  if(obj == HOUR) { 
    return strip.Color(255, 20, 20);  //时
  }
  if(obj == MIN) { 
    return strip.Color(20, 255, 20);  //分
  }
  if(obj == SEC) { 
    return strip.Color(20, 20, 255);  //秒
  }
}

void loop() {
    uint16_t i;
    for(i = 0; i < 60; i++) {
      if (i % 5 == 0) { strip.setPixelColor(i, getColor(BDOT)); } //5的倍数点画大点点
      else { strip.setPixelColor(i, getColor(SDOT)); } //其它的画小点点
      strip.setPixelColor(time_s, getColor(SEC));  //画秒针
      strip.setPixelColor(time_m, getColor(MIN));  //画分针, 如果和秒钟重复则叠在秒针上
      strip.setPixelColor(int(time_h * 5 + int(time_m / 12)), getColor(HOUR));  //画时针, int(5x小时数 + int(分钟除以12）)就是时针的位置
    }
    strip.show(); 
    Serial.print(time_h);
    Serial.print(":");
    Serial.print(time_m);
    Serial.print(":");
    Serial.print(time_s);
    Serial.println();
    delay(880); //设置每个led需要2ms，60个灯需要120ms，延时880ms一共1秒。arduino需要精准时钟需要配置外部RTC中断。
    time_s++; //走一秒
    if (time_s >= 60) { //超过60秒
      time_s -= 60; 
      time_m++; //走一分
      if(time_m >= 60) { //超过60分
        time_m -= 60;
        time_h = (time_h + 1) % 12;
      }
    }
}
