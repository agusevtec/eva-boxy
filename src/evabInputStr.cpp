#include "evabInputStr.h"


namespace evab
{

  void InputStr::IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, const char *aValue)
  {
    
    if (aSize.Y == 1)
    {
      unsigned char labelSectionSize = 2 * (aSize.X - 2) / 3;
      unsigned char valueSectionSize = aSize.X - labelSectionSize;
      aScreen->TextLeft(aPos, {labelSectionSize, 1}, aName, aIsFocused);
      aScreen->TextRight({aPos.X + labelSectionSize, aPos.Y}, {valueSectionSize, 1}, aValue, aIsFocused);
    }
    if (aSize.Y >= 2)
    {
      aScreen->TextLeft(aPos, {aSize.X, 1}, aName, aIsFocused);
      aScreen->TextRight({aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 1}, aValue, aIsFocused);
    }
  }

}
