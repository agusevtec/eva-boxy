#include "evabButton.h"
#include "evabDisplayPlatform.h"

namespace evab
{

  ButtonListItem::ButtonListItem(const char *aName) : mName(aName)
  {
  }

  void ButtonListItem::IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, const char *aName)
  {
    DisplayPlatform *p = DisplayPlatform::Instance();
    p->Display(aPos, {aSize.X, 1}, aName, PA_CENTER, aSelected);
    for (int i = 1; i < aSize.Y; i++)
      p->Fill(' ', {aPos.X, aPos.Y + i}, aSize, aSelected);
  }

  void ButtonListItem::drawer(Coor aPos, Coor aSize, unsigned char aSelected)
  {
    if (IsHidden())
      return;
    ButtonListItem::IndeedDrawer(aPos, aSize, aSelected, mName);
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
