

# File BoxyInputInt.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyInputInt.h**](_boxy_input_int_8h.md)

[Go to the documentation of this file](_boxy_input_int_8h.md)


```C++
#ifndef BOXYINPUTINT_H
#define BOXYINPUTINT_H

#pragma once
#include <evaDelegate.h>
#include "BoxyBaseElement.h"
using namespace eva;

class BoxyInputIntField : public BoxyBaseElement
{
public:
  BoxyInputIntField(const char *aName, int aValue);
  void SetValue(int aValue);
  int GetValue();
  static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, int aValue);

private:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

private:
  const char *mName;
  int mValue;
};

class BoxyInputInt : public BoxyInputIntField
{
public:
  BoxyInputInt(const char *aName, int aValue, IDelegate *aOnValueChangedDelegate);
  bool Key(char aKey) override;

private:
  IDelegate *mOnValueChangedDelegate = 0;
};

#endif
```


