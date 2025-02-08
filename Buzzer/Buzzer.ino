/*

  Simple buzzer.

*/

const int soundPin = 3;
const int dTime = 1000;

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {

  digitalWrite(soundPin, HIGH);
  delay(dTime);

  digitalWrite(soundPin, LOW);
  delay(dTime);
}
