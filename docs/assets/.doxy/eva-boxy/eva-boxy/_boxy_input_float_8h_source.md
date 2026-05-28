

# File BoxyInputFloat.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyInputFloat.h**](_boxy_input_float_8h.md)

[Go to the documentation of this file](_boxy_input_float_8h.md)


```C++
#ifndef BOXYINPUTFLOAT_H
#define BOXYINPUTFLOAT_H

#pragma once

#include <evaDelegate.h>
#include "BoxyBaseElement.h"
using namespace eva;

class BoxyInputFloatField : public BoxyBaseElement
{
public:
  BoxyInputFloatField(const char *aName, float aValue);
  void SetValue(float aValue);
  float GetValue();
  static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, float aValue);

private:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

private:
  const char *mName;
  float mValue;
};

class BoxyInputFloat : public BoxyInputFloatField
{
public:
  BoxyInputFloat(const char *aName, float aValue, IDelegate *aOnValueChangedDelegate);
  bool Key(char aKey) override;

private:
  IDelegate *mOnValueChangedDelegate = 0;
};

#endif
```


