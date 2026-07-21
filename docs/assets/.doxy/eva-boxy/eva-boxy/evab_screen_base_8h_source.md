

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
        void printTextInArea(Coor aPosition, Coor aSize, const char *text, unsigned char aColor, unsigned char offset);
        
        void printTextInArea(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor, unsigned char offset);

        unsigned char calcLeftOffset(Coor aSize, unsigned char textLen);
        
        unsigned char calcCenterOffset(Coor aSize, unsigned char textLen);
        
        unsigned char calcRightOffset(Coor aSize, unsigned char textLen);

        unsigned char flashStrLen(const __FlashStringHelper *str);
        
        char flashStrRead(const __FlashStringHelper *str, unsigned char index);
    };
}
```


