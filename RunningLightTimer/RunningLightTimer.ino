#include <MsTimer2.h>

/*
  Running light using timer interrupts.
*/

// Pins 2 or 3 should be used for interruptions on UNO.
const int buttonPin = 2;

// Time each LED is on.
const int flashTime = 200;

// Time when current LED was turned on
unsigned int timeTurnedOn = 0;

// Pins that must light up.
const int minPin = 3;
const int maxPin = 8;

// Initially, the light runs from the lowest pinID to the highest.
volatile int runStart = minPin;
volatile int runEnd = maxPin + 1;
volatile int step = 1;

// Current pin
volatile unsigned short pin = runStart;

// Changes the direction of light movement.
void timerISR()
{
  
  // Turn off current LED
  digitalWrite(pin, HIGH);

  // If button is being pressed - change direction
  if (digitalRead(buttonPin) == LOW)
  {
    runStart = (runStart == minPin) ? maxPin : minPin;
    runEnd = (runEnd == maxPin + 1) ? (minPin - 1) : (maxPin + 1);
    step = -step;
  }

  pin += step;

  // If the end is reached - restart
  if (pin == runEnd)
  {
    pin = runStart;
  }

  // Turn on new LED
  digitalWrite(pin, LOW);

}


void setup()
{
  for (int pin = minPin; pin <= maxPin; pin++)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  // Set interruption to be handled periodically.
  MsTimer2::set(flashTime, timerISR);
  // Start generating interruptions
  MsTimer2::start();
}


void loop()
{
  // Main loop is empty. All logic is handled in the ISR function.
}