/*
  Read digits sent to Arduino from PC and turn on matching LEDs.

  Total of 4 LEDs on pins 2-5.

  Example of input: 44421
  Result:
  - LED#4 turns on 3 times for 1 second
  - LED#2 turns on for 1 second
  - LED#1 turns on for 1 second
  Digit 1 in COM port turns on LED#1 on pin 2 for 1 second.
  Same for other digits.
*/

const int dTime = 1000;
const int switchTime = 200;
const short minPin = 2;
const short maxPin = 5;
short pin;
short LEDIndex;
short portValue;


void setup() {
  for (pin = minPin; pin <= maxPin; pin++)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  Serial.begin(9600);
}

// Convert ASCII code to digit
short toDigit(short portValue)
{
  short ASCIIZero = 48;
  return portValue - ASCIIZero;
}

void loop() {
  // More than 0 bytes in COM port.
  if (Serial.available() > 0)
  {
    // Read 1 byte.
    portValue = Serial.read();
    // Indexing starts with 1.
    LEDIndex = toDigit(portValue);
    pin = LEDIndex + 1;  

    if (pin >= minPin && pin <= maxPin)
    {
      digitalWrite(pin, LOW);
      delay(dTime);
      digitalWrite(pin, HIGH);
      delay(switchTime);
    }
  }
}
