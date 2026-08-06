

# File evabLabeled.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabLabeled.h**](evab_labeled_8h.md)

[Go to the documentation of this file](evab_labeled_8h.md)


```C++
// evabLabeled.h
#pragma once

#include <evabScreen.h>
#include <evabCoor.h>
#include <evabTextAlign.h>

namespace evab
{

  template <class T, typename TAlign, typename TText>
  class Labeled : public T
  {
  public:
    template <typename... Args>
    Labeled(TText aName, Args &&...args)
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
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        aScreen->Text<TAlign>(aPos, {labelWidth, 1}, mName, aIsFocused);
        aScreen->Clear({aPos.X, aPos.Y + 1}, {labelWidth, aSize.Y - 1}, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, aSize.Y}, aIsFocused);
      }
    }

  private:
    TText mName; 
  };

  // ============================================================
  // Convenience aliases for const char* labels
  // ============================================================

  template <class T>
  using LabeledLeft = Labeled<T, LeftAlign, const char *>;

  template <class T>
  using LabeledCenter = Labeled<T, CenterAlign, const char *>;

  template <class T>
  using LabeledRight = Labeled<T, RightAlign, const char *>;

  // ============================================================
  // Convenience aliases for Flash string labels
  // ============================================================

  template <class T>
  using LabeledLeftF = Labeled<T, LeftAlign, const __FlashStringHelper *>;

  template <class T>
  using LabeledCenterF = Labeled<T, CenterAlign, const __FlashStringHelper *>;

  template <class T>
  using LabeledRightF = Labeled<T, RightAlign, const __FlashStringHelper *>;

}
```


