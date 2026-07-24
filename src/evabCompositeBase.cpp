#include "evabCompositeBase.h"

namespace evab
{

  void CompositeBase::focusChild(ElementBase *aChild)
  {
    mFocusedChild = aChild;
  }

  bool CompositeBase::Key(Keys aKey)
  {
    if (mFocusedChild && mFocusedChild->Key(aKey))
      return true;
    return onResidualKey(aKey);
  }


  bool CompositeBase::onResidualKey(Keys)
  {
    return false;
  }

  bool CompositeBase::IsFocused(ElementBase *aChild)
  {
      return aChild == mFocusedChild;
  }
  
  ElementBase *CompositeBase::GetFocused() const
  {
      return mFocusedChild;
  }
}
