

# File evabWindowAlgorithms.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabWindowAlgorithms.h**](evab_window_algorithms_8h.md)

[Go to the documentation of this file](evab_window_algorithms_8h.md)


```C++
#pragma once

namespace evab
{

  class WindowAlgorithmBase
  {
  public:
    WindowAlgorithmBase();
    
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

  class FlipWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    void Select(signed char aIndex) override;
  };

  class ScrollWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    void Select(signed char aIndex) override;
  };

}
```


