

# File SlidingMethods.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**SlidingMethods.h**](_sliding_methods_8h.md)

[Go to the documentation of this file](_sliding_methods_8h.md)


```C++
#ifndef SLIDINGMETHODS_H
#define SLIDINGMETHODS_H

#pragma once
class SlidingMethodBase
{
public:
  SlidingMethodBase();
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

#endif
```


