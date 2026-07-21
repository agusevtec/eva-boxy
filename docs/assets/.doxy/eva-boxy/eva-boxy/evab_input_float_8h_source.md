

# File evabInputFloat.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputFloat.h**](evab_input_float_8h.md)

[Go to the documentation of this file](evab_input_float_8h.md)


```C++
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class InputFloat : public ElementBase
  {
  public:
    InputFloat(float aValue = 0);
    
    void SetValue(float aValue);
    
    float GetValue() const;
    
    void Increment(signed char delta);

  protected:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    float mValue;  

  };

}
```


