#include <evabElementBase.h>
#include <evabBoxy.h>
using namespace evab;

void ElementBase::redraw()
{
  if (isMuted())
    return;

  Screen *screen = Boxy::GetScreen();
  if (!screen)
    return;

  Coor currentPos, currentSize;
  bool isFocused;
  screen->Deserialize(mSerialized, currentPos, currentSize, isFocused);
  drawer(screen, currentPos, currentSize, isFocused);
}

bool ElementBase::isMuted()
{
  return mSerialized == 0;
}

void ElementBase::Mute()
{
  mSerialized = 0;
  muter();
}

void ElementBase::Draw(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
  if (!aScreen)
    return;

  if (aSize.X == 0 || aSize.Y == 0)
  {
    muter();
    return;
  }
  drawer(aScreen, aPos, aSize, aIsFocused);
  mSerialized = aScreen->Serialize(aPos, aSize, aIsFocused);
}

bool ElementBase::OnKey(Keys)
{
  return false;
}
