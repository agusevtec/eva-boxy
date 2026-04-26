

# File Gyver1306Platform.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**Gyver1306Platform.h**](_gyver1306_platform_8h.md)

[Go to the documentation of this file](_gyver1306_platform_8h.md)


```C++
#ifndef GYVER1306PLATFORM_H
#define GYVER1306PLATFORM_H

#include "DisplayPlatform.h"


class Gyver1306Platform : public DisplayPlatform
{
public:
  Gyver1306Platform();
  void Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup = 0) override;
  void Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup) override;
  Coor Size() override;

private:
  char mLine[16];
};

#endif
```


