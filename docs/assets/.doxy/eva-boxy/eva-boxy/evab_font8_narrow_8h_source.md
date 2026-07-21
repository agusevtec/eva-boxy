

# File evabFont8Narrow.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabFont8Narrow.h**](evab_font8_narrow_8h.md)

[Go to the documentation of this file](evab_font8_narrow_8h.md)


```C++
#pragma once

#include <evabIFont.h>
#include <Arduino.h>

namespace evab
{
    class Font8Narrow : public IFont
    {
    public:
        unsigned char GetVerticalSlice(char aCharcode, unsigned char aSliceColumn) const override;

    private:
        static const unsigned char kCharmap[][7] PROGMEM; 
    };
}
```


