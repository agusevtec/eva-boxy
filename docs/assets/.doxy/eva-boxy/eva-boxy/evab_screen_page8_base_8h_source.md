

# File evabScreenPage8Base.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenPage8Base.h**](evab_screen_page8_base_8h.md)

[Go to the documentation of this file](evab_screen_page8_base_8h.md)


```C++
#pragma once

#include <evabCoor.h>
#include <evabScreenBase.h>
#include <evabIFont.h>

namespace evab
{
  class ScreenPage8Base : public ScreenBase
  {
  public:
    ScreenPage8Base(const IFont* mFont);
    
    void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor);
    
    void Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor);
 
  protected:
    virtual void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) = 0;

  private:
    const IFont* mFont;  
    
    uint32_t upscaleY(uint8_t x, uint8_t scale);
  };

}
```


