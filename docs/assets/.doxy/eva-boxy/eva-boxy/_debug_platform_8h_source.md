

# File DebugPlatform.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**DebugPlatform.h**](_debug_platform_8h.md)

[Go to the documentation of this file](_debug_platform_8h.md)


```C++
#ifndef DEBUGPLATFORM_H_
#define DEBUGPLATFORM_H_

#include "DisplayPlatform.h"
#include <evaTimer.h>
#pragma once
using namespace eva;

class DebugPlatform : public DisplayPlatform
{
public:
  DebugPlatform();
  void Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup) override;
  void Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup) override;
  Coor Size();
  void Debug(void *aMsgSender, long aArgsMask);

private:
  char mField[7][13];
  Timer t = {new Delegate<DebugPlatform>(this, &Debug)};
};

#endif
```


