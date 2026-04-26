#pragma once

#include "evabBaseElement.h"

namespace evab
{

  class BaseComposite : public BaseElement
  {
  public:
    BaseComposite(BaseComposite *aParent = nullptr);
    virtual ~BaseComposite() = default;
    bool IsFocused(BaseElement *aChild);
    bool IsFocused();
    bool Key(char aKey) override;

  protected:
    void focusChild(BaseElement *aChild);

  private:
    virtual bool onKey(char aKey);

  private:
    BaseElement *mFocusedChild = nullptr;
    BaseComposite *mParent;
  };

}
