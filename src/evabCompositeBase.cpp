#include "evabCompositeBase.h"

namespace evab
{

  void CompositeBase::focusChild(ElementBase *aChild)
  {
    mFocusedChild = aChild;
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
