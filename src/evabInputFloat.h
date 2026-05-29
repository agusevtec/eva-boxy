#pragma once

#include <evabElementBase.h>

namespace evab
{

  class InputFloat : public ElementBase
  {
  public:
    InputFloat(float aValue = 0);
    void SetValue(float aValue);
    float GetValue() const;
    void Increment(signed char delta);

  protected:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    float mValue;

  };

}
