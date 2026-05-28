#include "evabInputInt.h"
#include "evabInputStr.h"
#include <Arduino.h>

namespace evab
{

  void InputIntField::IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, int aValue)
  {
    char stringTemp[20];
    InputStr::IndeedDrawer(aScreen, aPos, aSize, aIsFocused, aName, itoa(aValue, stringTemp, 10));
  }

  InputIntField::InputIntField(const char *aName, int aValue) : mName(aName), mValue(aValue)
  {
  }

  void InputIntField::SetValue(int aValue)
  {
    mValue = aValue;
    Redraw();
  }

  int InputIntField::GetValue()
  {
    return mValue;
  }

  void InputIntField::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    InputIntField::IndeedDrawer(aScreen, aPos, aSize, aIsFocused, mName, mValue);
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
