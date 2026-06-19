

# File evabScreenKS0108.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenKS0108.h**](evab_screen_k_s0108_8h.md)

[Go to the documentation of this file](evab_screen_k_s0108_8h.md)


```C++
#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>

namespace evab
{

    class ScreenKS0108 : public ScreenPage8Base
    {
    public:
        ScreenKS0108(const IFont *aFont,
                     uint8_t aRS, uint8_t aRW, uint8_t aE,
                     uint8_t aCS1, uint8_t aCS2,
                     uint8_t aDB0, uint8_t aDB1, uint8_t aDB2, uint8_t aDB3,
                     uint8_t aDB4, uint8_t aDB5, uint8_t aDB6, uint8_t aDB7,
                     uint8_t aLED = 255);
        ~ScreenKS0108();

        void setBacklight(uint8_t aState);
        void clear();
        Coor Size() override;

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
        void ClearTile(Coor aPosition, unsigned char aColor) override;

    private:
        void sendCommand(uint8_t aCmd, uint8_t aChip);
        void sendData(uint8_t aData, uint8_t aChip);
        void setChip(uint8_t aChip);
        void setPage(uint8_t aPage);
        void setColumn(uint8_t aCol);
        void initDisplay();

        void writeByte(uint8_t aByte);
        void pulseE();

        uint8_t mRSPin;
        uint8_t mRWPin;
        uint8_t mEPin;
        uint8_t mCS1Pin;
        uint8_t mCS2Pin;
        uint8_t mDataPins[8];
        uint8_t mLEDPin;
        uint8_t mCurrentChip;
    };

}
```


