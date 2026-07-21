

# File evabScreenSerialPixel.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenSerialPixel.h**](evab_screen_serial_pixel_8h.md)

[Go to the documentation of this file](evab_screen_serial_pixel_8h.md)


```C++
#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>

namespace evab
{
    class ScreenSerialPixel : public ScreenPage8Base
    {
    public:
        ScreenSerialPixel(IFont *aFont);

        void clear();
        
        void printToSerial();

        Coor Size() override;
        
        unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
        
        void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;

    private:
        uint8_t mBuffer[1024]; // 8 pages * 128 bytes = 1024 bytes
    };
}
```


