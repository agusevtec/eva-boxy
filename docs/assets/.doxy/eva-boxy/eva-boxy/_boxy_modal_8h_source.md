

# File BoxyModal.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyModal.h**](_boxy_modal_8h.md)

[Go to the documentation of this file](_boxy_modal_8h.md)


```C++
#ifndef BOXYMODAL_H
#define BOXYMODAL_H

#pragma once
#include <evaTimer.h>
#include "DisplayPlatform.h"
using namespace eva;

class BoxyModal
{
public:
    static BoxyModal &Instance();
    void ShowInt(const char *aName, int aValue);
    void onTimeout(void *aMsgSender, long aArgsMask);;

private:
    BoxyModal();

private:
    Timer mTimer = {new Delegate<BoxyModal>(this, &onTimeout)};
    DisplayPlatform *mDisplayPlatform = DisplayPlatform::Instance();
};

#endif
```


