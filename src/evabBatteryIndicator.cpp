#include "evabBatteryIndicator.h"
#include "evabDisplayPlatform.h"
#include <Arduino.h>

namespace evab
{

  extern char stringTemp[20];

  void BatteryIndicator::SetVoltage(float aVoltage)
  {
    mVoltage = aVoltage;
    Redraw();
  }

  void BatteryIndicator::drawer(Coor aPos, Coor aSize, unsigned char aSelected)
  {
    DisplayPlatform *p = DisplayPlatform::Instance();
    memset(stringTemp, '|', 7);
    dtostrf(mVoltage, 1, 2, stringTemp + 1);
    stringTemp[5] = 'v';
    stringTemp[7] = 0;
    p->Display(aPos, aSize, stringTemp, PA_CENTER, aSelected);
  }

}
