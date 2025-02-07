/*
  Running light using timer interrupts on timer 0.
*/

// Pins 2 or 3 should be used for interruptions on UNO.
const short buttonPin = 2;

// Time each LED is on.
const short flashTime = 200;

// Counter of milliseconds
volatile short mCount = 0;

// Pins that must light up.
const short minPin = 3;
const short maxPin = 8;

// Initially, the light runs from the lowest pinID to the highest.
volatile short runStart = minPin;
volatile short runEnd = maxPin + 1;
volatile short step = 1;

// Current pin
volatile unsigned short pin = runStart;

// Custom interruption handler for comparison interruption on timer 0.
// Gets called each 1 ms.
SIGNAL(TIMER0_COMPA_vect)
{
  
  mCount++;

  // Current LED has been on for required number of milliseconds.
  if (mCount >= flashTime)
  {

    mCount = 0;

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

}


void setup()
{
  for (int pin = minPin; pin <= maxPin; pin++)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  pinMode(buttonPin, INPUT_PULLUP);

  // **Some register magic**

  // ATmega323's timer supports 2 kinds of interruptions:
  // 1. Overflow interruption
  // 2. Comparison interruption. On each tick it compares its current value with the value 
  // inside OCR0A register and if they match, it calls the comparison interruption.
  // A rule of thumb is to use a value around the half of the max value (255 or 0xFF) in the comparison register.
  // This will give the CPU enough time to:
  // 1. Handle comparison interruption (on tick 175, for example)
  // 2. Then, handle overflow interruption (on tick 255)
  // Comparison interruptions have the same period: 1 ms.
  OCR0A = 0xAF;
  // TIMSK0 bitmask activates/deactivates supported kinds on interruptions on timer 0.
  // Bit responsible for comparison interruptions has number OCIE0A.
  // First, create a mask with 1 on the OCIE0A position.
  // Then, do a bitwise-OR with the TIMSK0 and this mask to set the bit on position OCIE0A inside TIMSK0 to 1.
  // This will activate comparison interruptions on timer 0.
  TIMSK0 |= (1 << OCIE0A);
}


void loop()
{
  // Main loop is empty. All logic is handled in the ISR function.
}