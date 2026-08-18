#include "evabInputFloat.h"
#include <evabScreen.h>
#include <stdlib.h>

using namespace evab;

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

// --- InputFloatDiscrete Implementation ---

InputFloatDiscrete::InputFloatDiscrete(float aValue, float aMin, float aMax, float aStep)
    : mMin(aMin), mMax(max(aMin, aMax)), mStep(aStep > 0.0f ? aStep : 0.1f)
{
  InputFloatDiscrete::SetValue(aValue);
}

void InputFloatDiscrete::SetValue(float aValue)
{
  float clamped = constrain(aValue, mMin, mMax);

  int k = (int)((clamped - mMin + (mStep / 2.0f)) / mStep);
  float snappedValue = mMin + (float)k * mStep;

  int maxSteps = (int)((mMax - mMin) / mStep);
  float maxGridVal = mMin + (float)maxSteps * mStep;

  InputFloat::SetValue(constrain(snappedValue, mMin, maxGridVal));
}

unsigned short InputFloatDiscrete::Count() const
{
  if (mStep <= 0.0f || mMax < mMin)
    return 0;

  int count = (int)((mMax - mMin) / mStep) + 1;
  return constrain(count, 0, 65535);
}

void InputFloatDiscrete::Select(unsigned short aIndex)
{
  unsigned short total = Count();
  if (total == 0)
    return;

  aIndex = constrain(aIndex, (unsigned short)0, (unsigned short)(total - 1));
  SetValue(mMin + ((float)aIndex * mStep));
}

signed short InputFloatDiscrete::Selected() const
{
  float currentVal = InputFloat::GetValue();
  if (currentVal <= mMin)
    return 0;

  return (currentVal - mMin + (mStep / 2.0f)) / mStep;
}

void InputFloatDiscrete::Increment(signed char aSteps)
{
  SetValue(InputFloat::GetValue() + ((float)aSteps * mStep));
}
