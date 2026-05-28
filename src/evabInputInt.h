#pragma once

#include "evabElementBase.h"
#include <evaHandler.h>

namespace evab
{

  class InputIntField : public ElementBase
  {
  public:
    InputIntField(const char *aName, int aValue);
    void SetValue(int aValue);
    int GetValue();
    static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, int aValue);

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const char *mName;
    int mValue;
  };

  class InputInt : public InputIntField
  {
  public:
    enum EventType
    {
      EVENT_VALUE_CHANGED = 1,
      EVENT_VALUE_CHANGED_WITH_DELTA = 2
    };
    InputInt(const char *aName, int aValue, eva::IHandler *aOnValueChangedDelegate);
    bool Key(char aKey) override;

  private:
    eva::IHandler *mOnValueChangedDelegate = nullptr;
  };

}
