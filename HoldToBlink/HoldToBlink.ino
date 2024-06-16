/*
  Press the button to make LED blink. Release the button to turn the LED off.
*/

const int buttonPin = 2; 
const int ledPin = 8; 
const int sleep = 250;

int ledState = HIGH;
int buttonState;

void setup() 
{

  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT_PULLUP); 

}

void loop() 
{

  buttonState = digitalRead(buttonPin);
  switch (buttonState)
  {
    // Button is pressed
    case LOW:
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      delay(sleep);
      break;
    // Button is not pressed
    case HIGH:
      digitalWrite(ledPin, HIGH);
  }

}
