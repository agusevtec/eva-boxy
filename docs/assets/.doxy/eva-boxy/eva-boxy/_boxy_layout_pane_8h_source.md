

# File BoxyLayoutPane.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyLayoutPane.h**](_boxy_layout_pane_8h.md)

[Go to the documentation of this file](_boxy_layout_pane_8h.md)


```C++
#ifndef BOXYLAYOUTPANE_H
#define BOXYLAYOUTPANE_H

#pragma once

#include "BoxyBaseComposite.h"

struct BoxyLayoutPaneItem
{
  BoxyBaseElement *Element;
  Coor Position;
  Coor Size;
};

class BoxyLayoutPane : public BoxyBaseComposite
{
public:
  BoxyLayoutPane(BoxyBaseComposite *aContainer);
  void SetItems(BoxyLayoutPaneItem aItems[], int aCount);

private:
  bool onKey(char aKey) override;
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

private:
  BoxyLayoutPaneItem *mItems;
  int mCount;
  int mFocused = -1;
};

#endif
```


