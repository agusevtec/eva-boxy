#include <ProgressBar.h>

using namespace evab;
// 8x8 pictogram
inline const uint8_t picto_progress_10[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7f, 0xc0, 0x80, 0x80, 0x80, 0x80, 0xc0, 0x7f};

// 8x8 pictogram
inline const uint8_t picto_progress_11[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7f, 0xc0, 0x98, 0xbc, 0xbc, 0x98, 0xc0, 0x7f};

// 8x8 pictogram
inline const uint8_t picto_progress_12[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7f, 0xc0, 0x9e, 0xbf, 0xbf, 0x9e, 0xc0, 0x7f};

// 8x8 pictogram
inline const uint8_t picto_progress_1full[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7f, 0xc0, 0x9f, 0xbf, 0xbf, 0x9f, 0xc0, 0x7f};

// 8x8 pictogram
inline const uint8_t picto_progress_20[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff};

// 8x8 pictogram
inline const uint8_t picto_progress_21[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xff, 0x00, 0xe0, 0xf0, 0xf0, 0xe0, 0x00, 0xff};

// 8x8 pictogram
inline const uint8_t picto_progress_22[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xff, 0x00, 0xfe, 0xff, 0xff, 0xfe, 0x00, 0xff};

// 8x8 pictogram
inline const uint8_t picto_progress_2full[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff};

// 8x8 pictogram
inline const uint8_t picto_progress_30[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xfe, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0xfe};

// 8x8 pictogram
inline const uint8_t picto_progress_31[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xfe, 0x03, 0xc1, 0xe1, 0xe1, 0xc1, 0x03, 0xfe};

// 8x8 pictogram
inline const uint8_t picto_progress_3full[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xfe, 0x03, 0xf9, 0xfd, 0xfd, 0xf9, 0x03, 0xfe};

static unsigned char *getPicto(unsigned char blockNumber, unsigned char blockFillNumber)
{
    switch ((blockNumber << 4) | (blockFillNumber))
    {
    case 0x10:
        return picto_progress_10;
    case 0x11:
        return picto_progress_11;
    case 0x12:
        return picto_progress_12;
    case 0x13:
        return picto_progress_1full;
    case 0x20:
        return picto_progress_20;
    case 0x21:
        return picto_progress_21;
    case 0x22:
        return picto_progress_22;
    case 0x23:
        return picto_progress_2full;
    case 0x30:
        return picto_progress_30;
    case 0x31:
        return picto_progress_31;
    case 0x32:
        return picto_progress_3full;
    case 0x33:
        return picto_progress_3full;
    }
    return nullptr;
}

ProgressBar::ProgressBar(unsigned char aValue)
    : mValue(aValue)
{
}

void ProgressBar::SetValue(unsigned char aValue)
{
    mValue = aValue;
}

unsigned blockFillNumber(unsigned char blockNumber, unsigned char normalizedValue)
{
    if (blockNumber < normalizedValue/3)
      return 3;
    if (blockNumber > normalizedValue/3)
      return 0;
    return normalizedValue % 3;
}

void ProgressBar::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
    unsigned short maxvalue = 3 + (aSize.Y - 2) * 3 + 2;
    unsigned short normalizedValue = maxvalue * mValue / 100;
    aScreen->Picto({aPos.X, aPos.Y + aSize.Y - 1}, getPicto(0, blockFillNumber(0, normalizedValue)));
    for (unsigned char i = 1; i < aSize.Y - 1; i++)
        aScreen->Picto({aPos.X, aPos.Y + aSize.Y - 1}, getPicto(1, blockFillNumber(i, normalizedValue)));
    aScreen->Picto({aPos.X, aPos.Y + aSize.Y - 1}, getPicto(2, blockFillNumber(aSize.Y, normalizedValue)));
}
