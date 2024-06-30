// Pins 2 or 3 should be used for interruptions on UNO.
const int buttonPin = 2;

// Time each LED is on.
const int flashTime = 500;

// Pins that must light up.
const int minPin = 3;
const int maxPin = 8;

// Initially, the light runs from the lowest pinID to the highest.
volatile int runStart = minPin;
volatile int runEnd = maxPin + 1;
volatile int step = 1;


// Changes the direction of light movement.
void pinISR()
{
  // Change direction of lights running with button click.
  step = -step;
  if (runStart == minPin)
  {
    runStart = maxPin;
    runEnd = minPin - 1;
  }
  else
  {
    runStart = minPin;
    runEnd = maxPin + 1;
  }

}


void setup()
{
  for (int pin = minPin; pin <= maxPin; pin++)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  // Handle button pressed with interruption. This allows
  // to change direction when light is already moving.
  attachInterrupt(
    digitalPinToInterrupt(buttonPin), 
    pinISR, 
    FALLING
  );
}


void loop()
{
  // Run light in a given direction.
  for (int pin = runStart; pin != runEnd; pin += step)
  {
    digitalWrite(pin, LOW);
    delay(flashTime);
    digitalWrite(pin, HIGH);
  }
}

