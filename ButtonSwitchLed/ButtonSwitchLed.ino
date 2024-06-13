/*
  Press and release the button to turn the LED on/off.

  (NOTE) This could be done with interruption mechanism, but I decided to use good old while loops
*/

// This pin is chosen because pins 2 and 3 also serve as external inturrupt inputs.
const int buttonPin = 2; 
const int ledPin = 8; 

// Initially, the LED is off
int ledState = HIGH; 
int buttonState = HIGH;


void setup() 
{

  pinMode(ledPin, OUTPUT); 
  // Turn off the target LED
  digitalWrite(ledPin, ledState); 
  
  // The pull-up resistor is in the circuit
  pinMode(buttonPin, INPUT_PULLUP); 

}

void loop() 
{

  // Wait for button to be pressed
  while(digitalRead(buttonPin) == buttonState) {}
  
  // Turn the LED on/off
  ledState = !ledState;
  digitalWrite(ledPin, ledState);

  // Mark that button was pressed
  buttonState = !buttonState;
  
  // Wait for button to be pressed
  while(digitalRead(buttonPin) == buttonState) {}

  // Mark that button was released
  buttonState = !buttonState;
}