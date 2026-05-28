#pragma once
#include <evabCoor.h>
#include <evabIScreen.h>

namespace evab
{

  class ElementBase
  {
  public:
    virtual bool Key(char aKey);
    void Hide();
    void Draw(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);
    void Redraw();
    bool IsHidden();

  private:
    virtual void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) = 0;
    virtual void hider() {};

    unsigned short serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
    void deserialize(Coor &aPos, Coor &aSize, bool &isFocused);

  private:
    unsigned short serialized = 0;
  };

}
