

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
      redraw();
      return *this;
    }

    ListBox<TWindowAlgorithm> &SetItemHeight(unsigned char aItemHeight)
    {
      mItemHeight = aItemHeight;
      redraw();
      return *this;
    }

    void Select(unsigned char aIndex) override
    {
      TWindowAlgorithm::Select(aIndex);
      redraw();
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

    bool OnKey(Keys aKey) override
    {
      if (!mItems)
        return false;

      signed char selected = TWindowAlgorithm::Selected();
      if (selected == -1)
        return false;

      ElementBase *item = mItems[selected];
      if (!item)
        return false;

      return item->OnKey(aKey);
    }

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      TWindowAlgorithm::resizeWindow(aSize.Y / mItemHeight);
      unsigned char visibleElementsCount = 0;
      signed char selected = TWindowAlgorithm::Selected();
      freezer();
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

    void freezer() override
    {
      for (int i = 0; i < TWindowAlgorithm::Count(); i++)
        mItems[i]->Freeze();
    }
  };

  // Convenience typedefs for common list box types
  using ScrollListbox = ListBox<ScrollWindowAlgorithm>; 
  using FlipListbox = ListBox<FlipWindowAlgorithm>;     
}
```


