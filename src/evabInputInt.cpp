#include "evabInputInt.h"
#include <evabIScreen.h>
namespace evab
{

  InputInt::InputInt(int aValue) : mValue(aValue)
  {
  }

  void InputInt::SetValue(int aValue)
  {
    mValue = aValue;
    Redraw();
  }

  int InputInt::GetValue() const
  {
    return mValue;
  }

  void InputInt::Increment(signed char delta)
  {
    SetValue(mValue + delta);
  }

  void InputInt::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    char buffer[20];
    itoa(mValue, buffer, 10);
    aScreen->TextCenter(aPos, aSize, buffer, aIsFocused);
  }

}
