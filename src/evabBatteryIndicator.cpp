#include "evabBatteryIndicator.h"
#include <Arduino.h>

namespace evab
{

  extern char stringTemp[20];

  void BatteryIndicator::SetVoltage(float aVoltage)
  {
    mVoltage = aVoltage;
    Redraw();
  }

  void BatteryIndicator::drawer(IScreen *aScreen,Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    
    memset(stringTemp, '|', 7);
    dtostrf(mVoltage, 1, 2, stringTemp + 1);
    stringTemp[5] = 'v';
    stringTemp[7] = 0;
    aScreen->TextCenter(aPos, aSize, stringTemp, aIsFocused);
  }

}
