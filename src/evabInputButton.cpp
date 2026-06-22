#include <evabInputButton.h>

namespace evab
{

  InputButton::InputButton(const __FlashStringHelper *aName) : mName(aName)
  {
  }

  void InputButton::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    aScreen->DrawSymbol(aPos, {1, 1}, '(', aIsFocused);
    aScreen->TextCenter({aPos.X + 1, aPos.Y}, {aSize.X - 2, 1}, mName, aIsFocused);
    aScreen->DrawSymbol({aPos.X + aSize.X - 1, aPos.Y}, {1, 1}, ')', aIsFocused);
    for (int i = 1; i < aSize.Y; i++)
      aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
  }

}
