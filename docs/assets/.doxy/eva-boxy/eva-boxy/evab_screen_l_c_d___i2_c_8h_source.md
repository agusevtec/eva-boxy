

# File evabScreenLCD\_I2C.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabScreenLCD\_I2C.h**](evab_screen_l_c_d___i2_c_8h.md)

[Go to the documentation of this file](evab_screen_l_c_d___i2_c_8h.md)


```C++
#pragma once

#include <evabScreenBase.h>
#include <Wire.h>

namespace evab
{

  class ScreenLCD_I2C : public ScreenBase
  {
  public:
    ScreenLCD_I2C(uint8_t aAddress, uint8_t aCols, uint8_t aRows, uint8_t aBacklightPin = 3);
    
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
```


