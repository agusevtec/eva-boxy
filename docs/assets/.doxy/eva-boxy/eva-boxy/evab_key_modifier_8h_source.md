

# File evabKeyModifier.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabKeyModifier.h**](evab_key_modifier_8h.md)

[Go to the documentation of this file](evab_key_modifier_8h.md)


```C++
#pragma once

#include <evaHandler.h>

namespace evab
{

  template <class T, unsigned char kDec, unsigned char kInc>
  class KeyModifier : public T
  {
  public:
    template <typename... Args>
    KeyModifier(Args &&...args)
        : T(args...)
    {
    }

    bool OnKey(Keys aKey) override
    {
      if (T::OnKey(aKey))
        return true;

      if (aKey == kDec)
        T::Increment(-1);
      else if (aKey == kInc)
        T::Increment(+1);
      else
        return false;

      return true;
    }
  };

}
```


