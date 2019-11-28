
// 本程序无需接线，让 Uno/Nano 的板载LED闪烁，并向串口发送计数信息
// 串口通信率9600波特，计数和闪烁每秒钟发生一次

int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, counter++ % 2 ? HIGH : LOW);
  Serial.print(String(count) + "\n");
  delay(1000);
}
