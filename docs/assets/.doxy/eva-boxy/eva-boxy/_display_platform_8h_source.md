

# File DisplayPlatform.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**DisplayPlatform.h**](_display_platform_8h.md)

[Go to the documentation of this file](_display_platform_8h.md)


```C++
#ifndef PLATFORM_H
#define PLATFORM_H

#include "Coor.h"

#include "BoxyBaseElement.h"

enum DisplayPlatformAlign
{
  PA_LEFT = 0,
  PA_CENTER,
  PA_RIGHT
};

class DisplayPlatform
{
public:
  virtual void Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup) = 0;
  virtual void Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup = 0) = 0;
  virtual Coor Size() = 0;
  void Draw(BoxyBaseElement *aGroundElement = 0);
  void Key(Keys aKey);
  void SetFreeze(int aFreeze);
  
public:
  static DisplayPlatform *Instance(DisplayPlatform *aPlatform = 0);

private:
  BoxyBaseElement *mGroundElement = 0;
};

#endif
```


