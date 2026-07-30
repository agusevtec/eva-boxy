// evabInputFloat.h
#pragma once

#include "evabElementBase.h"

namespace evab
{

  /**
   * @brief Float input element
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
     * @brief Increments the value by a step
     *
     * @param aSteps Amount to add (positive or negative)
     */
    void Increment(signed char aSteps);

  protected:
    /**
     * @brief Draws the float value centered on screen
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    float mValue; ///< Current float value
  };

  /**
   * @brief Discrete float input element
   *
   * Adds index-based control to InputFloat.
   */
  class InputFloatDiscrete : public InputFloat
  {
    unsigned char mCount;
    float mMin;
    float mMax;

  public:
    InputFloatDiscrete(float aValue, unsigned char aCount, float aMin, float aMax);
    void Select(unsigned char aIndex);
    signed short Selected() const;
    unsigned char Count() const { return mCount; }
    void Increment(int aSteps);
  };

}