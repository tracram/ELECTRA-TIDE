#include <Arduino.h>
#include liquidcrystal_I2C.h
#include Wire.h 

//code pour simuler une pedale avec un potentiometre
const int pedalPin = A0; // Pin du potentiomètre
int pedalRaw = 0;
float pedalPercent = 0.0;

const int deadZone = 10;
const int maxPedalValue = 1023;

void setup() {
    Serial.begin(115200);
}

void loop() {
    pedalRaw = analogRead(pedalPin);
    if (pedalRaw < deadZone) {
        pedalRaw = 0;
    } else if (pedalRaw > maxPedalValue - deadZone) {
        pedalRaw = maxPedalValue;
    }
    pedalPercent = ((float)pedalRaw / (float)maxPedalValue) * 100.0;
    Serial.println(pedalPercent);
//debug :

    Serial.print("Pedal Raw: ");
    Serial.print(pedalRaw);
    Serial.print(" | Pedal Percent: ");
    Serial.print(pedalPercent);
    Serial.println("%");

    delay(100);

}
