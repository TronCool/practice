
//onboard LED will blink every second(on/off).
//Serial will count times.

int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, count++ % 2 ? HIGH : LOW);
  Serial.print(String(count) + "\n");
  delay(1000);
}
