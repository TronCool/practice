
//Uno onboard LED will blink every second(on/off).
//Serial will count times.

int LED_PIN = 13;
int count = 0;

void setup(){
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
}

void loop(){
    digitalWrite(LED_PIN, count++ % 2 ? HIGH : LOW);
    Serial.print(String(count) + "\n");
    delay(1000);
}
