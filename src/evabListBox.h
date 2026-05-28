#pragma once

#include <evabSlidingMethods.h>
#include <evabCompositeBase.h>
#include <evaHandler.h>

namespace evab
{
  static const unsigned short EVENT_ITEM_MODIFIED = 1;
  static const unsigned short EVENT_SELECTION_CHANGED = 2;

  template <class TMethod>
  class ListBox : public CompositeBase, public TMethod
  {
  public:
    ListBox<TMethod>(CompositeBase *aParent)
        : CompositeBase(aParent)
    {
    }
    ListBox<TMethod> &SetItems(ElementBase *aItems[], int aCount)
    {
      mItems = aItems;
      TMethod::Count = aCount;
      return *this;
    }
    ListBox<TMethod> &SetItemHeight(unsigned char aItemHeight)
    {
      mItemHeight = aItemHeight;
      return *this;
    }
    ListBox<TMethod> &SetReadOnly(bool aIsReadonly)
    {
      mIsReadOnly = aIsReadonly;
      return *this;
    }
    ListBox<TMethod> &SetOnItemModified(eva::IHandler *aOnItemModifyDelegate)
    {
      mOnItemDelegate = aOnItemModifyDelegate;
      return *this;
    }
    ElementBase *GetItem(unsigned char aIndex)
    {
      if (aIndex < TMethod::Count)
        return mItems[aIndex];
      return nullptr;
    }
    void Select(signed char mIndex) override
    {
      if (this->Count == 0)
        return;
      TMethod::Select(mIndex);
    }

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      TMethod::PageSize = aSize.Y / mItemHeight;
      unsigned char visibleElementsCount = 0;
      for (int i = 0; i < TMethod::Count; i++)
      {
        int offset = TMethod::IndexInWindow(i) * mItemHeight;
        if (offset >= 0)
        {
          mItems[i]->Draw(aScreen, {aPos.X, aPos.Y + offset}, {aSize.X, mItemHeight}, (!mIsReadOnly) && aIsFocused && (TMethod::Selected() == i));
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
      for (int i = 0; i < TMethod::Count; i++)
        mItems[i]->Hide();
    }

    bool onResidualKey(char aKey) override
    {
      if (mIsReadOnly)
        return false;
      if (TMethod::Count == 0)
        return false;
      int oldSelected = TMethod::Selected();
      if (aKey == 'u')
      {
        TMethod::SelectRelative(-1);
        Redraw();
        if (mOnItemDelegate && oldSelected != TMethod::Selected())
        {
          eva::CallbackInfo cbInfo = {EVENT_SELECTION_CHANGED, TMethod::Selected()};
          mOnItemDelegate->invoke((void *)this, cbInfo);
        }
        return true;
      }
      if (aKey == 'd')
      {
        TMethod::SelectRelative(+1);
        Redraw();
        if (mOnItemDelegate && oldSelected != TMethod::Selected())
        {
          eva::CallbackInfo cbInfo = {EVENT_SELECTION_CHANGED, TMethod::Selected()};
          mOnItemDelegate->invoke((void *)this, cbInfo);
        }
        return true;
      }
      if (aKey == 'l')
      {
        if (mOnItemDelegate)
        {
          eva::CallbackInfo cbInfo = {EVENT_ITEM_MODIFIED, -1};
          mOnItemDelegate->invoke((void *)this, cbInfo);
          return true;
        }
      }
      if (aKey == 'r')
      {
        if (mOnItemDelegate)
        {
          eva::CallbackInfo cbInfo = {EVENT_ITEM_MODIFIED, +1};
          mOnItemDelegate->invoke((void *)this, cbInfo);
          return true;
        }
      }
      return false;
    }

  private:
    ElementBase **mItems = nullptr;
    unsigned char mItemHeight = 1;
    bool mIsReadOnly = false;
    eva::IHandler *mOnItemDelegate = nullptr;
  };

}
