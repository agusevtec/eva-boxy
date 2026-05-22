#include "evabDisplayPlatform.h"

namespace evab
{

  char stringTemp[20];

  void DisplayPlatform::Draw(ElementBase *aGroundElement)
  {
    if (!mGroundElement && aGroundElement)
      mGroundElement = aGroundElement;
    if (mGroundElement)
      mGroundElement->Draw({0, 0}, Size(), 1);
  }

  void DisplayPlatform::Key(char aKey)
  {
    if (!mGroundElement)
      return;
    mGroundElement->Key(aKey);
  }

  void DisplayPlatform::SetFreeze(int aFreeze)
  {
    if (!mGroundElement)
      return;
    if (aFreeze)
      mGroundElement->Draw({0, 0}, {0, 0}, 1);
    else
      mGroundElement->Draw({0, 0}, Size(), 1);
  }

  DisplayPlatform *DisplayPlatform::Instance(DisplayPlatform *aPlatform)
  {
    static DisplayPlatform *instance = aPlatform;
    return instance;
  }

}
