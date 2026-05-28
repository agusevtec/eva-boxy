#pragma once

#include "evabElementBase.h"

namespace evab
{

  class BatteryIndicator : public ElementBase
  {
  public:
    void SetVoltage(float aVoltage);

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    float mVoltage = 0;
  };

}
