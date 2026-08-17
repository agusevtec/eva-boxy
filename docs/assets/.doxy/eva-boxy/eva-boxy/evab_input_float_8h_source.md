

# File evabInputFloat.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputFloat.h**](evab_input_float_8h.md)

[Go to the documentation of this file](evab_input_float_8h.md)


```C++
// evabInputFloat.h
#pragma once

#include "evabElementBase.h"

namespace evab
{

  class InputFloat : public ElementBase
  {
  public:
    InputFloat(float aValue = 0);

    void SetValue(float aValue);

    float GetValue() const;

    void Increment(signed char aSteps);

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    float mValue; 
  };

  class InputFloatDiscrete : public InputFloat
  {
  public:
    InputFloatDiscrete(float aValue, float aMin, float aMax, float aStep = 0.1f);

    void Select(unsigned short aIndex);

    void SetValue(float aValue);

    signed short Selected() const;

    unsigned short Count() const;

    void Increment(signed char aSteps);

  private:
    float mMin;
    float mMax;
    float mStep;
  };
}
```


