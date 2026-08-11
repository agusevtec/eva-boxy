

# File evabLayoutBase.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabLayoutBase.h**](evab_layout_base_8h.md)

[Go to the documentation of this file](evab_layout_base_8h.md)


```C++
// evabCompositeBase.h
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class LayoutBase : public ElementBase
  {

    class FocusableBase
    {
    public:
      ElementBase *element;
      FocusableBase *next;
      FocusableBase(ElementBase *aElement) : element(aElement), next(nullptr) {}
    };

    template <class T>
    class Focusable : public T, public FocusableBase
    {
    public:
      template <typename... Args>
      Focusable(LayoutBase *aParent, Args &&...args)
          : T(args...), FocusableBase(this)
      {
        if (!aParent)
          return;

        FocusableBase *first = aParent->mFocusedChild;
        if (first)
        {
          FocusableBase *last = first;
          while (last->next && last->next != first)
            last = last->next;

          last->next = this;
          this->next = first;
        }
        else
        {
          this->next = this;
          aParent->mFocusedChild = this;
        }
      }
    };

  public:
    bool IsFocused(FocusableBase *aChild);

    ElementBase *GetFocused() const;

    void Increment(signed char delta);

    bool OnKey(Keys aKey) override;

  protected:
    void focusChild(FocusableBase *aChild);

  private:
    void focusNext();

    void focusPrev();

    virtual bool onResidualKey(Keys aKey);

    virtual void freezer();

  private:
    FocusableBase *mFocusedChild = nullptr; 
  };

}
```


