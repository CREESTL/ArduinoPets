/*
  Change voltage using potentiometer.
  Print the voltage.
*/

const short sensorPin = A0;

// Potentiometer can output the following values:
// 1. 0 (equals 0V)
// 2. 1023 (equals 5V)
// Each single value of potentiometer corresponds to this step in voltage.
const float step = 5.0 / 1023.0;

float toVoltage(int sensorValue)
{ 
  // Multiply number of steps and value of one step.
  return sensorValue * step;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage = toVoltage(analogRead(sensorPin));
  Serial.print("voltage = " );
  Serial.println(voltage, 5);
  delay(1000);
}
