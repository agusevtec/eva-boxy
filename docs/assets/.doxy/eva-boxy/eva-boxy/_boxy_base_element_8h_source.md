

# File BoxyBaseElement.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyBaseElement.h**](_boxy_base_element_8h.md)

[Go to the documentation of this file](_boxy_base_element_8h.md)


```C++
#ifndef BASEBOXY_H
#define BASEBOXY_H

#pragma once

#include "BoxyBaseField.h"

class BoxyBaseElement : public BoxyBaseField
{
public:
  virtual bool Key(Keys aKey);
};

#endif
```


