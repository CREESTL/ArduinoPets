/*
  Press and hold the button to turn the LED on.
  Release the button to turn the LED off.
*/


const int buttonPin = 2; // This pin is chosen because pins 2 and 3 also serve as external inturrupt inputs.
const int ledPin = 8; 

// Handle interruption on pressed button
void pinISR()
{

  // LED is on when pin level is 0
  digitalWrite(
    ledPin, 
    digitalRead(buttonPin) // 0 when button is pressed, otherwise 1
  );
}

void setup() 
{

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED 

  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, HIGH); // Turn off the target LED

  pinMode(buttonPin, INPUT_PULLUP); // The pull-up resistor is in the circuit

  // Create Interrupt Service Routine for buttonPin
  attachInterrupt(
    digitalPinToInterrupt(buttonPin), // Get interruption number based on pin number
    pinISR, // This function will be called to handle the interruption
    CHANGE // ISR will be called on any signal change: LOW to HIGH or HIGH to LOW
  );

}

void loop() 
{
  // Any code can be placed here. Because pressed button is handled by the interruption.
}