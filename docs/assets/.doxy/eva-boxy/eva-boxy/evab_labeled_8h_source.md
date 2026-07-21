

# File evabLabeled.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabLabeled.h**](evab_labeled_8h.md)

[Go to the documentation of this file](evab_labeled_8h.md)


```C++
#pragma once

#include <evabIScreen.h>
#include <evabCoor.h>

namespace evab
{

  template <class T>
  class Labeled : public T
  {
  public:
    template<typename... Args>
    Labeled(const char *aName, Args&&... args) 
      : T(args...), mName(aName)
    {
    }

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      if (aSize.Y == 1)
      {
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        
        aScreen->TextLeft(aPos, {labelWidth, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, 1}, aIsFocused);
      }
      else
      {
        aScreen->TextLeft(aPos, {aSize.X, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 1}, aIsFocused);
      }
    }

  private:
    const char *mName;  
  };

  template <class T>
  class LabeledF : public T
  {
  public:
    template<typename... Args>
    LabeledF(const __FlashStringHelper *aName, Args&&... args) 
      : T(args...), mName(aName)
    {
    }

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      if (aSize.Y == 1)
      {
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        
        aScreen->TextLeft(aPos, {labelWidth, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, 1}, aIsFocused);
      }
      else
      {
        aScreen->TextLeft(aPos, {aSize.X, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 1}, aIsFocused);
      }
    }

  private:
    const __FlashStringHelper *mName;  
  };

}
```


