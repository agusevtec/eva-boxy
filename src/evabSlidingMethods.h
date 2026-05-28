#pragma once

namespace evab
{

  class SlidingMethodBase
  {
  public:
    SlidingMethodBase();
    virtual void Select(signed char aIndex) = 0;
    signed char Selected();
    signed char Count();
    signed char WindowSize();

  protected:
    signed char indexInWindow(signed char aPosition);
    void setCount(signed char Count);
    void resizeWindow(signed char aWindowSize);

  protected:
    signed char mSelected;
    signed char mCount;
    signed char mWindowStart;
    signed char mWindowSize;
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
