

# File BoxyListBox.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyListBox.h**](_boxy_list_box_8h.md)

[Go to the documentation of this file](_boxy_list_box_8h.md)


```C++
#ifndef BOXYLISTBOX_H
#define BOXYLISTBOX_H

#pragma once
#include "SlidingMethods.h"
#include "BoxyBaseComposite.h"
#include <evaDelegate.h>
using namespace eva;

class BoxyListBox : public BoxyBaseComposite
{
public:
  BoxyListBox(BoxyBaseComposite *aParent, SlidingMethodBase *aSlidingMethod);
  BoxyListBox &SetItems(BoxyBaseField *aItems[], int aCount);
  BoxyListBox &SetGap(unsigned char aGap);
  BoxyListBox &SetReadOnly(bool aIsReadonly);
  BoxyListBox &SetOnItemModified(IDelegate *aOnItemModifyDelegate);

  BoxyBaseField *GetItem(unsigned char aIndex);
  void Select(int mIndex);
  int Selected();
  int Count();
  int PageSize();

private:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;
  bool onKey(char aKey) override;

private:
  BoxyBaseField **mItems;
  SlidingMethodBase *mSlidingMethod;
  IDelegate *mOnItemModifyDelegate = 0;
  unsigned char mGap = 1;
  bool mIsReadOnly = false;
};

#endif
```


