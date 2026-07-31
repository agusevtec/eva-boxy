// evabLayoutPane.cpp
#include "evabLayoutBase.h"

#include <Arduino.h>

using namespace evab;

void LayoutBase::focusChild(IFocusChain *aChild)
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

bool LayoutBase::OnKey(Keys aKey)
{
  if (mFocusedChild && mFocusedChild->AsElementBase()->OnKey(aKey))
    return true;

  return onResidualKey(aKey);
}

bool LayoutBase::onResidualKey(Keys)
{
  return false;
}

void LayoutBase::muter()
{
  if (!mFocusedChild)
    return;

  IFocusChain *current = mFocusedChild;
  do
  {
    current->AsElementBase()->Mute();
    current = current->Next();
  } while (current != mFocusedChild);
}
