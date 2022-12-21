#include <Arduino.h>

// @author PoofyPloop

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop()
{
  int iVal;
  float analogVal;
  float temp;
  String judge;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  analogVal = iVal * (3.3 / 1023.0);
  temp = analogVal * (50 / 3.3);

  if (temp < 10)
  {
    judge = "Cold!";
  }
  else if (temp <= 15)
  {
    judge = "Cool";
  }
  else if (temp <= 25)
  {
    judge = "Perfect";
  }
  else if (temp <= 30)
  {
    judge = "Warm";
  }
  else if (temp < 35)
  {
    judge = "Hot";
  }
  else if (temp > 35)
  {
    judge = "Too Hot!";
  }

  // print value to the USB port
  // Serial.println("Digitized Value = " + String(iVal));
  Serial.printf("Digitized Value = %s, which is equivalent to an Analog Voltage = %sV\n", String(iVal), String(analogVal));
  Serial.printf("Temperature = %s deg. C which is %s\n", String(temp), judge);

  // wait 2 seconds
  delay(2000);
}
