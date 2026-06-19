

# File evabScreenSerialText.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenSerialText.h**](evab_screen_serial_text_8h.md)

[Go to the documentation of this file](evab_screen_serial_text_8h.md)


```C++
#pragma once

#include <evabScreenBase.h>

namespace evab
{

    class ScreenSerialText : public ScreenBase
    {
    public:
        ScreenSerialText();
        
        void clear();
        void printToSerial();
        
        Coor Size() override;

    protected:
        void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor) override;

    private:
        char mBuffer[128];
    };

}
```


