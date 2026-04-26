#pragma once

#include "evabCoor.h"

namespace evab
{

  class BaseField
  {
  public:
    virtual ~BaseField() = default;
    bool IsHidden();
    void Draw(Coor aPos, Coor aSize, unsigned char aSelected);

  protected:
    void updateView();

  private:
    virtual void drawer(Coor aPos, Coor aSize, unsigned char aSelected) = 0;

  private:
    unsigned char mPos = 0;
    unsigned char mSize = 0;
  };

}
