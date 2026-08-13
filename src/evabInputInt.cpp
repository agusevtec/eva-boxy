#include "evabInputInt.h"
#include <evabScreen.h>
namespace evab
{

  InputInt::InputInt(int aValue) : mValue(aValue)
  {
  }

  void InputInt::SetValue(int aValue)
  {
    mValue = aValue;
    redraw();
  }

  int InputInt::GetValue() const
  {
    return mValue;
  }

  void InputInt::Increment(signed char aSteps)
  {
    SetValue(mValue + aSteps);
  }

  void InputInt::drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    char buffer[20];
    itoa(mValue, buffer, 10);
    aScreen->TextCenter(aPos, aSize, buffer, aIsFocused);
  }

  InputIntDiscrete::InputIntDiscrete(int aValue, int aMin, int aMax, unsigned short aStep)
      : mMin(aMin), mMax(max(aMin, aMax)), mStep(aStep)
  {
    InputIntDiscrete::SetValue(aValue);
  }

  void InputIntDiscrete::SetValue(int aValue)
  {
    int k = (aValue - mMin + mStep / 2) / mStep;
    int snappedValue = mMin + k * mStep;
    int maxGridVal = mMin + ((mMax - mMin) / mStep) * mStep;
    InputInt::SetValue(constrain(snappedValue, mMin, maxGridVal));
  }

  unsigned char InputIntDiscrete::Count() const
  {
    if (mStep == 0)
      return 0;
    return (((mMax - mMin) / mStep) + 1);
  }

  void InputIntDiscrete::Select(unsigned char aIndex)
  {
    aIndex = constrain(aIndex, 0, Count() - 1);
    SetValue(mMin + (aIndex)*mStep);
  }

  signed short InputIntDiscrete::Selected() const
  {
    int currentVal = InputInt::GetValue();
    if (currentVal <= mMin)
      return 0;
    return ((currentVal - mMin + mStep / 2) / mStep);
  }

  void InputIntDiscrete::Increment(signed char aSteps)
  {
    SetValue(InputInt::GetValue() + (aSteps * mStep));
  }
}
