

//code pour simuler une pedale avec un potentiometre
const int pedalPin = A0; // Pin du potentiomètre


const int deadZone = 10;
const int maxPedalValue = 1023;

void pedalReadPercent() {
    pedalRaw = analogRead(pedalPin);
    raw=constrain(pedalRaw, deadZone, maxPedalValue);
    int percent=map(raw, deadZone, maxPedalValue, 0, 100);
    return percent;
}

void setup() {
    Serial.begin(115200);
}

void loop() {
    int pedalPercent = pedalReadPercent();
    int pedalRaw = analogRead(pedalPin);
//debug :

    Serial.print("Pedal Raw: ");
    Serial.print(pedalRaw);
    Serial.print(" | Pedal Percent: ");
    Serial.print(pedalPercent);
    Serial.println("%");

    delay(500);

}
