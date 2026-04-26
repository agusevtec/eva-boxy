#include "evabInputStr.h"
#include "evabDisplayPlatform.h"

namespace evab
{

  void InputStr::IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, const char *aName, const char *aValue)
  {
    DisplayPlatform *p = DisplayPlatform::Instance();
    if (aSize.Y == 1)
    {
      unsigned char labelSectionSize = 2 * (aSize.X - 2) / 3;
      unsigned char valueSectionSize = aSize.X - labelSectionSize;
      p->Display(aPos, {labelSectionSize, 1}, aName, PA_LEFT, aSelected);
      p->Display({aPos.X + labelSectionSize, aPos.Y}, {valueSectionSize, 1}, aValue, PA_RIGHT, aSelected);
    }
    if (aSize.Y >= 2)
    {
      p->Display(aPos, {aSize.X, 1}, aName, PA_LEFT, aSelected);
      p->Display({aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 1}, aValue, PA_RIGHT, aSelected);
    }
  }

}
