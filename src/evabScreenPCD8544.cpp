#include <evabScreenPCD8544.h>

using namespace evab;

ScreenPCD8544::ScreenPCD8544(const IFont *aFont,
                             uint8_t aRST, uint8_t aCE, uint8_t aDC,
                             uint8_t aDIN, uint8_t aCLK,
                             uint8_t aLED)
    : ScreenPage8Base(aFont), mRSTPin(aRST), mCEPin(aCE), mDCPin(aDC), mLEDPin(aLED)
{
  pinMode(mRSTPin, OUTPUT);
  pinMode(mCEPin, OUTPUT);
  pinMode(mDCPin, OUTPUT);

  if (mLEDPin != 255)
    pinMode(mLEDPin, OUTPUT);

  digitalWrite(mCEPin, HIGH);

  // Аппаратный сброс
  digitalWrite(mRSTPin, LOW);
  delay(10);
  digitalWrite(mRSTPin, HIGH);
  delay(10);

  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV4);

  initDisplay();
  clear();
}

ScreenPCD8544::~ScreenPCD8544()
{
}

void ScreenPCD8544::setBacklight(uint8_t aState)
{
  if (mLEDPin != 255)
    digitalWrite(mLEDPin, aState);
}

void ScreenPCD8544::setContrast(uint8_t aContrast)
{
  sendCommand(CMD_FUNC_SET | 0x01);
  sendCommand(CMD_SET_VOP | (aContrast & 0x7F));
  sendCommand(CMD_FUNC_SET);
}

void ScreenPCD8544::clear()
{
  for (uint8_t page = 0; page < 6; page++)
  {
    for (uint8_t col = 0; col < 84; col++)
    {
      DrawVerticalSlice({(uint8_t)(col / 8), page}, col % 8, 0x00);
    }
  }
}

void ScreenPCD8544::sendCommand(uint8_t aCmd)
{
  digitalWrite(mDCPin, LOW);
  digitalWrite(mCEPin, LOW);
  SPI.transfer(aCmd);
  digitalWrite(mCEPin, HIGH);
}

void ScreenPCD8544::sendData(uint8_t aData)
{
  digitalWrite(mDCPin, HIGH);
  digitalWrite(mCEPin, LOW);
  SPI.transfer(aData);
  digitalWrite(mCEPin, HIGH);
}

void ScreenPCD8544::initDisplay()
{
  sendCommand(CMD_FUNC_SET);
  sendCommand(CMD_DISP_CTRL | 0x04);
  sendCommand(CMD_SET_Y | 0x00);
  sendCommand(CMD_SET_X | 0x00);
  setContrast(0x30);
}

void ScreenPCD8544::DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice)
{
  uint8_t x = aPosition.X * 8 + aSliceColumn;
  uint8_t page = aPosition.Y;

  if (x >= 84 || page >= 6)
    return;

  sendCommand(CMD_SET_Y | (page & 0x07));
  sendCommand(CMD_SET_X | (x & 0x7F));
  sendData(aSlice);
}

void ScreenPCD8544::ClearTile(Coor aPosition, unsigned char aColor)
{
  for (uint8_t col = 0; col < 8; col++)
  {
    DrawVerticalSlice({aPosition.X, aPosition.Y}, col, aColor ? 0xFF : 0x00);
  }
}

#include <evabSerializers.h>

unsigned short ScreenPCD8544::Serialize(const Coor &aPos, const Coor &aSize, bool isFocused)
{
  return serialize_16x8(aPos, aSize, isFocused);
}

void ScreenPCD8544::Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
  deserialize_16x8(aSerialized, aPos, aSize, isFocused);
}
