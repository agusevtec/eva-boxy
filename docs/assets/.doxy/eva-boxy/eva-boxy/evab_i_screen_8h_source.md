

# File evabIScreen.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabIScreen.h**](evab_i_screen_8h.md)

[Go to the documentation of this file](evab_i_screen_8h.md)


```C++
#pragma once
#include <evabCoor.h>
#include <Arduino.h>

namespace evab
{
    class IScreen
    {
    public:
        virtual void TextLeft(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;
        
        virtual void TextCenter(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;
        
        virtual void TextRight(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;

        virtual void TextLeft(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;
        
        virtual void TextCenter(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;
        
        virtual void TextRight(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;

        virtual void Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor) = 0;
        
        virtual void Clear(Coor aPosition, Coor aSize, unsigned char aColor = 0) = 0;
        
        virtual void DrawSymbol(Coor aPosition, Coor aSize, char aSymbol, unsigned char aColor) = 0;
        
        virtual Coor Size() = 0;
        
        virtual unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused) = 0;
        
        virtual void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused) = 0;
    };
}
```


