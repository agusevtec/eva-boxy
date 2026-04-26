#include "evabSlidingMethods.h"
#include <Arduino.h>

namespace evab
{

  SlidingMethodBase::SlidingMethodBase() : mIndex(0), mSlidingWindow(0), PageSize(0), Count(0)
  {
  }

  signed char SlidingMethodBase::IndexInWindow(signed char aPosition)
  {
    int candidate = aPosition - mSlidingWindow;
    if (0 <= candidate && candidate < PageSize)
      return candidate;
    return -1;
  }

  signed char SlidingMethodBase::Selected()
  {
    if (Count == 0)
      return -1;
    return mIndex;
  }

  void SlidingMethodBase::SelectRelative(signed char aShift)
  {
    Select(mIndex + aShift);
  }

  void FlipSlidingMethod::Select(signed char aIndex)
  {
    if (Count == 0 || PageSize == 0)
      return;
    mIndex = ((aIndex % Count) + Count) % Count;
    mSlidingWindow = (mIndex / PageSize) * PageSize;
  }

  void ScrollSlidingMethod::Select(signed char aIndex)
  {
    if (Count == 0 || PageSize == 0)
      return;
    aIndex = ((aIndex % Count) + Count) % Count;
    mIndex = constrain(aIndex, 0, Count - 1);
    int visualIndex = aIndex - mSlidingWindow;
    if (visualIndex <= 0)
      mSlidingWindow = max(0, aIndex - 1);
    if (visualIndex >= PageSize - 1)
      mSlidingWindow = min(max(0, Count - PageSize), aIndex - PageSize + 2);
  }

}
