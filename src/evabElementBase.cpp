#include <evabElementBase.h>
#include <evabBoxy.h>
namespace evab
{

  void ElementBase::Redraw()
  {
    if (mSize == 0)
      return;
    drawer(Boxy::Instance()->Screen(), {(0x7f & mPos) >> 3, 0x7 & mPos}, {mSize >> 4, 0xf & mSize}, mPos >> 7);
  }

  bool ElementBase::IsHidden()
  {
    return mSize == 0;
  }

  void ElementBase::Hide()
  {
    mSize = 0;
    hider();
  }

  void ElementBase::Draw(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    mPos = (aIsFocused << 7) | (aPos.X << 3) | (0x7 & aPos.Y);
    mSize = (aSize.X << 4) | (0xf & aSize.Y);
    if (mSize)
      drawer(aScreen, aPos, aSize, aIsFocused);
    else
      hider();
  }

  bool ElementBase::Key(char aKey)
  {
    return false;
  }
}
