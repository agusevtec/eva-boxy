// evabInputFloat.cpp
#include "evabInputFloat.h"
#include <evabScreen.h>
#include <stdlib.h>

namespace evab
{

  InputFloat::InputFloat(float aValue) : mValue(aValue)
  {
  }

  void InputFloat::SetValue(float aValue)
  {
    mValue = aValue;
    redraw();
  }

  float InputFloat::GetValue() const
  {
    return mValue;
  }

  void InputFloat::Increment(signed char aSteps)
  {
    SetValue(mValue + aSteps);
  }

  void InputFloat::drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    char buffer[20];
    if (abs(mValue) < 1)
      dtostrf(mValue, 1, 2, buffer);
    else
      dtostrf(mValue, 1, 1, buffer);
    aScreen->TextCenter(aPos, aSize, buffer, aIsFocused);
  }

  // ========== DiscreteFloat ==========

  InputFloatDiscrete::InputFloatDiscrete(float aValue, unsigned char aCount, float aMin, float aMax)
      : InputFloat(aValue), mCount(aCount), mMin(aMin), mMax(aMax)
  {
  }

  void InputFloatDiscrete::Select(unsigned char aIndex)
  {
    aIndex = constrain(aIndex, 0, mCount - 1);
    float step = (mMax - mMin) / (mCount - 1);
    InputFloat::SetValue(mMin + aIndex * step);
  }

  signed short InputFloatDiscrete::Selected() const
  {
    float value = InputFloat::GetValue();
    float step = (mMax - mMin) / (mCount - 1);
    int index = round((value - mMin) / step);
    return constrain(index, 0, mCount - 1);
  }

  void InputFloatDiscrete::Increment(signed char aSteps)
  {
    Select(Selected() + aSteps);
  }

}