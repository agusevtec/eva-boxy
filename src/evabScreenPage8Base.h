#pragma once

#include <evabCoor.h>
#include <evabScreenBase.h>
#include <evabIFont.h>

namespace evab
{
  class ScreenPage8Base : public ScreenBase
  {
  public:
    ScreenPage8Base(const IFont* mFont);
    
    void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor);
    void Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor);
 
  protected:
    virtual void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) = 0;

  private:
    const IFont* mFont;
    
    uint32_t upscaleY(uint8_t x, uint8_t scale);
  };

}