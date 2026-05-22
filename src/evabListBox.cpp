#include "evabListBox.h"
#include "evabDisplayPlatform.h"

namespace evab
{

  ListBox::ListBox(CompositeBase *aParent, SlidingMethodBase *aSlidingMethod)
      : CompositeBase(aParent), mSlidingMethod(aSlidingMethod)
  {
  }

  ListBox &ListBox::SetItems(ElementBase *aItems[], int aCount)
  {
    mItems = aItems;
    mSlidingMethod->Count = aCount;
    return *this;
  }

  ListBox &ListBox::SetGap(unsigned char aGap)
  {
    mGap = aGap;
    return *this;
  }

  ListBox &ListBox::SetReadOnly(bool aIsReadonly)
  {
    mIsReadOnly = aIsReadonly;
    return *this;
  }

  ListBox &ListBox::SetOnItemModified(eva::IHandler *aOnItemModifyDelegate)
  {
    mOnItemModifyDelegate = aOnItemModifyDelegate;
    return *this;
  }

  ElementBase *ListBox::GetItem(unsigned char aIndex)
  {
    if (aIndex < mSlidingMethod->Count)
      return mItems[aIndex];
    return nullptr;
  }

  bool ListBox::onResidualKey(char aKey)
  {
    if (mIsReadOnly)
      return false;
    if (mSlidingMethod->Count == 0)
      return false;
    int oldSelected = mSlidingMethod->Selected();
    if (aKey == 'u')
    {
      mSlidingMethod->SelectRelative(-1);
      Redraw();
      if (mOnItemModifyDelegate && oldSelected != mSlidingMethod->Selected())
        mOnItemModifyDelegate->invoke(this, {EVENT_SELECTION_CHANGED, mSlidingMethod->Selected()});
      return true;
    }
    if (aKey == 'd')
    {
      mSlidingMethod->SelectRelative(+1);
      Redraw();
      if (mOnItemModifyDelegate && oldSelected != mSlidingMethod->Selected())
        mOnItemModifyDelegate->invoke(this, {EVENT_SELECTION_CHANGED, mSlidingMethod->Selected()});
      return true;
    }
    if (mOnItemModifyDelegate)
    {
      if (aKey == 'l')
      {
        mOnItemModifyDelegate->invoke(this, {EVENT_ITEM_MODIFIED, -1});
        return true;
      }
      if (aKey == 'r')
      {
        mOnItemModifyDelegate->invoke(this, {EVENT_ITEM_MODIFIED, +1});
        return true;
      }
    }
    return false;
  }

  void ListBox::Select(int mIndex)
  {
    if (mSlidingMethod->Count == 0)
      return;
    mSlidingMethod->Select(mIndex);
  }

  int ListBox::Count()
  {
    return mSlidingMethod->Count;
  }

  int ListBox::PageSize()
  {
    return mSlidingMethod->PageSize;
  }

  int ListBox::Selected()
  {
    return mSlidingMethod->Selected();
  }

  void ListBox::drawer(Coor aPos, Coor aSize, unsigned char aSelected)
  {
    if (IsHidden())
    {
      for (int i = 0; i < mSlidingMethod->Count; i++)
        mItems[i]->Draw({0, 0}, {0, 0}, 0);
      return;
    }
    mSlidingMethod->PageSize = aSize.Y / mGap;
    auto p = DisplayPlatform::Instance();
    unsigned char j = 0;
    for (int index = 0; index < mSlidingMethod->Count; index++)
    {
      int i = mSlidingMethod->IndexInWindow(index);
      if (i != -1)
      {
        mItems[index]->Draw({aPos.X, aPos.Y + i * mGap}, {aSize.X, mGap}, (!mIsReadOnly) && aSelected && (mSlidingMethod->Selected() == index));
        j++;
      }
      else
        mItems[index]->Draw({0, 0}, {0, 0}, 0);
    }
    for (int k = mGap * j; k < aSize.Y; k++)
      p->Fill(' ', {aPos.X, aPos.Y + k}, {aSize.X, 1}, 0);
  }

}
