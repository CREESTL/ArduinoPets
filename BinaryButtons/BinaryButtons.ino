/*
  Press buttons to pass different values to serial port.
*/

const short buttonPin1 = 2;
const short buttonPin2 = 3;
const short confirmPin = 4;
short pin;

void setup() {
  for (pin = buttonPin1; pin <= confirmPin; pin++) pinMode(pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  for (pin = buttonPin1; pin <= confirmPin; pin++)
  {
    if (digitalRead(pin) == LOW) 
    {
    
      // Contact bounce protection
      delay(20);

      // While button is pressed - do nothing. Only pass value to serial port on button release.
      while (digitalRead(pin) == LOW) {}

      delay(20);

      if (pin == confirmPin) 
      {
        Serial.println(" ");
      } else if (pin == buttonPin1) 
      {
        Serial.print(0, DEC);
      } else if (pin == buttonPin2) 
      {
        Serial.print(1, DEC);
      }

      delay(20);

      // Only one button is supposed to be pressed
      break;
    }
  }

}
