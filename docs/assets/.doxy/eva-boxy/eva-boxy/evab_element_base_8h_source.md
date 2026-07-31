

# File evabElementBase.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabElementBase.h**](evab_element_base_8h.md)

[Go to the documentation of this file](evab_element_base_8h.md)


```C++
#pragma once
#include <evabCoor.h>
#include <evabScreen.h>
#include <evabKeys.h>

namespace evab
{

  class ElementBase
  {
  public:
    virtual bool OnKey(Keys aKey);

    void Draw(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);

    void Freeze();

  protected:
    bool isFrozen();
    virtual void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) = 0;

    virtual void freezer() {};

    void redraw();

  private:
    unsigned short mSerialized = 0; 
  };

}
```


