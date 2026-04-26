#pragma once

#include "evabBaseField.h"

namespace evab
{

  class BaseElement : public BaseField
  {
  public:
    virtual ~BaseElement() = default;
    virtual bool Key(char aKey);
  };

}
