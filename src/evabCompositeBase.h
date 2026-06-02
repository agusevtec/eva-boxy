#pragma once

#include <evabElementBase.h>

namespace evab
{

  class CompositeBase : public ElementBase
  {
  public:

    bool Key(Keys aKey) override;

  protected:
    void focusChild(ElementBase *aChild);

  private:
    virtual bool onResidualKey(Keys aKey);
    virtual void hider() = 0;
  private:
    ElementBase *mFocusedChild = nullptr;
  };

}
