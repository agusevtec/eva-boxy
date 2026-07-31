

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
    
    virtual void Select(unsigned char aIndex) = 0;
    
    signed short Selected();
    
    unsigned char Count();
    
    unsigned char WindowSize();

  protected:
    signed char indexInWindow(unsigned char aPosition);
    
    void setCount(unsigned char Count);
    
    void resizeWindow(unsigned char aWindowSize);

  protected:
    unsigned char mSelected;     
    unsigned char mCount;        
    unsigned char mWindowStart;  
    unsigned char mWindowSize;   
  };

  class FlipWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    void Select(unsigned char aIndex) override;
  };

  class ScrollWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    void Select(unsigned char aIndex) override;
  };

}
```


