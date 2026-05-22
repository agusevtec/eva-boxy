#pragma once

#include "..\..\src\evabCompositeBase.h"

namespace evab
{

  struct LayoutPaneItem
  {
    ElementBase *Element;
    Coor Position;
    Coor Size;
  };

  class LayoutPane : public CompositeBase
  {
  public:
    LayoutPane(CompositeBase *aContainer);
    void SetItems(LayoutPaneItem aItems[], int aCount);

  private:
    bool onResidualKey(char aKey) override;
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;

  private:
    LayoutPaneItem *mItems = nullptr;
    int mCount = 0;
    int mFocused = -1;
  };

}
