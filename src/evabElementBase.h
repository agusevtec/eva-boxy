#pragma once
#include "evabCoor.h"

namespace evab
{

  class ElementBase
  {
  public:
    virtual bool Key(char aKey);
    void Hide();
    void Draw(Coor aPos, Coor aSize, unsigned char aSelected);
    void Redraw();
    bool IsHidden();

  private:
    virtual void drawer(Coor aPos, Coor aSize, unsigned char aSelected) = 0;
    virtual void hidder() {};

  private:
    unsigned char mPos = 0;
    unsigned char mSize = 0;
  };

}
