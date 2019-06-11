#include <Arduino.h>

const int aMin = 0;
const int aMax = 1024;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  //connect AO on rain sensor to AO nodemcu
  int aRead = analogRead(A0);
  int r = map(aRead, aMin, aMax, 0, 3);

  // range value:
  switch (r)
  {
  case 0: // Sensor getting wet
    Serial.println("overflow Water");
    break;
  case 1: // Sensor getting wet
    Serial.println("Rain ALERT!!!");
    break;
  case 2: 
    Serial.println("Not Raining");
    break;
  }
  delay(1); // delay between reads
}