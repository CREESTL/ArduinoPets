

const int soundPin = 3;

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {

  digitalWrite(soundPin, HIGH);
  delay(1000);

  digitalWrite(soundPin, LOW);
  delay(1000);
}
