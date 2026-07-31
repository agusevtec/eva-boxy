#include "evabCompositeBase.h"

namespace evab
{

  void CompositeBase::focusChild(ElementBase *aChild)
  {
    if (mFocusedChild == aChild)
      return;

    mFocusedChild = aChild;
    redraw();
  }

  bool CompositeBase::OnKey(Keys aKey)
  {
    if (mFocusedChild && mFocusedChild->OnKey(aKey))
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
