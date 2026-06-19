

# File evabScreenSSH1106.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenSSH1106.h**](evab_screen_s_s_h1106_8h.md)

[Go to the documentation of this file](evab_screen_s_s_h1106_8h.md)


```C++
#pragma once

#include <evabCoor.h>
#include <evabScreenPage8Base.h>
#include <Wire.h>

namespace evab
{
    class ScreenSSH1106 : public ScreenPage8Base
    {
    public:
        ScreenSSH1106(const IFont* font, unsigned long aWireClock = 800000L);
        
        void clearDisplay();

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
        void ClearTile(Coor aPosition, unsigned char aColor) override;
        Coor Size() override;

    private:
        void sendCommand(unsigned char cmd);
        void setPage(unsigned char page);
        void setColumn(unsigned char col);

        uint8_t mAddress;
    };
}
```


