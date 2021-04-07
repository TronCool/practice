#include <Adafruit_NeoPixel.h>

#define LEDS_NUM       14   //LED数量
#define DATA1_PIN      12   //DATA1端口
#define DATA2_PIN      13   //DATA1端口
#define HALL_PIN       A0   //霍尔元件
#define BRIGHTNESS     30   //亮度0-50

//初始化一个LED串
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(LEDS_NUM, DATA1_PIN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(LEDS_NUM, DATA2_PIN, NEO_GRB + NEO_KHZ400);

void setup() {
                                               
  pinMode(HALL_PIN,  INPUT);  

  strip1.begin();
  strip2.begin();
  strip1.setBrightness(BRIGHTNESS);
  strip2.setBrightness(BRIGHTNESS);
  strip1.show(); // Initialize all pixels to 'off'
  strip2.show();
}

void loop() {
//  rainbow(5);
    rainbowCycle(3);
}

//用指定颜色流水刷新
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip2.setPixelColor(i, c);
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel((i+j) & 255));
      strip2.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
