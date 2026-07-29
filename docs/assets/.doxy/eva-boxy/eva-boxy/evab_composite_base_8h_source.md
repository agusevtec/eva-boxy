

# File evabCompositeBase.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabCompositeBase.h**](evab_composite_base_8h.md)

[Go to the documentation of this file](evab_composite_base_8h.md)


```C++
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class CompositeBase : public ElementBase
  {
  public:
    bool Key(Keys aKey) override;

    bool IsFocused(ElementBase *aChild);

    ElementBase *GetFocused() const;

  protected:
    void focusChild(ElementBase *aChild);

  private:
    virtual bool onResidualKey(Keys aKey);

    virtual void hider() = 0;

  private:
    ElementBase *mFocusedChild = nullptr; 
  };

}
```


