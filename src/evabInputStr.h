#pragma once

#include <evabCoor.h>
#include <evabIScreen.h>
namespace evab
{

  class InputStr
  {
  public:
    static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, const char *aValue);
  };

}
