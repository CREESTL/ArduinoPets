/*
  Change voltage using potentiometer.
  Change LED brightness according to voltage.
*/

const short sensorPin = A0;
const short LEDPin = 11;

int sensorValue = 0;
int LEDValue = 0;

// Convert value received from potentiometer to range supported by LED
// Potentiometer range: 0 - 1023
// LED range: 0 - 255
int convert(int sensorValue)
{
  return sensorValue / 4;
}

void setup() {
}

void loop() {
  sensorValue = analogRead(sensorPin);
  LEDValue = convert(sensorValue);
  // When LEDValue is 0 - the LED is off.
  // When LEDValue is 255 - LED has full brightness.
  analogWrite(LEDPin, LEDValue);
}
