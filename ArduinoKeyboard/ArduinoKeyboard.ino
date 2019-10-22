#include "Keyboard.h"

bool isBtn5Pressed = false;
bool isBtn6Pressed = false;
bool isBtn7Pressed = false;
bool isBtn8Pressed = false;
int btn5 = 5;
int btn6 = 4;
int btn7 = 3;
int btn8 = 2;


void setup() {
  pinMode(btn5, INPUT_PULLUP); 
  pinMode(btn6, INPUT_PULLUP); 
  pinMode(btn7, INPUT_PULLUP); 
  pinMode(btn8, INPUT_PULLUP); 
  Keyboard.begin();
}

void loop() {
    if (digitalRead(btn8) == LOW) {
        if (!isBtn8Pressed) {
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('c');
            isBtn8Pressed = true;
        }
    } else {
        if (isBtn8Pressed) {
            Keyboard.releaseAll();
            isBtn8Pressed = false;
        }
    }
    if (digitalRead(btn7) == LOW) {
        if (!isBtn7Pressed) {
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('v');
            isBtn7Pressed = true;
        }
    } else {
        if (isBtn7Pressed) {
            Keyboard.releaseAll();
            isBtn7Pressed = false;
        }
    }
  
    delay(10); //延时10毫秒
}
