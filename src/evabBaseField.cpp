#include "evabBaseField.h"

namespace evab
{

  void BaseField::updateView()
  {
    if (mSize == 0)
      return;
    drawer({(0x7f & mPos) >> 3, 0x7 & mPos}, {mSize >> 4, 0xf & mSize}, mPos >> 7);
  }

  bool BaseField::IsHidden()
  {
    return mSize == 0;
  }

  void BaseField::Draw(Coor aPos, Coor aSize, unsigned char aSelected)
  {
    mPos = (aSelected << 7) | (aPos.X << 3) | (0x7 & aPos.Y);
    mSize = (aSize.X << 4) | (0xf & aSize.Y);
    drawer(aPos, aSize, aSelected);
  }

}
