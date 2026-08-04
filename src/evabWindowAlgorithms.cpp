#include <evabWindowAlgorithms.h>
#include <Arduino.h>

namespace evab
{

  WindowAlgorithmBase::WindowAlgorithmBase(unsigned char aCount)
      : mSelected(0), mWindowStart(0), mWindowSize(0), mCount(aCount)
  {
  }

  signed char WindowAlgorithmBase::indexInWindow(unsigned char aPosition)
  {
    int candidate = aPosition - mWindowStart;
    if (0 <= candidate && candidate < mWindowSize)
      return candidate;
    return -1;
  }

  signed short WindowAlgorithmBase::Selected()
  {
    if (mCount == 0)
      return -1;
    return mSelected;
  }

  void WindowAlgorithmBase::setCount(unsigned char aCount)
  {
    mCount = aCount;
  }
  void WindowAlgorithmBase::setWindowSize(unsigned char aWindowSize)
  {
    mWindowSize = aWindowSize;
  }

  unsigned char WindowAlgorithmBase::Count()
  {
    return mCount;
  }

  unsigned char WindowAlgorithmBase::WindowSize()
  {
    return mWindowSize;
  }

  void FlipWindowAlgorithm::Select(unsigned char aIndex)
  {
    if (mCount == 0 || mWindowSize == 0)
      return;
    mSelected = ((aIndex % mCount) + mCount) % mCount;
    mWindowStart = (mSelected / mWindowSize) * mWindowSize;
  }

  void ScrollWindowAlgorithm::Select(unsigned char aIndex)
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
