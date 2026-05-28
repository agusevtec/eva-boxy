#include "evabButton.h"

namespace evab
{

  ButtonListItem::ButtonListItem(const char *aName) : mName(aName)
  {
  }

  void ButtonListItem::IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName)
  {
    
    aScreen->TextCenter(aPos, {aSize.X, 1}, aName, aIsFocused);
    for (int i = 1; i < aSize.Y; i++)
      aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
  }

  void ButtonListItem::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    if (IsHidden())
      return;
    ButtonListItem::IndeedDrawer(aScreen, aPos, aSize, aIsFocused, mName);
  }

  Button::Button(const char *aName, eva::IHandler *aOnPressDelegate)
      : ButtonListItem(aName), mOnPressDelegate(aOnPressDelegate)
  {
  }

  bool Button::Key(char aKey)
  {
    if (aKey == 'l' || aKey == 'r')
    {
      if (mOnPressDelegate)
        mOnPressDelegate->invoke(this, {EVENT_PRESS, 0});
      return true;
    }
    return false;
  }

}
