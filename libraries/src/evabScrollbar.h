#pragma once

#include "evabBaseElement.h"
#include <evaHandler.h>

namespace evab
{

  class ScrollbarField : public BaseElement
  {
  public:
    ScrollbarField(unsigned aCount);
    void SetPosition(int aPosition);
    int GetPosition();
    static void IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, unsigned aPosition, unsigned aCount);

  private:
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;

  private:
    int mPosition;
    unsigned mCount;
  };

  class Scrollbar : public ScrollbarField
  {
  public:
    enum EventType
    {
      EVENT_POSITION_CHANGED = 1
    };
    Scrollbar(unsigned aCount, eva::IHandler *aOnPositionChanged);
    bool Key(char aKey) override;

  private:
    eva::IHandler *mOnPositionChanged;
  };

}
