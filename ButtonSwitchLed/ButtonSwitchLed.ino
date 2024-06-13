/*
  Press and release the button to turn the LED on/off.

  (NOTE) This could be done with interruption mechanism, but I decided to use good old while loops
*/

// Include local button library
#include "Button.h"

const int buttonPin = 2; 
const int ledPin = 8; 

// Initially, the LED is off.
int ledState = HIGH;

// Filter time is 2ms * delayTime.
const int delayTime = 20;
Button button(buttonPin, delayTime);


void setup() 
{

  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, ledState);
  pinMode(buttonPin, INPUT_PULLUP); 

}

void loop() 
{

  button.scanState();

  // Check if button moves from HIGH to LOW
  if (button.flagClick == true)
  {
      // Turn the LED on/off
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      button.flagClick = false;
  }
  
}