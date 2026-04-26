#include "evabModal.h"
#include "evabInputInt.h"

namespace evab
{

  Modal::Modal() : mTimer(this)
  {
  }

  Modal &Modal::Instance()
  {
    static Modal inst;
    return inst;
  }

  void Modal::ShowInt(const char *aName, int aValue)
  {
    Coor sz = mDisplayPlatform->Size();
    mDisplayPlatform->SetFreeze(1);
    mDisplayPlatform->Fill('-', {0, sz.Y / 2 - 1}, {sz.X, 1}, 0);
    InputIntField::IndeedDrawer({0, sz.Y / 2}, {sz.X, 1}, 0, aName, aValue);
    mDisplayPlatform->Fill('-', {0, sz.Y / 2 + 1}, {sz.X, 1}, 0);
    mTimer.start(1200, this);
  }

  void Modal::invoke(void *msgSender, eva::CallbackInfo cbInfo)
  {
    (void)msgSender;
    (void)cbInfo;
    mDisplayPlatform->SetFreeze(0);
  }

}
