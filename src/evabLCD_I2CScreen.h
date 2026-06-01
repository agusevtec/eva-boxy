#pragma once

#include <evabScreenBase.h>
#include <Wire.h>

namespace evab
{

  class LCD_I2CScreen : public ScreenBase
  {
  public:
    LCD_I2CScreen(uint8_t aAddress, uint8_t aCols, uint8_t aRows, uint8_t aBacklightPin = 3);
    
    void setBacklight(uint8_t aState);
    void clear();
    Coor Size() override { return {mCols, mRows}; }

  protected:
    void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor) override;

  private:
    void sendByte(uint8_t aData, bool aIsCommand);
    void sendNibble(uint8_t aData, bool aIsCommand);
    void initDisplay();
    void setCursor(uint8_t aCol, uint8_t aRow);
    
    uint8_t mAddress;
    uint8_t mCols;
    uint8_t mRows;
    uint8_t mBacklightPin;
    uint8_t mBacklightMask;
  };

}
