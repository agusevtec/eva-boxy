#pragma once

#include "evabSlidingMethods.h"
#include "..\..\src\evabCompositeBase.h"
#include <evaHandler.h>

namespace evab
{

  template <class SLIDING>
  class ListBox : public CompositeBase : public SLIDING
  {
  public:
    enum EventType
    {
      EVENT_ITEM_MODIFIED = 1,
      EVENT_SELECTION_CHANGED = 2
    };

    ListBox<SLIDING>(CompositeBase *aParent)
        : CompositeBase(aParent)
    {
    }
    ListBox<SLIDING> &SetItems(ElementBase *aItems[], int aCount)
    {
      mItems = aItems;
      SLIDING::Count = aCount;
      return *this;
    }
    ListBox<SLIDING> &SetGap(unsigned char aGap)
    {
      mGap = aGap;
      return *this;
    }
    ListBox<SLIDING> &SetReadOnly(bool aIsReadonly)
    {
      mIsReadOnly = aIsReadonly;
      return *this;
    }
    ListBox<SLIDING> &SetOnItemModified(eva::IHandler *aOnItemModifyDelegate)
    {
      mOnItemDelegate = aOnItemModifyDelegate;
      return *this;
    }
    ElementBase *GetItem(unsigned char aIndex)
    {
      if (aIndex < SLIDING::Count)
        return mItems[aIndex];
      return nullptr;
    }
    void Select(int mIndex) override
    {
      if (SLIDING->Count == 0)
        return;
      SLIDING->Select(mIndex);
    }

  private:
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override
    {
      if (IsHidden())
      {
        for (int i = 0; i < SLIDING::Count; i++)
          mItems[i]->Draw({0, 0}, {0, 0}, 0);
        return;
      }
      SLIDING::PageSize = aSize.Y / mGap;
      auto p = DisplayPlatform::Instance();
      unsigned char j = 0;
      for (int index = 0; index < SLIDING::Count; index++)
      {
        int i = SLIDING::IndexInWindow(index);
        if (i != -1)
        {
          mItems[index]->Draw({aPos.X, aPos.Y + i * mGap}, {aSize.X, mGap}, (!mIsReadOnly) && aSelected && (SLIDING::Selected() == index));
          j++;
        }
        else
          mItems[index]->Draw({0, 0}, {0, 0}, 0);
      }
      for (int k = mGap * j; k < aSize.Y; k++)
        p->Fill(' ', {aPos.X, aPos.Y + k}, {aSize.X, 1}, 0);
    }

    bool onResidualKey(char aKey) override
    {
      if (mIsReadOnly)
        return false;
      if (SLIDING->Count == 0)
        return false;
      int oldSelected = SLIDING->Selected();
      if (aKey == 'u')
      {
        SLIDING->SelectRelative(-1);
        Redraw();
        if (mOnItemDelegate && oldSelected != SLIDING->Selected())
          mOnItemDelegate->invoke(this, {EVENT_SELECTION_CHANGED, SLIDING->Selected()});
        return true;
      }
      if (aKey == 'd')
      {
        SLIDING->SelectRelative(+1);
        Redraw();
        if (mOnItemDelegate && oldSelected != SLIDING->Selected())
          mOnItemDelegate->invoke(this, {EVENT_SELECTION_CHANGED, SLIDING->Selected()});
        return true;
      }
      if (mOnItemDelegate)
      {
        if (aKey == 'l')
        {
          mOnItemDelegate->invoke(this, {EVENT_ITEM_MODIFIED, -1});
          return true;
        }
        if (aKey == 'r')
        {
          mOnItemDelegate->invoke(this, {EVENT_ITEM_MODIFIED, +1});
          return true;
        }
      }
      return false;
    }

  private:
    ElementBase **mItems = nullptr;
    unsigned char mGap = 1;
    bool mIsReadOnly = false;
    eva::IHandler *mOnItemDelegate = nullptr;
  };

}
