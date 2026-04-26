#pragma once

#include "evabBaseElement.h"
#include <evaHandler.h>

namespace evab
{

  class InputIntField : public BaseElement
  {
  public:
    InputIntField(const char *aName, int aValue);
    void SetValue(int aValue);
    int GetValue();
    static void IndeedDrawer(Coor aPos, Coor aSize, unsigned char aSelected, const char *aName, int aValue);

  private:
    void drawer(Coor aPos, Coor aSize, unsigned char aSelected) override;

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
