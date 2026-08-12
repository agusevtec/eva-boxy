

# File evabScreenPage8Base.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenPage8Base.h**](evab_screen_page8_base_8h.md)

[Go to the documentation of this file](evab_screen_page8_base_8h.md)


```C++
#pragma once

#include <evabCoor.h>
#include <evabScreen.h>
#include <evabIFont.h>

namespace evab
{
  class ScreenPage8Base : public Screen
  {
  public:
    ScreenPage8Base(const IFont *aFont);

    void Picto(Coor aPosition, const unsigned char *aPictogram, unsigned char aColor);

    void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor);

  private:

    virtual void drawVerticalSlice(Coor aPosition, unsigned char aCutColsumn, unsigned char aSlice) = 0;

    uint32_t upscaleY(uint8_t aSlice, uint8_t aScale);

  private:
    const IFont *mFont; 
  };

}
```


