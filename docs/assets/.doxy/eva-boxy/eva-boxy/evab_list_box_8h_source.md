

# File evabListBox.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabListBox.h**](evab_list_box_8h.md)

[Go to the documentation of this file](evab_list_box_8h.md)


```C++
#pragma once

#include <evabWindowAlgorithms.h>
#include <evabElementBase.h>

namespace evab
{
  template <class TWindowAlgorithm>
  class ListBox : public ElementBase, public TWindowAlgorithm
  {
  private:
    ElementBase **mItems = nullptr;
    unsigned char mItemHeight = 1;

  public:
    ListBox<TWindowAlgorithm> &SetItems(ElementBase *aItems[], int aCount)
    {
      mItems = aItems;
      TWindowAlgorithm::setCount(aCount);
      if (aCount)
        Select(0);
      Redraw();
      return *this;
    }

    ListBox<TWindowAlgorithm> &SetItemHeight(unsigned char aItemHeight)
    {
      mItemHeight = aItemHeight;
      Redraw();
      return *this;
    }

    void Select(signed char aIndex) override
    {
      TWindowAlgorithm::Select(aIndex);
      Redraw();
    }

    ElementBase *GetItem(unsigned char aIndex)
    {
      if (aIndex < TWindowAlgorithm::Count())
        return mItems[aIndex];
      return nullptr;
    }

    void Increment(signed char delta)
    {
      Select(Selected() + delta);
    }

    bool Key(Keys aKey) override
    {
      signed char selected = TWindowAlgorithm::Selected();
      if (selected == -1)
        return false;

      if (mItems[selected]->Key(aKey))
        return true;

      return false;
    }

  protected:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      TWindowAlgorithm::resizeWindow(aSize.Y / mItemHeight);
      unsigned char visibleElementsCount = 0;
      signed char selected = TWindowAlgorithm::Selected();
      hider();
      for (int i = 0; i < TWindowAlgorithm::Count(); i++)
      {
        int offset = TWindowAlgorithm::indexInWindow(i) * mItemHeight;
        if (offset >= 0)
        {
          mItems[i]->Draw(aScreen, {aPos.X, aPos.Y + offset}, {aSize.X, mItemHeight}, aIsFocused && (i == selected));
          visibleElementsCount++;
        }
      }
      aScreen->Clear({aPos.X, aPos.Y + visibleElementsCount * mItemHeight}, {aSize.X, aSize.Y - visibleElementsCount * mItemHeight});
    }

    void hider() override
    {
      for (int i = 0; i < TWindowAlgorithm::Count(); i++)
        mItems[i]->Hide();
    }
  };

  using ScrollListbox = ListBox<ScrollWindowAlgorithm>;
  using FlipListbox = ListBox<FlipWindowAlgorithm>;
}
```


