#pragma once

#include <evaDelayTimer.h>
#include "evabDisplayPlatform.h"

namespace evab
{

  class Modal : public eva::IHandler
  {
  public:
    static Modal &Instance();
    void ShowInt(const char *aName, int aValue);
    void invoke(void *msgSender, eva::CallbackInfo cbInfo) override;

  private:
    Modal();

  private:
    eva::DelayTimer mTimer;
    DisplayPlatform *mDisplayPlatform = DisplayPlatform::Instance();
  };

}
