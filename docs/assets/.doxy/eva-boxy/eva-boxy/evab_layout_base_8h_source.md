

# File evabLayoutBase.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabLayoutBase.h**](evab_layout_base_8h.md)

[Go to the documentation of this file](evab_layout_base_8h.md)


```C++
// evabCompositeBase.h
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class IFocusChain
  {
  public:
    virtual IFocusChain *Next() = 0;

    virtual ElementBase *AsElementBase() = 0;

    virtual void SetNext(IFocusChain *aNext) = 0;

  };

  class LayoutBase : public ElementBase
  {
    template <class T>
    class FocusChain : public T, public IFocusChain
    {
    public:
      template <typename... Args>
      FocusChain(LayoutBase *aParent, Args &&...args)
          : T(args...), mNext(nullptr)
      {
        if (!aParent)
          return;
        IFocusChain *first = aParent->mFocusedChild;
        if (first)
        {
          IFocusChain *last = first;
          while (last->Next() && last->Next() != first)
            last = last->Next();

          last->SetNext(this);
          this->SetNext(first);
        }
        else
        {
          this->SetNext(this);
          aParent->mFocusedChild = this;
        }
      }

      IFocusChain *Next() override
      {
        return mNext;
      }

      virtual void SetNext(IFocusChain *aNext) override
      {
        mNext = aNext;
      }

      virtual ElementBase *AsElementBase() override
      {
        return this;
      }

    private:
      IFocusChain *mNext;
    };

  public:
    bool IsFocused(IFocusChain *aChild);

    ElementBase *GetFocused() const;

    void Increment(signed char delta);

    bool Key(Keys aKey) override;

  protected:
    void focusChild(IFocusChain *aChild);

  private:
    void focusNext();

    void focusPrev();

    virtual bool onResidualKey(Keys aKey);

    virtual void hider();

  private:
    IFocusChain *mFocusedChild = nullptr; 
  };

}
```


