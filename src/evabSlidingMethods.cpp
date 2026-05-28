#include "evabSlidingMethods.h"
#include <Arduino.h>

namespace evab
{

  SlidingMethodBase::SlidingMethodBase()
      : mSelected(0), mWindowStart(0), mWindowSize(0), mCount(0)
  {
  }

  signed char SlidingMethodBase::indexInWindow(signed char aPosition)
  {
    int candidate = aPosition - mWindowStart;
    if (0 <= candidate && candidate < mWindowSize)
      return candidate;
    return -1;
  }

  signed char SlidingMethodBase::Selected()
  {
    if (mCount == 0)
      return -1;
    return mSelected;
  }

  void SlidingMethodBase::setCount(signed char Count)
  {
      mCount = Count;
    if (mCount)
      mSelected = 0;
  }
  void SlidingMethodBase::resizeWindow(signed char aWindowSize)
  {
    mWindowSize = aWindowSize;
  }

  signed char SlidingMethodBase::Count()
  {
    return mCount;
  }

  signed char SlidingMethodBase::WindowSize()
  {
    return mWindowSize;
  }

  void FlipSlidingMethod::Select(signed char aIndex)
  {
    if (mCount == 0 || mWindowSize == 0)
      return;
    mSelected = ((aIndex % mCount) + mCount) % mCount;
    mWindowStart = (mSelected / mWindowSize) * mWindowSize;
  }

  void ScrollSlidingMethod::Select(signed char aIndex)
  {
    if (mCount == 0 || mWindowSize == 0)
      return;
    aIndex = ((aIndex % mCount) + mCount) % mCount;
    mSelected = constrain(aIndex, 0, mCount - 1);
    int visualIndex = aIndex - mWindowStart;
    if (visualIndex <= 0)
      mWindowStart = max(0, aIndex - 1);
    if (visualIndex >= mWindowSize - 1)
      mWindowStart = min(max(0, mCount - mWindowSize), aIndex - mWindowSize + 2);
  }

}
