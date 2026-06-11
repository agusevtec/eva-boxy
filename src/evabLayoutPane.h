#pragma once

#include <evabElementBase.h>

namespace evab
{
  struct LayoutPaneItem
  {
    ElementBase *Element;
    Coor Position;
    Coor Size;
  };

  class LayoutPane: public ElementBase
  {
  public:
    // LayoutPane(CompositeBase *aContainer);
      void SetItems(unsigned short aLayout, LayoutPaneItem aItems[], unsigned char  aCount);

  private:
    bool Key(Keys aKey) override;
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;
    void hider() override;
    static int digits(unsigned short n);
    static int getTileCount(unsigned short n, unsigned char row);

  private:
    LayoutPaneItem *mItems = nullptr;
    int mCount = 0;
    int mFocused = -1;
    unsigned short number;
  };
}
