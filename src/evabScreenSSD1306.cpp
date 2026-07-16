#include <evabScreenSSD1306.h>

using namespace evab;

ScreenSSD1306::ScreenSSD1306(const IFont *aFont, unsigned long aWireClock, uint8_t aHeightPx)
    : ScreenPage8Base(aFont), mAddress(0x3C)
{
  Coor sz = Size();
  mWidth = 128;
  mHeight = aHeightPx;
  mPages = aHeightPx / 8;

  Wire.begin();
  Wire.setClock(aWireClock);
  initDisplay();
  clearDisplay();
}

ScreenSSD1306::~ScreenSSD1306()
{
}

void ScreenSSD1306::sendCommand(uint8_t aCmd)
{
  Wire.beginTransmission(mAddress);
  Wire.write(0x00);
  Wire.write(aCmd);
  Wire.endTransmission();
}

void ScreenSSD1306::sendData(uint8_t aData)
{
  Wire.beginTransmission(mAddress);
  Wire.write(0x40);
  Wire.write(aData);
  Wire.endTransmission();
}

void ScreenSSD1306::initDisplay()
{
  sendCommand(0xAE);
  sendCommand(0xD5);
  sendCommand(0x80);
  sendCommand(0xA8);
  sendCommand(mHeight - 1);
  sendCommand(0xD3);
  sendCommand(0x00);
  sendCommand(0x40);
  sendCommand(0x8D);
  sendCommand(0x14);
  sendCommand(0xA1);
  sendCommand(0xC8);
  sendCommand(0xDA);
  sendCommand((mHeight == 64) ? 0x12 : 0x02);
  sendCommand(0x81);
  sendCommand(0x7F);
  sendCommand(0xD9);
  sendCommand(0xF1);
  sendCommand(0xDB);
  sendCommand(0x40);
  sendCommand(0xA4);
  sendCommand(0xA6);
  sendCommand(0xAF);
}

void ScreenSSD1306::SetContrast(uint8_t aContrast)
{
  sendCommand(0x81);
  sendCommand(aContrast);
}

void ScreenSSD1306::ClearDisplay()
{
  for (uint8_t page = 0; page < mPages; page++)
  {
    sendCommand(0xB0 | page);
    sendCommand(0x00);
    sendCommand(0x10);

    for (uint16_t i = 0; i < mWidth; i++)
      sendData(0x00);
  }
}

void ScreenSSD1306::DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice)
{
  uint8_t x = aPosition.X * 8 + aSliceColumn;
  uint8_t page = aPosition.Y;

  if (x >= mWidth || page >= mPages)
    return;

  sendCommand(0xB0 | page);
  sendCommand(x & 0x0F);
  sendCommand(0x10 | ((x >> 4) & 0x0F));
  sendData(aSlice);
}

void ScreenSSD1306::ClearTile(Coor aPosition, unsigned char aColor)
{
  uint8_t startX = aPosition.X * 8;
  uint8_t page = aPosition.Y;

  if (startX >= mWidth || page >= mPages)
    return;

  sendCommand(0xB0 | page);
  sendCommand(startX & 0x0F);
  sendCommand(0x10 | ((startX >> 4) & 0x0F));

  for (uint8_t col = 0; col < 8; col++)
    sendData(aColor ? 0xFF : 0x00);
}

Coor ScreenSSD1306::Size()
{
  return {16, mPages};
}

#include <evabSerializers.h>

unsigned short ScreenSSD1306::Serialize(const Coor &aPos, const Coor &aSize, bool isFocused)
{
    return serialize_16x8(aPos, aSize, isFocused);
}

void ScreenSSD1306::Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
    deserialize_16x8(aSerialized, aPos, aSize, isFocused);
}
