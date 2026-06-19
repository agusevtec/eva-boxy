

# File evabBatteryIndicator.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabBatteryIndicator.h**](evab_battery_indicator_8h.md)

[Go to the documentation of this file](evab_battery_indicator_8h.md)


```C++
#pragma once

#include "evabElementBase.h"

namespace evab
{

  class BatteryIndicator : public ElementBase
  {
  public:
    void SetVoltage(float aVoltage);

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    float mVoltage = 0;
  };

}
```


