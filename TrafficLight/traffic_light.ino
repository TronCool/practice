bool isBtnPressed = false;
int mode = 2;
int pinInt = 1;
volatile int state = LOW;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(pinInt, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pinInt), selfAdd, HIGH);
}

void loop() {
  allOff();
  if (mode == 2) {
    flashAllYellow();
  } 
  if (mode == 3) {
    flashAll();
  }
  if (mode ==4) {
    normalMode();
  }
}

void selfAdd() {
  if (digitalRead(pinInt) == LOW) {
    if (!isBtnPressed) {
      mode++;
      if (mode > 4) {
        mode = 2;
      }
      isBtnPressed = true;
    } else {
      if (isBtnPressed) {
        isBtnPressed = false;
      }
    }
  }

}

void allOff() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  digitalWrite(15, LOW);
  digitalWrite(14, LOW);
  digitalWrite(16, LOW);
}

void flashAll() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);

  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);

  digitalWrite(15, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(16, HIGH);

  delay(300);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  digitalWrite(15, LOW);
  digitalWrite(14, LOW);
  digitalWrite(16, LOW);

  delay(200);
}

void flashAllYellow() {
  blinkPin4(3, 6, 9, 14, 3);
  //blinkPin4(2, 5, 8, 15, 3);
}

void normalMode() {
  light4(2, 7, 10, 15, 5000);
  blinkPin4(3, 6, 9, 14, 3);
  light4(4, 5, 8, 16, 5000);
  blinkPin4(3, 6, 9, 14, 3);
}


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
