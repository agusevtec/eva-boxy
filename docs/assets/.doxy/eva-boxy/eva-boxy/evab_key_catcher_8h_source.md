

# File evabKeyCatcher.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabKeyCatcher.h**](evab_key_catcher_8h.md)

[Go to the documentation of this file](evab_key_catcher_8h.md)


```C++
#pragma once

#include <evaHandler.h>

namespace evab
{

  template <class T, Keys... KEYS>
  class KeyCatcher : public T
  {
  public:
    template <typename... Args>
    KeyCatcher(eva::IHandler *aListener, Args &&...args)
        : T(args...), mListener(aListener)
    {
    }

    bool OnKey(Keys aKey) override
    {
      if (T::OnKey(aKey))
        return true;

      if ((... || (aKey == KEYS)))
      {
        if (mListener)
        {
          mListener->invoke(this, {0, (int)aKey});
          return true;
        }
      }
      return false;
    }

  private:
    eva::IHandler *mListener = nullptr; 
  };

}
```


