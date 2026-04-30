const int PEDAL_PIN = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(PEDAL_PIN);
  raw = constrain(raw, 80, 1023);

  int percent = map(raw, 80, 1023, 0, 100);
  Serial.print("Raw: ");
  Serial.print(raw);

  Serial.print(" | Percent: ");
  Serial.print(percent);
  Serial.println(" %");

  delay(500);
}
