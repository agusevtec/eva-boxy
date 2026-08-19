

# File evabInputInt.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputInt.h**](evab_input_int_8h.md)

[Go to the documentation of this file](evab_input_int_8h.md)


```C++
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class InputInt : public ElementBase
  {
  public:
    InputInt(int aValue = 0);

    void SetValue(int aValue);

    int GetValue() const;

    void Increment(signed char aSteps);

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    int mValue; 
  };

  class InputIntDiscrete : public InputInt
  {

  public:
    InputIntDiscrete(int aValue, int aMin, int aMax, unsigned short aStep = 1);
    void Select(unsigned char aIndex);

    void SetValue(int aValue);

    signed short Selected() const;
    unsigned char Count() const;
    void Increment(signed char aSteps);

  private:
    int mMin;
    int mMax;
    unsigned short mStep;
  };

}
```


