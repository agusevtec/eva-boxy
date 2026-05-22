#pragma once

#include "evabElementBase.h"

namespace evab
{

  class BatteryIndicator : public ElementBase
  {
  public:
    void SetVoltage(float aVoltage);

  private:
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;

  private:
    float mVoltage = 0;
  };

}
