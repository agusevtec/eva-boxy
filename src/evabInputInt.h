#pragma once

#include "evabElementBase.h"

namespace evab
{

  /**
   * @brief Integer input element
   *
   * Displays and manages an integer value.
   */
  class InputInt : public ElementBase
  {
  public:
    /**
     * @brief Constructor for InputInt
     *
     * @param aValue Initial integer value (default 0)
     */
    InputInt(int aValue = 0);

    /**
     * @brief Sets the integer value and redraws
     *
     * @param aValue New integer value
     */
    void SetValue(int aValue);

    /**
     * @brief Gets the current integer value
     *
     * @return Current integer value
     */
    int GetValue() const;

    /**
     * @brief Increments the value by a delta
     *
     * @param delta Amount to add (positive or negative)
     */
    void Increment(signed char delta);

  protected:
    /**
     * @brief Draws the integer value centered on screen
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    int mValue; ///< Current integer value
  };

}
