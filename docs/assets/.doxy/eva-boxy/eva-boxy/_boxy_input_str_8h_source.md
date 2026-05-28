

# File BoxyInputStr.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyInputStr.h**](_boxy_input_str_8h.md)

[Go to the documentation of this file](_boxy_input_str_8h.md)


```C++
#ifndef BOXYINPUTSTR_H
#define BOXYINPUTSTR_H

#pragma once

#include "Coor.h"

class BoxyInputStr
{
public:
    static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, const char *aValue);
};

#endif
```


