#pragma once

#include <evabElementBase.h>

namespace evab
{

  /**
   * @brief Floating-point input element
   * 
   * Displays and manages a floating-point value.
   */
  class InputFloat : public ElementBase
  {
  public:
    /**
     * @brief Constructor for InputFloat
     * 
     * @param aValue Initial float value (default 0)
     */
    InputFloat(float aValue = 0);
    
    /**
     * @brief Sets the float value and redraws
     * 
     * @param aValue New float value
     */
    void SetValue(float aValue);
    
    /**
     * @brief Gets the current float value
     * 
     * @return Current float value
     */
    float GetValue() const;
    
    /**
     * @brief Increments the value by a delta
     * 
     * @param delta Amount to add (positive or negative)
     */
    void Increment(signed char delta);

  protected:
    /**
     * @brief Draws the float value centered on screen
     * 
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    float mValue;  ///< Current float value

  };

}
