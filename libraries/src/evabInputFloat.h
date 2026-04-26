#pragma once

#include "evabBaseElement.h"
#include <evaHandler.h>

namespace evab
{

  class InputFloatField : public BaseElement
  {
  public:
    InputFloatField(const char *aName, float aValue);
    void SetValue(float aValue);
    float GetValue();
    static void IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, const char *aName, float aValue);

  private:
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;

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
