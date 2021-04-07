#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>

#endif


#define LEDS_NUM       64   //LED数量
#define DATA_PIN       2   //DATA端口
#define BRIGHTNESS     250   //亮度0-50

//初始化一个LED串
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS_NUM, DATA_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); //不设参数把灯串全关
}

void loop() {
    uint16_t i, j;
    for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
      for(i=0; i< strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(((i * 256 / 8) + j) & 255));
      }
      strip.show();
      delay(1);
    }
}

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
