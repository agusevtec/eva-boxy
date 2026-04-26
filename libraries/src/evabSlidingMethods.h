#pragma once

namespace evab
{

  class SlidingMethodBase
  {
  public:
    SlidingMethodBase();
    virtual ~SlidingMethodBase() = default;
    virtual void Select(signed char aIndex) = 0;
    signed char Selected();
    signed char IndexInWindow(signed char aPosition);
    void SelectRelative(signed char aShift);

  protected:
    signed char mSlidingWindow;
    signed char mIndex;

  public:
    signed char Count;
    signed char PageSize;
  };

  class FlipSlidingMethod : public SlidingMethodBase
  {
  public:
    void Select(signed char aIndex) override;
  };

  class ScrollSlidingMethod : public SlidingMethodBase
  {
  public:
    void Select(signed char aIndex) override;
  };

}
