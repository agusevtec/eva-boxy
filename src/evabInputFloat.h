#pragma once

#include "evabElementBase.h"
#include <evaHandler.h>

namespace evab
{

  class InputFloatField : public ElementBase
  {
  public:
    InputFloatField(const char *aName, float aValue);
    void SetValue(float aValue);
    float GetValue();
    static void IndeedDrawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused, const char *aName, float aValue);

  private:
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const char *mName;
    float mValue;
  };

  class InputFloat : public InputFloatField
  {
  public:
    enum EventType
    {
      EVENT_VALUE_CHANGED = 1,
      EVENT_VALUE_CHANGED_WITH_DELTA = 2
    };
    InputFloat(const char *aName, float aValue, eva::IHandler *aOnValueChangedDelegate);
    bool Key(char aKey) override;

  private:
    eva::IHandler *mOnValueChangedDelegate = nullptr;
  };

}
