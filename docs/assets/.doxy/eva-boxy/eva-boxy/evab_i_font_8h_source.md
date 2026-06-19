

# File evabIFont.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabIFont.h**](evab_i_font_8h.md)

[Go to the documentation of this file](evab_i_font_8h.md)


```C++
#pragma once

namespace evab
{
    class IFont
    {
    public:
        virtual unsigned char GetVerticalSlice(char aCharcode, unsigned char col) const = 0;
    };

}
```


