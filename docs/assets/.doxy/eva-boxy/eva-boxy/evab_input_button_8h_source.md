

# File evabInputButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputButton.h**](evab_input_button_8h.md)

[Go to the documentation of this file](evab_input_button_8h.md)


```C++
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class InputButton : public ElementBase
  {
  public:
    InputButton(const __FlashStringHelper *aName);
    
    void Increment(signed char delta);  // Placeholder, does nothing

  protected:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const __FlashStringHelper * mName;  
  };

}
```


