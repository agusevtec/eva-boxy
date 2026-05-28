#pragma once

#include <evabElementBase.h>

namespace evab
{

  class CompositeBase : public ElementBase
  {
  public:

    bool Key(char aKey) override;

  protected:
    void focusChild(ElementBase *aChild);

  private:
    virtual bool onResidualKey(char aKey);
    virtual void hider() = 0;
  private:
    ElementBase *mFocusedChild = nullptr;
  };

}
