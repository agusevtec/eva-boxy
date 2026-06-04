#pragma once

#include <evabScreenPage8Base.h>
#include <SPI.h>

namespace evab
{

  class ScreenPCD8544 : public ScreenPage8Base
  {
  public:
    ScreenPCD8544(const IFont *aFont, 
                  uint8_t aRST, uint8_t aCE, uint8_t aDC, 
                  uint8_t aDIN, uint8_t aCLK,
                  uint8_t aLED = 255);
    ~ScreenPCD8544();
    
    void setBacklight(uint8_t aState);
    void setContrast(uint8_t aContrast);
    void clear();
    Coor Size() override { return {11, 6}; }

  protected:
    void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
    void ClearTile(Coor aPosition, unsigned char aColor) override;

  private:
    void sendCommand(uint8_t aCmd);
    void sendData(uint8_t aData);
    void initDisplay();
    
    static const uint8_t CMD_FUNC_SET   = 0x20;
    static const uint8_t CMD_DISP_CTRL  = 0x08;
    static const uint8_t CMD_SET_Y      = 0x40;
    static const uint8_t CMD_SET_X      = 0x80;
    static const uint8_t CMD_SET_VOP    = 0x80;
    
    uint8_t mRSTPin;
    uint8_t mCEPin;
    uint8_t mDCPin;
    uint8_t mLEDPin;
  };

}

