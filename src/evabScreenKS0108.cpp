#include <evabScreenKS0108.h>
#include <Arduino.h>
#include <evabSerializers.h>

using namespace evab;

ScreenKS0108::ScreenKS0108(const IFont *aFont,
                           uint8_t aRS, uint8_t aRW, uint8_t aE,
                           uint8_t aCS1, uint8_t aCS2,
                           uint8_t aDB0, uint8_t aDB1, uint8_t aDB2, uint8_t aDB3,
                           uint8_t aDB4, uint8_t aDB5, uint8_t aDB6, uint8_t aDB7,
                           uint8_t aLED)
    : ScreenPage8Base(aFont),
      mRSPin(aRS), mRWPin(aRW), mEPin(aE),
      mCS1Pin(aCS1), mCS2Pin(aCS2), mLEDPin(aLED), mCurrentChip(0)
{
    mDataPins[0] = aDB0;
    mDataPins[1] = aDB1;
    mDataPins[2] = aDB2;
    mDataPins[3] = aDB3;
    mDataPins[4] = aDB4;
    mDataPins[5] = aDB5;
    mDataPins[6] = aDB6;
    mDataPins[7] = aDB7;

    // pinMode(mRSPin, OUTPUT);
    // pinMode(mRWPin, OUTPUT);
    // pinMode(mEPin, OUTPUT);
    // pinMode(mCS1Pin, OUTPUT);
    // pinMode(mCS2Pin, OUTPUT);

    // for (int i = 0; i < 8; i++)
    //     pinMode(mDataPins[i], OUTPUT);

    // if (mLEDPin != 255)
    //     pinMode(mLEDPin, OUTPUT);

    digitalWrite(mRWPin, LOW);
    digitalWrite(mEPin, LOW);

    initDisplay();
    clear();
}

ScreenKS0108::~ScreenKS0108()
{
}

void ScreenKS0108::setBacklight(uint8_t aState)
{
    if (mLEDPin != 255)
        digitalWrite(mLEDPin, aState);
}

void ScreenKS0108::setChip(uint8_t aChip)
{
    digitalWrite(mCS1Pin, (aChip == 0) ? HIGH : LOW);
    digitalWrite(mCS2Pin, (aChip == 1) ? HIGH : LOW);
    mCurrentChip = aChip;
}

void ScreenKS0108::writeByte(uint8_t aByte)
{
    for (int i = 0; i < 8; i++)
        digitalWrite(mDataPins[i], (aByte >> i) & 1);
}

void ScreenKS0108::pulseE()
{
    digitalWrite(mEPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(mEPin, LOW);
    delayMicroseconds(1);
}

void ScreenKS0108::sendCommand(uint8_t aCmd, uint8_t aChip)
{
    setChip(aChip);
    digitalWrite(mRSPin, LOW);
    writeByte(aCmd);
    pulseE();
}

void ScreenKS0108::sendData(uint8_t aData, uint8_t aChip)
{
    setChip(aChip);
    digitalWrite(mRSPin, HIGH);
    writeByte(aData);
    pulseE();
}

void ScreenKS0108::setPage(uint8_t aPage)
{
    // page 0-7 (0xB0-0xB7)
    uint8_t cmd = 0xB0 | (aPage & 0x07);
    sendCommand(cmd, 0);
    sendCommand(cmd, 1);
}

void ScreenKS0108::setColumn(uint8_t aCol)
{
    // column 0-63 (0x40-0x7F)
    uint8_t cmd = 0x40 | (aCol & 0x3F);
    sendCommand(cmd, 0);
    sendCommand(cmd, 1);
}

void ScreenKS0108::initDisplay()
{
    setPage(0);
    setColumn(0);

    // Display on
    sendCommand(0x3F, 0);
    sendCommand(0x3F, 1);

    delay(10);
}

void ScreenKS0108::clear()
{
    for (uint8_t page = 0; page < 8; page++)
    {
        setPage(page);
        setColumn(0);

        for (uint8_t chip = 0; chip < 2; chip++)
        {
            setChip(chip);
            for (uint8_t col = 0; col < 64; col++)
            {
                sendData(0x00, chip);
            }
        }
    }
}

Coor ScreenKS0108::Size()
{
    return {16, 8}; // 128/8 = 16 тайлов, 8 страниц
}

void ScreenKS0108::DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice)
{
    uint8_t x = aPosition.X * 8 + aSliceColumn;
    uint8_t page = aPosition.Y;
    uint8_t chip = (x < 64) ? 0 : 1;
    uint8_t col = (x < 64) ? x : x - 64;

    if (x >= 128 || page >= 8)
        return;

    setPage(page);
    setColumn(col);
    sendData(aSlice, chip);
}

void ScreenKS0108::ClearTile(Coor aPosition, unsigned char aColor)
{
    uint8_t startCol = aPosition.X * 8;
    uint8_t page = aPosition.Y;

    if (startCol >= 128 || page >= 8)
        return;

    setPage(page);

    for (uint8_t chip = 0; chip < 2; chip++)
    {
        uint8_t chipStart = (chip == 0) ? 0 : 64;
        uint8_t chipEnd = (chip == 0) ? 64 : 128;

        uint8_t from = max((int)startCol, (int)chipStart);
        uint8_t to = min((int)(startCol + 8), (int)chipEnd);

        if (from < to)
        {
            setChip(chip);
            for (uint8_t col = from; col < to; col++)
            {
                setColumn(col);
                sendData(aColor ? 0xFF : 0x00, chip);
            }
        }
    }
}



unsigned short ScreenKS0108::Serialize(const Coor &aPos, const Coor &aSize, bool isFocused)
{
    return serialize_16x8(aPos, aSize, isFocused);
}

void ScreenKS0108::Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
    deserialize_16x8(aSerialized, aPos, aSize, isFocused);
}