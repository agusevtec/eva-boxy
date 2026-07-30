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
    Redraw();
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

  InputIntDiscrete::InputIntDiscrete(int aValue, unsigned char aCount, int aMin, int aMax)
      : InputInt(aValue), mCount(aCount), mMin(aMin), mMax(aMax)
  {
  }

  void InputIntDiscrete::Select(unsigned char aIndex)
  {
    aIndex = constrain(aIndex, 0, mCount - 1);
    int step = (mMax - mMin) / (mCount - 1);
    InputInt::SetValue(mMin + aIndex * step);
  }

  signed short InputIntDiscrete::Selected() const
  {
    int value = InputInt::GetValue();
    int step = (mMax - mMin) / (mCount - 1);
    int index = round((value - mMin) / step);
    return constrain(index, 0, mCount - 1);
  }

  void InputIntDiscrete::Increment(int aSteps)
  {
    Select(Selected() + aSteps);
  }

}
