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
   * Adds step-grid bound control to InputFloat.
   */
  class InputFloatDiscrete : public InputFloat
  {
  public:
    /**
     * @brief Constructs a discrete float input.
     *
     * @param aValue Initial value.
     * @param aMin   Minimum value / start of the step grid.
     * @param aMax   Maximum boundary limit.
     * @param aStep  Grid step size (must be > 0.0f).
     */
    InputFloatDiscrete(float aValue, float aMin, float aMax, float aStep = 0.1f);

    /**
     * @brief Selects a step by index (0 to Count()-1).
     */
    void Select(unsigned short aIndex);

    /**
     * @brief Sets the float value snapped to grid and redraws
     *
     * @param aValue New float value
     */
    void SetValue(float aValue);

    /**
     * @brief Returns the currently selected index.
     */
    signed short Selected() const;

    /**
     * @brief Returns the total number of steps.
     */
    unsigned short Count() const;

    /**
     * @brief Increments value by discrete grid steps
     *
     * @param aSteps Amount of steps to increment (positive or negative)
     */
    void Increment(signed char aSteps);

  private:
    float mMin;
    float mMax;
    float mStep;
  };
}