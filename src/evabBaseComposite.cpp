#include "evabBaseComposite.h"

namespace evab
{

  void BaseComposite::focusChild(BaseElement *aChild)
  {
    mFocusedChild = aChild;
  }

  BaseComposite::BaseComposite(BaseComposite *aParent) : mParent(aParent)
  {
  }

  bool BaseComposite::IsFocused(BaseElement *aChild)
  {
    if (!IsFocused())
      return false;
    return mFocusedChild == aChild;
  }

  bool BaseComposite::IsFocused()
  {
    if (!mParent)
      return true;
    return mParent->IsFocused(this);
  }

  bool BaseComposite::Key(char aKey)
  {
    if (mFocusedChild && mFocusedChild->Key(aKey))
      return true;
    return onKey(aKey);
  }

  bool BaseComposite::onKey(char aKey)
  {
    return false;
  }

}
