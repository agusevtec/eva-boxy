

# File BoxyBaseField.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyBaseField.h**](_boxy_base_field_8h.md)

[Go to the documentation of this file](_boxy_base_field_8h.md)


```C++
#ifndef BASEBOXYFIELD_H
#define BASEBOXYFIELD_H

#pragma once

#include "Coor.h"

class BoxyBaseField
{
public:

  bool IsHidden();

  void Draw(Coor aPos, Coor aSize, unsigned char aSelected);

protected:
    void updateView();

private:
  virtual void drawer(Coor aPos, Coor aSize, unsigned char aSelected) = 0;

private:
  unsigned char mPos = 0;
  unsigned char mSize = 0;
};

#endif
```


