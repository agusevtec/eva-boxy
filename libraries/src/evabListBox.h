#pragma once

#include "evabSlidingMethods.h"
#include "evabBaseComposite.h"
#include <evaHandler.h>

namespace evab
{

  class ListBox : public BaseComposite
  {
  public:
    enum EventType
    {
      EVENT_ITEM_MODIFIED = 1,
      EVENT_SELECTION_CHANGED = 2
    };
    ListBox(BaseComposite *aParent, SlidingMethodBase *aSlidingMethod);
    virtual ~ListBox() = default;
    ListBox &SetItems(BaseField *aItems[], int aCount);
    ListBox &SetGap(unsigned char aGap);
    ListBox &SetReadOnly(bool aIsReadonly);
    ListBox &SetOnItemModified(eva::IHandler *aOnItemModifyDelegate);
    BaseField *GetItem(unsigned char aIndex);
    void Select(int mIndex);
    int Selected();
    int Count();
    int PageSize();

  private:
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;
    bool onKey(char aKey) override;

  private:
    BaseField **mItems = nullptr;
    SlidingMethodBase *mSlidingMethod;
    eva::IHandler *mOnItemModifyDelegate = nullptr;
    unsigned char mGap = 1;
    bool mIsReadOnly = false;
  };

}
