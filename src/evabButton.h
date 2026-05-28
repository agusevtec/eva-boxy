#pragma once

#include "evabElementBase.h"
#include <evaHandler.h>

namespace evab
{

  class ButtonListItem : public ElementBase
  {
  public:
    ButtonListItem(const char *aName);
    static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName);

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const char *mName;
  };

  class Button : public ButtonListItem
  {
  public:
    enum EventType
    {
      EVENT_PRESS = 1
    };
    Button(const char *aName, eva::IHandler *aOnPressDelegate = nullptr);
    bool Key(char aKey) override;

  private:
    eva::IHandler *mOnPressDelegate;
  };

}
