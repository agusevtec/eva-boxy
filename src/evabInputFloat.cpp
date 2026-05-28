#include "evabInputFloat.h"
#include "evabInputStr.h"
#include <Arduino.h>

namespace evab
{

  extern char stringTemp[20];

  InputFloatField::InputFloatField(const char *aName, float aValue) : mName(aName), mValue(aValue)
  {
  }

  void InputFloatField::IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, float aValue)
  {
    if (abs(aValue) < 1)
      InputStr::IndeedDrawer(aScreen, aPos, aSize, aIsFocused, aName, dtostrf(aValue, aSize.X / 2, 2, stringTemp));
    else
      InputStr::IndeedDrawer(aScreen, aPos, aSize, aIsFocused, aName, dtostrf(aValue, aSize.X / 2, 1, stringTemp));
  }

  void InputFloatField::SetValue(float aValue)
  {
    mValue = aValue;
    Redraw();
  }

  float InputFloatField::GetValue()
  {
    return mValue;
  }

  void InputFloatField::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    InputFloatField::IndeedDrawer(aScreen, aPos, aSize, aIsFocused, mName, mValue);
  }

  InputFloat::InputFloat(const char *aName, float aValue, eva::IHandler *aOnValueChangedDelegate)
      : InputFloatField(aName, aValue), mOnValueChangedDelegate(aOnValueChangedDelegate)
  {
  }

  bool InputFloat::Key(char aKey)
  {
    float delta = 0;
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
      mOnValueChangedDelegate->invoke(this, {EVENT_VALUE_CHANGED_WITH_DELTA, (int)delta});
    }
    return true;
  }

}
