#define BUZZER_PIN 26 

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.println("Testing Buzzer on GPIO 26...");
}

void loop() {
  // TEST 1: Simple Digital High (For Active Buzzers)
  Serial.println("Testing as Active Buzzer (DC High)...");
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);

  // TEST 2: PWM Tone (For Passive Buzzers)
  // This uses a built-in Arduino function that works on ESP32
  Serial.println("Testing as Passive Buzzer (Tone)...");
  tone(BUZZER_PIN, 2000); // 2000Hz frequency
  delay(500);
  noTone(BUZZER_PIN);
  delay(1000);
}