// evabLayoutPane.cpp
#include "evabLayoutBase.h"

#include <Arduino.h>

using namespace evab;

void LayoutBase::focusChild(IFocusChain *aChild)
{
  if (mFocusedChild == aChild)
    return;

  mFocusedChild = aChild;
  Redraw();
}

ElementBase *LayoutBase::GetFocused() const
{
  return mFocusedChild->AsElementBase();
}

bool LayoutBase::IsFocused(IFocusChain *aChild)
{
  return aChild == mFocusedChild;
}

void LayoutBase::focusNext()
{
  if (!mFocusedChild)
    return;

  focusChild(mFocusedChild->Next());
}

void LayoutBase::focusPrev()
{
  if (!mFocusedChild)
    return;

  IFocusChain *prev = mFocusedChild;
  while (prev->Next() != mFocusedChild)
    prev = prev->Next();

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

bool LayoutBase::Key(Keys aKey)
{
  // Forward to focused child first
  if (mFocusedChild && mFocusedChild->AsElementBase()->Key(aKey))
    return true;

  // If not handled, try residual
  return onResidualKey(aKey);
}

bool LayoutBase::onResidualKey(Keys)
{
  return false;
}

void LayoutBase::hider()
{
  if (!mFocusedChild)
    return;

  IFocusChain *current = mFocusedChild;
  do
  {
    current->AsElementBase()->Hide();
    current = current->Next();
  } while (current != mFocusedChild);
}
