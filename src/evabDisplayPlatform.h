#ifndef EVAB_DISPLAY_PLATFORM_H
#define EVAB_DISPLAY_PLATFORM_H

#include "evabCoor.h"
#include "evabElementBase.h"

namespace evab
{

  enum DisplayPlatformAlign
  {
    PA_LEFT = 0,
    PA_CENTER,
    PA_RIGHT
  };

  class DisplayPlatform
  {
  public:
    virtual ~DisplayPlatform() = default;
    virtual void Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup) = 0;
    virtual void Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup = 0) = 0;
    virtual Coor Size() = 0;
    void Draw(ElementBase *aGroundElement = nullptr);
    void Key(char aKey);
    void SetFreeze(int aFreeze);
    static DisplayPlatform *Instance(DisplayPlatform *aPlatform = nullptr);

  private:
    ElementBase *mGroundElement = nullptr;
  };

}
#endif
