

# File evabSerializers.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabSerializers.h**](evab_serializers_8h.md)

[Go to the documentation of this file](evab_serializers_8h.md)


```C++
#pragma once
#include <evabCoor.h>

namespace evab
{
    unsigned short serialize_16x8(const Coor &aPos, const Coor &aSize, bool isFocused);
    
    void deserialize_16x8(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    unsigned short serialize_32x4(const Coor &aPos, const Coor &aSize, bool isFocused);
    
    void deserialize_32x4(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);
}
```


