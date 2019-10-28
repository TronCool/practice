#include "Keyboard.h"

void setup() {
  pinMode(2, INPUT_PULLUP); 
  pinMode(3, INPUT); 
  Keyboard.begin();
}

void loop() {
//Keyboard.print("2:");
//Keyboard.print(digitalRead(2));
//Keyboard.print("\n");
//
//Keyboard.print("3:");
//Keyboard.print(digitalRead(3));
//Keyboard.print("\n");

delay(1000); //延时10毫秒
}
