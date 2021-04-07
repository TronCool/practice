#include <Servo.h>

Servo servo_x;
Servo servo_y;
int stick_x_pin = A1;
int stick_y_pin = A0;
int servo_x_pin = 8;
int servo_y_pin = 9;
int servo_x_ang = 90;
int servo_y_ang = 90;
int stick_x_origin = 520;
int stick_y_origin = 501;
int stick_x_value;
int stick_y_value;

void setup() {
  Serial.begin(9600);
  servo_x.attach(servo_x_pin);
  servo_y.attach(servo_y_pin);
  servo_x.write(servo_x_ang);
  servo_y.write(servo_y_ang);
  pinMode(stick_x_pin, INPUT);
  pinMode(stick_y_pin, INPUT);
}

int calcAngle(int origin, int value) {
  if (abs(value - origin) < 2) {
    return 90;
  } else if (value > origin) {
    return map(value, 0, origin, 0, 90);  
  } 
  return map(value, origin, 1023, 90, 180);  
}

int calcAngle_x(int value) {
  return calcAngle(stick_x_origin, value);
}

int calcAngle_y(int value) { 
  return calcAngle(stick_y_origin, value);
}

void loop() {
  stick_x_value = analogRead(stick_x_pin);
  stick_y_value = analogRead(stick_y_pin);
  Serial.print("stick_x_value: ");
  Serial.print(stick_x_value);
  Serial.print(" /  stick_y_value: ");
  Serial.println(stick_y_value);

  servo_x.write(calcAngle_x(1023 - stick_x_value));
  servo_y.write(calcAngle_y(stick_y_value));

  delay(100);
}
