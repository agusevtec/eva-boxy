

# File evabTitled.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabTitled.h**](evab_titled_8h.md)

[Go to the documentation of this file](evab_titled_8h.md)


```C++
#pragma once

#include <evabScreen.h>
#include <evabCoor.h>
#include <evabTextAlign.h>

namespace evab
{

  template <class T, typename TAlign, typename TText>
  class Titled : public T
  {
  public:
    template <typename... Args>
    Titled(TText aName, Args &&...args)
        : T(args...), mName(aName)
    {
    }

    void SetLabel(TText aName)
    {
      mName = aName;
      redraw();
    }

    TText GetLabel() const
    {
      return mName;
    }

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      if (aSize.Y == 1)
      {
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        aScreen->Text<TAlign>(aPos, {labelWidth, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, 1}, aIsFocused);
      }
      else
      {
        aScreen->Text<TAlign>(aPos, {aSize.X, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 1}, aIsFocused);
      }
    }

  private:
    TText mName; 
  };

  // ============================================================
  // Convenience aliases for const char* labels
  // ============================================================

  template <class T>
  using TitledLeft = Titled<T, LeftAlign, const char *>;

  template <class T>
  using TitledCenter = Titled<T, CenterAlign, const char *>;

  template <class T>
  using TitledRight = Titled<T, RightAlign, const char *>;

  // ============================================================
  // Convenience aliases for Flash string labels
  // ============================================================

  template <class T>
  using TitledLeftF = Titled<T, LeftAlign, const __FlashStringHelper *>;

  template <class T>
  using TitledCenterF = Titled<T, CenterAlign, const __FlashStringHelper *>;

  template <class T>
  using TitledRightF = Titled<T, RightAlign, const __FlashStringHelper *>;

}
```


