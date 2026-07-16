#include <evabElementBase.h>
#include <evabBoxy.h>
using namespace evab;

void ElementBase::Redraw()
{
  if (IsHidden())
    return;

  IScreen *screen = Boxy::Screen();
  if (screen)
  {
    Coor pos, sz;
    bool focused;
    screen->Deserialize(mSerialized, pos, sz, focused);
    drawer(screen, pos, sz, focused);
  }
}

bool ElementBase::IsHidden()
{
  return !((mSerialized >> 0) & 1);
}

void ElementBase::Hide()
{
  hider();
  mSerialized = 0;
}

void ElementBase::Draw(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
  if (!aScreen)
    return;

  if (aSize.X == 0 || aSize.Y == 0)
  {
    hider();
    return;
  }
  drawer(aScreen, aPos, aSize, aIsFocused);
  mSerialized =  aScreen->Serialize(aPos, aSize, aIsFocused);
}

bool ElementBase::Key(Keys)
{
  return false;
}
