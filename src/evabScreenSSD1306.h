#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>
#include <Wire.h>

namespace evab
{

  class ScreenSSD1306 : public ScreenPage8Base
  {
  public:
    ScreenSSD1306(const IFont *aFont, uint8_t aHeightPx);
    ~ScreenSSD1306();

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
