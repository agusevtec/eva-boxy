

# File BoxyBatteryIndicator.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyBatteryIndicator.h**](_boxy_battery_indicator_8h.md)

[Go to the documentation of this file](_boxy_battery_indicator_8h.md)


```C++
#ifndef BOXYBATTERYINDICATOR_H
#define BOXYBATTERYINDICATOR_H

#pragma once

#include "BoxyBaseField.h"

class BoxyBatteryIndicator: public BoxyBaseField
{
public:
    void SetVoltage(float aVoltage);

private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

private:
    float mVoltage = 0;
};

#endif
```


