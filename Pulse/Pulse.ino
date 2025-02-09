/*
  Generate pulses and measure their duration.
*/


const byte tonePin = 3;
const byte readPin = 4;
// Frequency of tone
const short freq = 1500;
const float wave_period = 1.0 / freq;
// Expected duration of pulse in seconds.
const float pulse_duration = wave_period / 2.0;

float duration_micros;
float duration_s;

void setup() {
  pinMode(tonePin, OUTPUT);
  pinMode(readPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  tone(tonePin, freq, 500);
  duration_micros = pulseIn(readPin, HIGH);
  // Measured duration of pulse in seconds.
  duration_s = duration_micros / 1000000.0;
  Serial.print("Expected pulse duration: ");
  Serial.println(pulse_duration, 4);
  Serial.print("Measured pulse duration: ");
  Serial.println(duration_s, 4);
  Serial.println("\n");
  delay(1000);
}
