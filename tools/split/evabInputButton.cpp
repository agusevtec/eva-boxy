#include <evabInputButton.h>

namespace evab
{

  /**
   * @brief Constructor for InputButton
   * 
   * @param aName Flash string for button label
   */
  InputButton::InputButton(const __FlashStringHelper *aName) : mName(aName)
  {
  }

  /**
   * @brief Draws the button element
   * 
   * @param aScreen Screen to draw on
   * @param aPos Position on screen
   * @param aSize Size of the element
   * @param aIsFocused Focus state (1 = focused, 0 = not focused)
   */
  void InputButton::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    aScreen->DrawSymbol(aPos, {1, 1}, '(', aIsFocused);
    aScreen->TextCenter({aPos.X + 1, aPos.Y}, {aSize.X - 2, 1}, mName, aIsFocused);
    aScreen->DrawSymbol({aPos.X + aSize.X - 1, aPos.Y}, {1, 1}, ')', aIsFocused);
    for (int i = 1; i < aSize.Y; i++)
      aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
  }

}
