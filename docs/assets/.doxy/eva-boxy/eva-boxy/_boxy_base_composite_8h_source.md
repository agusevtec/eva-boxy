

# File BoxyBaseComposite.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyBaseComposite.h**](_boxy_base_composite_8h.md)

[Go to the documentation of this file](_boxy_base_composite_8h.md)


```C++
#ifndef BOXYCONTAINERBASE_H
#define BOXYCONTAINERBASE_H

#include "BoxyBaseElement.h"

class BoxyBaseComposite : public BoxyBaseElement
{
public:
  BoxyBaseComposite(BoxyBaseComposite *aParent = 0);
  bool IsFocused(BoxyBaseElement *aChild);
  bool IsFocused();
  bool Key(Keys aKey) override;

protected:
  void focusChild(BoxyBaseElement *aChild);

private:
  virtual bool onKey(Keys aKey);

private:
  BoxyBaseElement *mFocusedChild = 0;
  BoxyBaseComposite *mParent;
};

#endif
```


