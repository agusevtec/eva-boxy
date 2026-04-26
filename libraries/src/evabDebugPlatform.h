#ifndef EVAB_DEBUG_PLATFORM_H
#define EVAB_DEBUG_PLATFORM_H

#include "evabDisplayPlatform.h"
#include <evaRepeatTimer.h>

namespace evab
{

  class DebugPlatform : public DisplayPlatform, public eva::IHandler
  {
  public:
    DebugPlatform();
    ~DebugPlatform() = default;
    void Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup) override;
    void Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup) override;
    Coor Size() override;
    void invoke(void *msgSender, eva::CallbackInfo cbInfo) override;

  private:
    char mField[7][13];
    eva::RepeatTimer t;
  };

}
#endif
