// evabLayoutPane.cpp
#include "evabLayoutBase.h"

#include <Arduino.h>

using namespace evab;

LayoutBase::LayoutBase()
    : mCurrentChild(nullptr)
{
}

void LayoutBase::setCurrentChild(IFocusChain *aChild)
{
  Serial.print("Before: ");
  Serial.print((int)mCurrentChild);
  Serial.print(" ");
  Serial.println((int)aChild);
  mCurrentChild = aChild;
  Serial.print("After: ");
  Serial.println((int)mCurrentChild);
  Redraw();
}

IFocusChain *LayoutBase::getCurrentChild() const
{
  return mCurrentChild;
}

bool LayoutBase::IsFocused(IFocusChain *aChild)
{
  return aChild == mCurrentChild;
}

void LayoutBase::focusNext()
{
  if (!mCurrentChild)
    return;

  // Cast to FocusChain to access next() pointer
  IFocusChain *current = mCurrentChild;
  IFocusChain *next = current->next();

  if (next && next != mCurrentChild)
  {
    setCurrentChild(next);
  }
}

void LayoutBase::focusPrev()
{
  if (!mCurrentChild)
    return;

  // Find previous: walk from current until we find one whose next == current
  IFocusChain *current = mCurrentChild;
  IFocusChain *prev = current;

  // Walk through the chain to find previous
  while (prev->next() != current)
  {
    prev = prev->next();
  }

  if (prev && prev != current)
  {
    setCurrentChild(prev);
  }
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
  if (mCurrentChild && mCurrentChild->asElementBase()->Key(aKey))
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
  if (!mCurrentChild)
    return;

  // Walk through chain and hide all children
  IFocusChain *current = mCurrentChild;
  do
  {
    ElementBase *elem = current->asElementBase();
    if (elem)
    {
      elem->Hide();
    }
    current = current->next();
  } while (current != mCurrentChild);
}
