#pragma once

#include "evabBaseComposite.h"

namespace evab
{

  struct LayoutPaneItem
  {
    BaseElement *Element;
    Coor Position;
    Coor Size;
  };

  class LayoutPane : public BaseComposite
  {
  public:
    LayoutPane(BaseComposite *aContainer);
    void SetItems(LayoutPaneItem aItems[], int aCount);

  private:
    bool onKey(char aKey) override;
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;

  private:
    LayoutPaneItem *mItems = nullptr;
    int mCount = 0;
    int mFocused = -1;
  };

}
