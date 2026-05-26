#pragma once

#include <evabSlidingMethods.h>
#include <evabCompositeBase.h>
#include <evaHandler.h>

namespace evab
{

  template <class TSlidingMethod>
  class ListBox : public CompositeBase : public TSlidingMethod
  {
  public:
    enum EventType
    {
      EVENT_ITEM_MODIFIED = 1,
      EVENT_SELECTION_CHANGED = 2
    };

    ListBox<TSlidingMethod>(CompositeBase *aParent)
        : CompositeBase(aParent)
    {
    }
    ListBox<TSlidingMethod> &SetItems(ElementBase *aItems[], int aCount)
    {
      mItems = aItems;
      TSlidingMethod::Count = aCount;
      return *this;
    }
    ListBox<TSlidingMethod> &SetItemHeight(unsigned char aItemHeight)
    {
      mItemHeight = aItemHeight;
      return *this;
    }
    ListBox<TSlidingMethod> &SetReadOnly(bool aIsReadonly)
    {
      mIsReadOnly = aIsReadonly;
      return *this;
    }
    ListBox<TSlidingMethod> &SetOnItemModified(eva::IHandler *aOnItemModifyDelegate)
    {
      mOnItemDelegate = aOnItemModifyDelegate;
      return *this;
    }
    ElementBase *GetItem(unsigned char aIndex)
    {
      if (aIndex < TSlidingMethod::Count)
        return mItems[aIndex];
      return nullptr;
    }
    void Select(int mIndex) override
    {
      if (TSlidingMethod->Count == 0)
        return;
      TSlidingMethod->Select(mIndex);
    }

  private:

    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override
    {
      TSlidingMethod::PageSize = aSize.Y / mItemHeight;
      unsigned char visibleElementsCount = 0;
      for (int i = 0; i < TSlidingMethod::Count; i++)
      {
        int offset = TSlidingMethod::IndexInWindow(i) * mItemHeight;
        if (offset >= 0)
        {
          mItems[i]->Draw({aPos.X, aPos.Y + offset}, {aSize.X, mItemHeight}, (!mIsReadOnly) && aSelected && (TSlidingMethod::Selected() == index));
          visibleElementsCount++;
        }
        else
        {
          mItems[i]->Hide();
        }
      }
      auto p = DisplayPlatform::Instance();
      p->Clear({aPos.X, visibleElementsCount * mItemHeight}, {aSize.Y - visibleElementsCount * mItemHeight, 1});
    }

    void hider() override
    {
      for (int i = 0; i < TSlidingMethod::Count; i++)
        mItems[i]->Hide();
    }

    bool onResidualKey(char aKey) override
    {
      if (mIsReadOnly)
        return false;
      if (TSlidingMethod->Count == 0)
        return false;
      int oldSelected = TSlidingMethod->Selected();
      if (aKey == 'u')
      {
        TSlidingMethod->SelectRelative(-1);
        Redraw();
        if (mOnItemDelegate && oldSelected != TSlidingMethod->Selected())
          mOnItemDelegate->invoke(this, {EVENT_SELECTION_CHANGED, TSlidingMethod->Selected()});
        return true;
      }
      if (aKey == 'd')
      {
        TSlidingMethod->SelectRelative(+1);
        Redraw();
        if (mOnItemDelegate && oldSelected != TSlidingMethod->Selected())
          mOnItemDelegate->invoke(this, {EVENT_SELECTION_CHANGED, TSlidingMethod->Selected()});
        return true;
      }
      if (aKey == 'l')
      {
        if (mOnItemDelegate)
        {
          mOnItemDelegate->invoke(this, {EVENT_ITEM_MODIFIED, -1});
          return true;
        }
      }
      if (aKey == 'r')
      {
        if (mOnItemDelegate)
        {
          mOnItemDelegate->invoke(this, {EVENT_ITEM_MODIFIED, +1});
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
