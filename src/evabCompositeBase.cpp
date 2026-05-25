#include "evabCompositeBase.h"

namespace evab
{

  void CompositeBase::focusChild(ElementBase *aChild)
  {
    mFocusedChild = aChild;
  }

  CompositeBase::CompositeBase(CompositeBase *aParent) : mParent(aParent)
  {
  }

  bool CompositeBase::IsFocused(ElementBase *aChild)
  {
    if (!IsFocused())
      return false;
    return mFocusedChild == aChild;
  }

  bool CompositeBase::IsFocused()
  {
    if (!mParent)
      return true;
    return mParent->IsFocused(this);
  }

  bool CompositeBase::Key(char aKey)
  {
    if (mFocusedChild && mFocusedChild->Key(aKey))
      return true;
    return onResidualKey(aKey);
  }


  bool CompositeBase::onResidualKey(char aKey)
  {
    return false;
  }

}
