#pragma once

#include <evabElementBase.h>

namespace evab
{

  class CompositeBase : public ElementBase
  {
  public:
    virtual bool onResidualKey(Keys aKey);
    virtual void hider() = 0;
    bool IsFocused(ElementBase *aChild);

  protected:
    void focusChild(ElementBase *aChild);

  private:
    bool Key(Keys aKey) override;

  private:
    ElementBase *mFocusedChild = nullptr;
  };

}
