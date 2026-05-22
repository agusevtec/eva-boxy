#include "evabScrollbar.h"
#include "evabDisplayPlatform.h"
#include <Arduino.h>

namespace evab
{

  ScrollbarField::ScrollbarField(unsigned aCount) : mCount(aCount), mPosition(0)
  {
  }

  void ScrollbarField::drawer(Coor aPos, Coor aSize, unsigned char aSelected)
  {
    if (IsHidden())
      return;
    ScrollbarField::IndeedDrawer(aPos, aSize, aSelected, mPosition, mCount);
  }

  void ScrollbarField::IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, unsigned aPosition, unsigned aCount)
  {
    auto p = DisplayPlatform::Instance();
    unsigned char startblock = aPosition * aSize.X / aCount;
    unsigned char blocksize = aSize.X / aCount;
    p->Fill(' ', aPos, {startblock, aSize.Y}, aSelected);
    p->Fill('-', {aPos.X + startblock, aPos.Y}, {blocksize, aSize.Y}, aSelected);
    p->Fill(' ', {aPos.X + startblock + blocksize, aPos.Y}, {aSize.X - startblock - blocksize, aSize.Y}, aSelected);
  }

  void ScrollbarField::SetPosition(int aPosition)
  {
    mPosition = constrain(aPosition, 0, mCount - 1);
  }

  int ScrollbarField::GetPosition()
  {
    return mPosition;
  }

  Scrollbar::Scrollbar(unsigned aCount, eva::IHandler *aOnPositionChanged)
      : ScrollbarField(aCount), mOnPositionChanged(aOnPositionChanged)
  {
  }

  bool Scrollbar::Key(char aKey)
  {
    int delta = 0;
    if (aKey == 'l')
    {
      SetPosition(GetPosition() - 1);
      delta = -1;
    }
    else if (aKey == 'r')
    {
      SetPosition(GetPosition() + 1);
      delta = +1;
    }
    else
      return false;
    if (mOnPositionChanged)
      mOnPositionChanged->invoke(this, {EVENT_POSITION_CHANGED, delta});
    Redraw();
    return true;
  }

}
