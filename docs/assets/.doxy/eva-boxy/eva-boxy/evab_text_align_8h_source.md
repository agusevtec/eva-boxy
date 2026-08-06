

# File evabTextAlign.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabTextAlign.h**](evab_text_align_8h.md)

[Go to the documentation of this file](evab_text_align_8h.md)


```C++
// evabTextAlign.h
#pragma once

#include <evabCoor.h>
#include <evabTextTraits.h>

namespace evab
{

    struct LeftAlign
    {
        static unsigned char Offset(Coor aSize, unsigned char textLen);
    };

    struct CenterAlign
    {
        static unsigned char Offset(Coor aSize, unsigned char textLen);
    };

    struct RightAlign
    {
        static unsigned char Offset(Coor aSize, unsigned char textLen);
    };

} // namespace evab
```


