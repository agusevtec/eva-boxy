#include "evabModal.h"
//#include "evabInputInt.h"
#include <evabBoxy.h>

using namespace evab;

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
  IScreen *screen = Boxy::Instance()->Screen();
  Coor sz = screen->Size();
  Boxy::Instance()->Enabled(false);
  // TODO:!!!
  //     screen->Fill('-', {0, sz.Y / 2 - 1}, {sz.X, 1}, 0);
  //InputIntField::IndeedDrawer(screen, {0, sz.Y / 2}, {sz.X, 1}, 0, aName, aValue);
  // TODO:!!!
  //     mDisplayPlatform->Fill('-', {0, sz.Y / 2 + 1}, {sz.X, 1}, 0);
  mTimer.start(1200, this);
}

void Modal::invoke(void *msgSender, eva::CallbackInfo cbInfo)
{
  Boxy::Instance()->Enabled(true);
}
