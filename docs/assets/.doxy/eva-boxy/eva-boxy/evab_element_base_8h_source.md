

# File evabElementBase.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabElementBase.h**](evab_element_base_8h.md)

[Go to the documentation of this file](evab_element_base_8h.md)


```C++
#pragma once
#include <evabCoor.h>
#include <evabIScreen.h>
#include <evabKeys.h>

namespace evab
{

  class ElementBase
  {
  public:
    virtual bool Key(Keys aKey);
    void Hide();
    void Draw(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);
    void Redraw();
    bool IsHidden();

  private:
    virtual void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) = 0;
    virtual void hider() {};

    void serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
    void deserialize(Coor &aPos, Coor &aSize, bool &isFocused);

  private:
    unsigned short serialized = 0;
  };

}
```


