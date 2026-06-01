#include <evabLCD_I2CScreen.h>

using namespace evab;
  LCD_I2CScreen::LCD_I2CScreen(uint8_t aAddress, uint8_t aCols, uint8_t aRows, uint8_t aBacklightPin)
    : mAddress(aAddress), mCols(aCols), mRows(aRows), mBacklightPin(aBacklightPin)
  {
    mBacklightMask = 1 << mBacklightPin;
    
    Wire.begin();
    
    // Инициализация HD44780 через I2C
    delay(50);
    sendNibble(0x30, true);
    delay(5);
    sendNibble(0x30, true);
    delay(1);
    sendNibble(0x30, true);
    delay(1);
    sendNibble(0x20, true);
    delay(1);
    
    sendByte(0x28, true);  // 4-bit, 2 lines, 5x8
    sendByte(0x08, true);  // display off
    sendByte(0x01, true);  // clear
    delay(2);
    sendByte(0x06, true);  // entry mode
    sendByte(0x0C, true);  // display on, cursor off
    
    setBacklight(HIGH);
    clear();
  }

  void LCD_I2CScreen::sendNibble(uint8_t aData, bool aIsCommand)
  {
    uint8_t value = aData | (aIsCommand ? 0x00 : 0x02);
    value |= mBacklightMask;
    
    Wire.beginTransmission(mAddress);
    Wire.write(value | 0x04);
    Wire.endTransmission();
    delayMicroseconds(1);
    
    Wire.beginTransmission(mAddress);
    Wire.write(value & ~0x04);
    Wire.endTransmission();
    delayMicroseconds(50);
  }

  void LCD_I2CScreen::sendByte(uint8_t aData, bool aIsCommand)
  {
    sendNibble(aData & 0xF0, aIsCommand);
    sendNibble((aData << 4) & 0xF0, aIsCommand);
  }

  void LCD_I2CScreen::setBacklight(uint8_t aState)
  {
    if (aState)
      mBacklightMask |= (1 << mBacklightPin);
    else
      mBacklightMask &= ~(1 << mBacklightPin);
    sendByte(0x00, true);
  }

  void LCD_I2CScreen::clear()
  {
    sendByte(0x01, true);
    delay(2);
  }

  // void LCD_I2CScreen::home()
  // {
  //   sendByte(0x02, true);
  //   delay(2);
  // }

  void LCD_I2CScreen::setCursor(uint8_t aCol, uint8_t aRow)
  {
    uint8_t rowOffsets[] = {0x00, 0x40, 0x14, 0x54};
    if (aRow >= mRows)
      aRow = mRows - 1;
    sendByte(0x80 | (aCol + rowOffsets[aRow]), true);
    delay(1);
  }

  void LCD_I2CScreen::DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor)
  {
    (void)aSize;
    (void)aColor;
    
    if (aPosition.X < mCols && aPosition.Y < mRows)
    {
      setCursor(aPosition.X, aPosition.Y);
      sendByte(aCharcode, false);
    }
  }


