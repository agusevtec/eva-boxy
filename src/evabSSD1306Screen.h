#pragma once

#include <evabPage8ScreenBase.h>
#include <evabIFont.h>
#include <Wire.h>

namespace evab
{

  class SSD1306ScreenBase : public Page8ScreenBase
  {
  public:
    SSD1306ScreenBase(const IFont *aFont, uint8_t aHeightPx, uint8_t aAddress = 0x3C);
    ~SSD1306ScreenBase();

    void SetContrast(uint8_t aContrast);
    void ClearDisplay();
    Coor Size() override;

  protected:
    void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
    void ClearTile(Coor aPosition, unsigned char aColor) override;
    void initDisplay();

  private:
    void sendCommand(uint8_t aCmd);
    void sendData(uint8_t aData);

    uint8_t mAddress;
    uint8_t mWidth;  // ширина в пикселях
    uint8_t mHeight; // высота в пикселях
    uint8_t mPages;  // количество страниц
  };

}
