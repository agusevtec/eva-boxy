#pragma once

#include <evabElementBase.h>

namespace evab
{

  /**
   * @brief Button input element
   * 
   * Displays a button with a label enclosed in parentheses.
   * The Increment method is a placeholder that does nothing.
   */
  class InputButton : public ElementBase
  {
  public:
    /**
     * @brief Constructor for InputButton
     * 
     * @param aName Flash string for button label
     */
    InputButton(const __FlashStringHelper *aName);
    
    /**
     * @brief Placeholder increment method (does nothing)
     * 
     * @param delta Unused parameter
     */
    void Increment(signed char delta);  // Placeholder, does nothing

  protected:
    /**
     * @brief Draws the button element
     * 
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const __FlashStringHelper * mName;  ///< Button label
  };

}
