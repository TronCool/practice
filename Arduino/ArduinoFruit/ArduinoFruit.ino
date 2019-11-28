#include "Keyboard.h"

int val = 0;
bool isFruitAPressed = false;
bool isFruitBPressed = false;

void setup() {
  Serial.begin(9600);  
  Keyboard.begin();
}

void loop() {
    if (analogRead(A3) > 700) {
       if (!isFruitAPressed) {
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('c');
            isFruitAPressed = true;
        }
    } else {
        if (isFruitAPressed) {
            Keyboard.releaseAll();
            isFruitAPressed = false;
        }
    }
    
    if (analogRead(A2) > 700) {
       if (!isFruitBPressed) {
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('v');
            isFruitBPressed = true;
        }
    } else {
        if (isFruitBPressed) {
            Keyboard.releaseAll();
            isFruitBPressed = false;
        }
    }
    delay(50); //延时10毫秒
}
