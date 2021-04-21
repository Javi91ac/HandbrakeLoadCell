// Ebrake with loadcell
// 
// original handbrake code AMSTUDIO 
// original load cell scale code by robtillaart
// edited for loadcell by backcountrybum
// 
// Edit for loadcell NA151 200Kg By Javi91ac thx AMSTUDIO, robtillart and backcounttrybum
// 21.04.2021



#include <Joystick.h>

#include "HX711.h"

// Create Joystick
Joystick_ Joystick;

HX711 scale;

uint8_t dataPin = 6;
uint8_t clockPin = 5;

uint32_t start, stop;
volatile float f;

void setup()

{Serial.begin(115200);
  // Serial.println(__FILE__);
  // Serial.print("LIBRARY VERSION: ");
  // Serial.println(HX711_LIB_VERSION);
  // Serial.println();

  scale.begin(dataPin, clockPin);

  // TODO find a nice solution for this calibration..
  // loadcell factor 20 KG
  // scale.set_scale(127.15);
  // loadcell factor 5 KG
  scale.set_scale(40);
  // reset the scale to zero = 0
  scale.tare();
   Joystick.begin();}



void loop()

{int pot = scale.get_units(5);
int mapped = map(pot,0,2500,0,255);
{Joystick.setThrottle(mapped);}
Serial.println(pot);
}
