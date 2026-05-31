#include <evabProgressBar.h>

using namespace evab;
// 8x8 pictogram
const uint8_t picto_progress_11[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0x7f, 0xc0, 0x80, 0x80, 0x80, 0x80, 0xc0, 0x7f
};

// 8x8 pictogram
const uint8_t picto_progress_12[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0x7f, 0xc0, 0x98, 0xbc, 0xbc, 0x98, 0xc0, 0x7f
};

// 8x8 pictogram
const uint8_t picto_progress_13[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0x7f, 0xc0, 0x9e, 0xbf, 0xbf, 0x9e, 0xc0, 0x7f
};

// 8x8 pictogram
const uint8_t picto_progress_14[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0x7f, 0xc0, 0x9f, 0xbf, 0xbf, 0x9f, 0xc0, 0x7f
};

// 8x8 pictogram
const uint8_t picto_progress_20[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff
};

// 8x8 pictogram
const uint8_t picto_progress_21[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xff, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0xff
};

// 8x8 pictogram
const uint8_t picto_progress_22[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xff, 0x00, 0xf0, 0xf8, 0xf8, 0xf0, 0x00, 0xff
};

// 8x8 pictogram
const uint8_t picto_progress_23[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xff, 0x00, 0xfe, 0xff, 0xff, 0xfe, 0x00, 0xff
};

// 8x8 pictogram
const uint8_t picto_progress_24[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff
};

// 8x8 pictogram
const uint8_t picto_progress_30[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xfe, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0xfe
};

// 8x8 pictogram
const uint8_t picto_progress_31[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xfe, 0x03, 0x81, 0xc1, 0xc1, 0x81, 0x03, 0xfe
};

// 8x8 pictogram
const uint8_t picto_progress_32[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xfe, 0x03, 0xe1, 0xf1, 0xf1, 0xe1, 0x03, 0xfe
};

// 8x8 pictogram
const uint8_t picto_progress_33[] PROGMEM = {
    8, 8,  // (8x8 пикселей)
    0xfe, 0x03, 0xf9, 0xfd, 0xfd, 0xf9, 0x03, 0xfe
};

static const unsigned char *getPicto(unsigned char blockType, unsigned char fillNumber)
{
    switch ((blockType << 4) | (fillNumber))
    {
    case 0x11:
        return picto_progress_11;
    case 0x12:
        return picto_progress_12;
    case 0x13:
        return picto_progress_13;
    case 0x14:
        return picto_progress_14;
    case 0x20:
        return picto_progress_20;
    case 0x21:
        return picto_progress_21;
    case 0x22:
        return picto_progress_22;
    case 0x23:
        return picto_progress_23;
    case 0x24:
        return picto_progress_24;
    case 0x30:
        return picto_progress_30;
    case 0x31:
        return picto_progress_31;
    case 0x32:
        return picto_progress_32;
    case 0x33:
        return picto_progress_33;
    }
    Serial.print("Error ");
    Serial.println(blockType);
    Serial.println(fillNumber);
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

unsigned char evab::ProgressBar::Resolution()
{
    return 0;
}

char fillNumber(unsigned char blockNumber, unsigned char normalizedValue)
{
    if (normalizedValue / 3 < blockNumber)
        return 0;
    if (normalizedValue / 3 > blockNumber)
        return 4;
    return normalizedValue % 3 + 1;
}

void ProgressBar::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
    unsigned short resulution = 3 + (aSize.Y - 2) * 3 + 2;
    unsigned short normalizedValue = min((int)(resulution * mValue / 95), (int)resulution);
    Serial.println(normalizedValue);
    Serial.println(resulution);
    aScreen->Picto({aPos.X, aPos.Y + aSize.Y - 1}, getPicto(1, fillNumber(0, normalizedValue)), aIsFocused);
    for (unsigned char i = 1; i < aSize.Y - 1; i++)
        aScreen->Picto({aPos.X, aPos.Y + aSize.Y - i - 1}, getPicto(2, fillNumber(i, normalizedValue)), aIsFocused);
    aScreen->Picto(aPos, getPicto(3, fillNumber(aSize.Y - 1, normalizedValue)), aIsFocused);
}
