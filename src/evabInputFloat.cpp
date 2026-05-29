#include "evabInputFloat.h"
#include <stdlib.h>

namespace evab
{

  InputFloat::InputFloat(float aValue) : mValue(aValue)
  {
  }

  void InputFloat::SetValue(float aValue)
  {
    mValue = aValue;
    Redraw();
  }

  float InputFloat::GetValue() const
  {
    return mValue;
  }

  void InputFloat::Increment(signed char delta)
  {
    SetValue(mValue + delta);
  }

  void InputFloat::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    char buffer[20];
    if (abs(mValue) < 1)
      dtostrf(mValue, 1, 2, buffer);
    else
      dtostrf(mValue, 1, 1, buffer);
    aScreen->TextCenter(aPos, aSize, buffer, aIsFocused);
  }

}
