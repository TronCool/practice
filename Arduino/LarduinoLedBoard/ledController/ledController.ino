#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LEDS_NUM  16  //LED数量
#define DATA_PIN  7   //DATA端口
#define PLUS_PIN  2   //"加"按钮控制脚
#define MINUS_PIN 3   //"减"按钮控制脚
#define RED_PIN   11  //"红"按钮控制脚
#define GREEN_PIN 12  //"绿"按钮控制脚
#define BLUE_PIN  13  //"蓝"按钮控制脚

//初始化一个LED串
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS_NUM, DATA_PIN, NEO_GRB + NEO_KHZ800);

boolean plus  = false;
boolean minus = false;
boolean red   = false;
boolean green = false;
boolean blue  = false;

void setup() {                                             
  pinMode(PLUS_PIN,  INPUT);
  pinMode(MINUS_PIN, INPUT);
  pinMode(RED_PIN,   INPUT);
  pinMode(GREEN_PIN, INPUT);
  pinMode(BLUE_PIN,  INPUT);

  
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'

//  Serial.print("PLUS_PIN:");
//  Serial.print(digitalRead(PLUS_PIN));
//  Serial.print("MINUS_PIN：");
//  Serial.print(digitalRead(MINUS_PIN));
//  Serial.print("RED_PIN：");
//  Serial.print(digitalRead(RED_PIN));
//  Serial.print("GREEN_PIN：");
//  Serial.print(digitalRead(GREEN_PIN));
//  Serial.print("BLUE_PIN：");
//  Serial.print(digitalRead(BLUE_PIN));
}

void loop() {
//if (digitalRead(PLUS_PIN) == LOW) {
//    Serial.println("PLUS_PIN");
//}
//if (digitalRead(MINUS_PIN) == LOW) {
//    Serial.println("MINUS_PIN");
//}
//if (digitalRead(RED_PIN) == HIGH) {
//    Serial.println("RED_PIN");
//}
//if (digitalRead(GREEN_PIN) == HIGH) {
//    Serial.println("GREEN_PIN");
//}
//if (digitalRead(BLUE_PIN) == HIGH) {
//    Serial.println("BLUE_PIN");
//}
//

  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(255, 255, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 255, 255), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  colorWipe(strip.Color(255, 0, 255), 50); // Blue
  rainbow(10);
  rainbowCycle(10);
}



void check_button()
{
  int button_input    =   digitalRead(PLUS_PIN);
}

//用指定颜色流水刷新
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
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
