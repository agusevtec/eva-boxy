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
     * @brief Increments the value by a step
     *
     * @param aSteps Amount to add (positive or negative)
     */
    void Increment(signed char aSteps);

  protected:
    /**
     * @brief Draws the integer value centered on screen
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    int mValue; ///< Current integer value
  };

  class InputIntDiscrete : public InputInt
  {
    unsigned char mCount;
    int mMin;
    int mMax;

  public:
    InputIntDiscrete(int aValue, unsigned char aCount, int aMin, int aMax);
    void Select(unsigned char aIndex);
    signed short Selected() const;
    unsigned char Count() const { return mCount; }
    void Increment(int aSteps);
  };

}
