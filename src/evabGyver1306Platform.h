#ifndef EVAB_GYVER1306_PLATFORM_H
#define EVAB_GYVER1306_PLATFORM_H

#include "evabDisplayPlatform.h"

namespace evab
{

  class Gyver1306Platform : public DisplayPlatform
  {
  public:
    Gyver1306Platform();
    ~Gyver1306Platform() = default;
    void Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup = 0) override;
    void Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup) override;
    Coor Size() override;

  private:
    char mLine[16];
  };

}
#endif
