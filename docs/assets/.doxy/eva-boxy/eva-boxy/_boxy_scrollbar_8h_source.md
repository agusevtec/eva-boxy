

# File BoxyScrollbar.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**BoxyScrollbar.h**](_boxy_scrollbar_8h.md)

[Go to the documentation of this file](_boxy_scrollbar_8h.md)


```C++
#ifndef BOXYSCROLLBAR_H
#define BOXYSCROLLBAR_H

#include "BoxyBaseElement.h"
#include <evaDelegate.h>
using namespace eva;

class BoxyScrollbarField : public BoxyBaseElement
{
public:
  BoxyScrollbarField(unsigned aCount);
  void SetPosition(int aPosition);
  int GetPosition();
  static void IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, unsigned aPosition, unsigned aCount);

  private:
  void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;

private:
  int mPosition;
  unsigned mCount;
};

class BoxyScrollbar : public BoxyScrollbarField
{
public:
  BoxyScrollbar(unsigned aCount, IDelegate *aOnPositionChanged);
  bool Key(char aKey) override;

private:
  IDelegate *mOnPositionChanged;
};

#endif
```


