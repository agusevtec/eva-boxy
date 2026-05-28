// #pragma once

// #include "evabElementBase.h"
// #include <evaHandler.h>

// namespace evab
// {

//   class ScrollbarField : public ElementBase
//   {
//   public:
//     ScrollbarField(unsigned aCount);
//     void SetPosition(int aPosition);
//     int GetPosition();
//     static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, unsigned aPosition, unsigned aCount);

//   private:
//     void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

//   private:
//     int mPosition;
//     unsigned mCount;
//   };

//   class Scrollbar : public ScrollbarField
//   {
//   public:
//     enum EventType
//     {
//       EVENT_POSITION_CHANGED = 1
//     };
//     Scrollbar(unsigned aCount, eva::IHandler *aOnPositionChanged);
//     bool Key(char aKey) override;

//   private:
//     eva::IHandler *mOnPositionChanged;
//   };

// }
