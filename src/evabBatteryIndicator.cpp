#include "evabBatteryIndicator.h"
#include <Arduino.h>

namespace evab
{


  void BatteryIndicator::SetVoltage(float aVoltage)
  {
    mVoltage = aVoltage;
    Redraw();
  }

  void BatteryIndicator::drawer(IScreen *aScreen,Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    
    char stringTemp[20];
    memset(stringTemp, '|', 7);
    dtostrf(mVoltage, 1, 2, stringTemp + 1);
    stringTemp[5] = 'v';
    stringTemp[7] = 0;
    aScreen->TextCenter(aPos, aSize, stringTemp, aIsFocused);
  }

}
