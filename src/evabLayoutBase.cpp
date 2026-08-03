// evabLayoutPane.cpp
#include "evabLayoutBase.h"

#include <Arduino.h>

using namespace evab;

void LayoutBase::focusChild(FocusChainBase *aChild)
{
  if (mFocusedChild == aChild)
    return;

  mFocusedChild = aChild;
  redraw();
}

ElementBase *LayoutBase::GetFocused() const
{
  if (!mFocusedChild)
    return nullptr;
  return mFocusedChild->element;
}

bool LayoutBase::IsFocused(FocusChainBase *aChild)
{
  return aChild == mFocusedChild;
}

void LayoutBase::focusNext()
{
  if (!mFocusedChild)
    return;

  focusChild(mFocusedChild->next);
}

void LayoutBase::focusPrev()
{
  if (!mFocusedChild)
    return;

  FocusChainBase *prev = mFocusedChild;
  while (prev->next != mFocusedChild)
    prev = prev->next;

  focusChild(prev);
}

void LayoutBase::Increment(signed char delta)
{
  if (delta > 0)
  {
    focusNext();
  }
  else if (delta < 0)
  {
    focusPrev();
  }
}

bool LayoutBase::OnKey(Keys aKey)
{
  if (mFocusedChild && mFocusedChild->element->OnKey(aKey))
    return true;

  return onResidualKey(aKey);
}

bool LayoutBase::onResidualKey(Keys)
{
  return false;
}

void LayoutBase::freezer()
{
  if (!mFocusedChild)
    return;

  FocusChainBase *current = mFocusedChild;
  do
  {
    current->element->Freeze();
    current = current->next;
  } while (current != mFocusedChild);
}
