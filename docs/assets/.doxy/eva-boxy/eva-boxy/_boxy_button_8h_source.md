

# File BoxyButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyButton.h**](_boxy_button_8h.md)

[Go to the documentation of this file](_boxy_button_8h.md)


```C++
#ifndef BOXYBUTTON_H
#define BOXYBUTTON_H

#include "BoxyBaseElement.h"
#include <evaDelegate.h>
using namespace eva;

class BoxyButtonListboxItem : public BoxyBaseElement
{
public:
  BoxyButtonListboxItem(const char *aName);
  static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName);

private:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

private:
  const char *mName;
};

class BoxyButton : public BoxyButtonListboxItem
{
public:
  BoxyButton(const char *aName, IDelegate *aOnButtonPressedDelegate = 0);
  bool Key(char aKey) override;

private:
  IDelegate *mOnButtonPressedDelegate;
};

#endif
```


