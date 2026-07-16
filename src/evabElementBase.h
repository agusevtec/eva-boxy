#pragma once
#include <evabCoor.h>
#include <evabIScreen.h>
#include <evabKeys.h>

namespace evab
{

  class ElementBase
  {
  public:
    virtual bool Key(Keys aKey);
    void Hide();
    void Draw(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);
    void Redraw();
    bool IsHidden();

  private:
    virtual void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) = 0;
    virtual void hider() {};

  private:
    unsigned short mSerialized = 0;
  };

}
