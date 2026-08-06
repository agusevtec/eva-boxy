

# File evabKeyReactor.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabKeyReactor.h**](evab_key_reactor_8h.md)

[Go to the documentation of this file](evab_key_reactor_8h.md)


```C++
#pragma once

#include <evaHandler.h>

namespace evab
{
  template <class T, unsigned char kDec, unsigned char kInc>
  class KeyReactor : public T
  {
  public:
    enum EventType
    {
      EVENT_VALUE_CHANGED = 2, 
    };

    template <typename... Args>
    KeyReactor(eva::IHandler *aListener, Args &&...args)
        : T(args...), mListener(aListener)
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

      if (mListener)
        mListener->invoke((void *)this, {EVENT_VALUE_CHANGED, 0});
      return true;
    }

  private:
    eva::IHandler *mListener = nullptr; 
  };

}
```


