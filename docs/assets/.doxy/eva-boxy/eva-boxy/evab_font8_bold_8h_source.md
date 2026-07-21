

# File evabFont8Bold.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabFont8Bold.h**](evab_font8_bold_8h.md)

[Go to the documentation of this file](evab_font8_bold_8h.md)


```C++
#pragma once

#include <Arduino.h>
#include <evabIFont.h>

namespace evab
{
    class Font8Bold : public IFont
    {
    public:
        unsigned char GetVerticalSlice(char aCharcode, unsigned char col) const override;

    private:
        static const unsigned char kCharmap[][8] PROGMEM; 
    };
}
```


