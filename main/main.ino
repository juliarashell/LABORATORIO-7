#include "controlPot.h"

ControlPot bultinLED(13);

void setup()
{
 bultinLED.begin();
}
void loop() 
{
  bultinLED.EncenderLed();
  bultinLED.ApagarLed();
}
