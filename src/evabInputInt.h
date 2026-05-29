#pragma once

#include "evabElementBase.h"

namespace evab
{

  class InputInt : public ElementBase
  {
  public:
    InputInt(int aValue = 0);
    void SetValue(int aValue);
    int GetValue() const;
    void Increment(signed char delta);

  protected:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    int mValue;
  };

}
