

# File evabScreenBase.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenBase.h**](evab_screen_base_8h.md)

[Go to the documentation of this file](evab_screen_base_8h.md)


```C++
#pragma once
#include "evabCoor.h"
#include <Arduino.h>

#include <evabIScreen.h>

namespace evab
{
    class ScreenBase : public IScreen
    {
    public:
        void TextLeft(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) override;
        void TextCenter(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) override;
        void TextRight(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) override;
        void TextLeft(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) override;
        void TextCenter(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) override;
        void TextRight(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) override;
        void Clear(Coor aPosition, Coor aSize, unsigned char aColor) override;
        virtual void Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor);

    protected:

        virtual void ClearTile(Coor position, unsigned char aColor);

    private:
        void printTextInArea(Coor aPosition, Coor aSize, const char *text, unsigned char aColor, uint8_t offset);
        void printTextInArea(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor, uint8_t offset);

        uint8_t calcLeftOffset(Coor aSize, uint8_t textLen);
        uint8_t calcCenterOffset(Coor aSize, uint8_t textLen);
        uint8_t calcRightOffset(Coor aSize, uint8_t textLen);

        uint8_t flashStrLen(const __FlashStringHelper *str);
        char flashStrRead(const __FlashStringHelper *str, uint8_t index);
    };
}
```


