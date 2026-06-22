#include <evabInputButton.h>

namespace evab
{

  InputButton::InputButton(const __FlashStringHelper *aName) : mName(aName)
  {
  }

  void InputButton::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    aScreen->TextCenter(aPos, {aSize.X, 1}, mName, aIsFocused);
    for (int i = 1; i < aSize.Y; i++)
      aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
  }

}
