// #include "evabScrollbar.h"

// #include <Arduino.h>

// namespace evab
// {

//   ScrollbarField::ScrollbarField(unsigned aCount) : mCount(aCount), mPosition(0)
//   {
//   }

//   void ScrollbarField::drawer(Coor aPos, Coor aSize, unsigned char aIsFocused)
//   {
//     if (IsHidden())
//       return;
//     ScrollbarField::IndeedDrawer(aPos, aSize, aIsFocused, mPosition, mCount);
//   }

//   void ScrollbarField::IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, unsigned aPosition, unsigned aCount)
//   {
//     auto p = DisplayPlatform::Instance();
//     unsigned char startblock = aPosition * aSize.X / aCount;
//     unsigned char blocksize = aSize.X / aCount;
//     aScreen->Clear(aPos, {startblock, aSize.Y}, aIsFocused);
//     p->Fill('-', {aPos.X + startblock, aPos.Y}, {blocksize, aSize.Y}, aIsFocused);
//     aScreen->Clear({aPos.X + startblock + blocksize, aPos.Y}, {aSize.X - startblock - blocksize, aSize.Y}, aIsFocused);
//   }

//   void ScrollbarField::SetPosition(int aPosition)
//   {
//     mPosition = constrain(aPosition, 0, mCount - 1);
//   }

//   int ScrollbarField::GetPosition()
//   {
//     return mPosition;
//   }

//   Scrollbar::Scrollbar(unsigned aCount, eva::IHandler *aOnPositionChanged)
//       : ScrollbarField(aCount), mOnPositionChanged(aOnPositionChanged)
//   {
//   }

//   bool Scrollbar::Key(char aKey)
//   {
//     int delta = 0;
//     if (aKey == 'l')
//     {
//       SetPosition(GetPosition() - 1);
//       delta = -1;
//     }
//     else if (aKey == 'r')
//     {
//       SetPosition(GetPosition() + 1);
//       delta = +1;
//     }
//     else
//       return false;
//     if (mOnPositionChanged)
//       mOnPositionChanged->invoke(this, {EVENT_POSITION_CHANGED, delta});
//     Redraw();
//     return true;
//   }

// }
