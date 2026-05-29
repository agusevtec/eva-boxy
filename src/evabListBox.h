#pragma once

#include <evabSlidingMethods.h>
#include <evabElementBase.h>

namespace evab
{
  template <class TMethod>
  class ListBox : public ElementBase, public TMethod
  {
  private:
    ElementBase **mItems = nullptr;
    unsigned char mItemHeight = 1;

  public:
    ListBox<TMethod> &SetItems(ElementBase *aItems[], int aCount)
    {
      mItems = aItems;
      TMethod::setCount(aCount);
      if (aCount)
        Select(0);
      Redraw();
      return *this;
    }

    ListBox<TMethod> &SetItemHeight(unsigned char aItemHeight)
    {
      mItemHeight = aItemHeight;
      Redraw();
      return *this;
    }

    ElementBase *GetItem(unsigned char aIndex)
    {
      if (aIndex < TMethod::Count())
        return mItems[aIndex];
      return nullptr;
    }

    void Increment(signed char delta)
    {
      Select(Selected() + delta);
      Redraw();
    }

    bool Key(char aKey) override
    {
      signed char selected = TMethod::Selected();
      if (selected == -1)
        return false;

      if (mItems[selected]->Key(aKey))
        return true;

      return false;
    }

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      TMethod::resizeWindow(aSize.Y / mItemHeight);
      unsigned char visibleElementsCount = 0;
      signed char selected = TMethod::Selected();
      for (int i = 0; i < TMethod::Count(); i++)
      {
        int offset = TMethod::indexInWindow(i) * mItemHeight;
        if (offset >= 0)
        {
          mItems[i]->Draw(aScreen, {aPos.X, aPos.Y + offset}, {aSize.X, mItemHeight}, aIsFocused && (i == selected));
          visibleElementsCount++;
        }
        else
        {
          mItems[i]->Hide();
        }
      }
      aScreen->Clear({aPos.X, visibleElementsCount * mItemHeight}, {aSize.Y - visibleElementsCount * mItemHeight, 1});
    }

    void hider() override
    {
      for (int i = 0; i < TMethod::Count(); i++)
        mItems[i]->Hide();
    }
  };
}
