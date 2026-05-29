#pragma once

#include <evabElementBase.h>

namespace evab
{

  class UIButton : public ElementBase
  {
  public:
    UIButton(const __FlashStringHelper *aName);
    void Increment(signed char delta);  // заглушка, ничего не делает

  protected:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const __FlashStringHelper * mName;
  };

}
