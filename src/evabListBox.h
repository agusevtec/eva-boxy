#pragma once

#include <evabSlidingMethods.h>
#include <evabCompositeBase.h>
#include <evaHandler.h>

namespace evab
{
  static const unsigned short EVENT_ITEM_MODIFIED = 1;
  static const unsigned short EVENT_SELECTION_CHANGED = 2;

  template <class TMethod>
  class ListBox : public ElementBase, public TMethod
  {
  public:
    // ListBox<TMethod>(CompositeBase *aParent)
    //     : CompositeBase(aParent)
    // {
    // }
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

    ListBox<TMethod> &SetReadOnly(bool aIsReadonly)
    {
      mIsReadOnly = aIsReadonly;
      Redraw();
      return *this;
    }

    ListBox<TMethod> &SetListener(eva::IHandler *aListener)
    {
      mListener = aListener;
      return *this;
    }

    ElementBase *GetItem(unsigned char aIndex)
    {
      if (aIndex < TMethod::Count())
        return mItems[aIndex];
      return nullptr;
    }

    virtual void Select(signed char aIndex) override
    {
      signed char wasSelected = TMethod::Selected();
      TMethod::Select(aIndex);
      signed char nowSelected = TMethod::Selected();
      if ((wasSelected != nowSelected) && (nowSelected != -1))
      {
        if (mListener)
        {
          eva::CallbackInfo cbInfo = {EVENT_SELECTION_CHANGED, nowSelected};
          mListener->invoke(this, cbInfo);
        }
        Redraw();
      }
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
          mItems[i]->Draw(aScreen, {aPos.X, aPos.Y + offset}, {aSize.X, mItemHeight}, (!mIsReadOnly) && aIsFocused && (i == selected));
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

    bool Key(char aKey) override
    {
      if (mIsReadOnly)
        return false;

      signed char selected = TMethod::Selected();

      if (selected == -1)
        return false;

      if (mItems[selected]->Key(aKey))
        return true;

      if (aKey == 'u' || aKey == 'd')
      {
        Select(selected + (aKey == 'u') ? -1 : +1);
        return true;
      }

      if (aKey == 'l' || aKey == 'r')
      {
        if (mListener)
        {
          eva::CallbackInfo cbInfo = {EVENT_ITEM_MODIFIED, (aKey == 'l') ? -1 : +1};
          mListener->invoke(this, cbInfo);
          return true;
        }
      }
      return false;
    }

  private:
    ElementBase **mItems = nullptr;
    unsigned char mItemHeight = 1;
    bool mIsReadOnly = false;
    eva::IHandler *mListener = nullptr;
  };

}
