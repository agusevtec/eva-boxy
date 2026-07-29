

# File evabInputButtonPicto.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputButtonPicto.h**](evab_input_button_picto_8h.md)

[Go to the documentation of this file](evab_input_button_picto_8h.md)


```C++
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class InputButtonPicto : public ElementBase
  {
  public:
    InputButtonPicto(const unsigned char *aaPictogram);

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const unsigned char *maPictogram; 
  };

}
```


