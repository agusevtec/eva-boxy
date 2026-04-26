#include "evabInputInt.h"
#include "evabInputStr.h"
#include <Arduino.h>

namespace evab
{

  extern char stringTemp[20];

  void InputIntField::IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, const char *aName, int aValue)
  {
    InputStr::IndeedDrawer(aPos, aSize, aSelected, aName, itoa(aValue, stringTemp, 10));
  }

  InputIntField::InputIntField(const char *aName, int aValue) : mName(aName), mValue(aValue)
  {
  }

  void InputIntField::SetValue(int aValue)
  {
    mValue = aValue;
    updateView();
  }

  int InputIntField::GetValue()
  {
    return mValue;
  }

  void InputIntField::drawer(Coor aPos, Coor aSize, unsigned char aSelected)
  {
    if (IsHidden())
      return;
    InputIntField::IndeedDrawer(aPos, aSize, aSelected, mName, mValue);
  }

  InputInt::InputInt(const char *aName, int aValue, eva::IHandler *aOnValueChangedDelegate)
      : InputIntField(aName, aValue), mOnValueChangedDelegate(aOnValueChangedDelegate)
  {
  }

  bool InputInt::Key(char aKey)
  {
    int delta = 0;
    if (aKey == 'l')
    {
      SetValue(GetValue() - 1);
      delta = -1;
    }
    else if (aKey == 'r')
    {
      SetValue(GetValue() + 1);
      delta = +1;
    }
    else
      return false;
    if (mOnValueChangedDelegate)
    {
      mOnValueChangedDelegate->invoke(this, {EVENT_VALUE_CHANGED, (int)GetValue()});
      mOnValueChangedDelegate->invoke(this, {EVENT_VALUE_CHANGED_WITH_DELTA, delta});
    }
    return true;
  }

}
