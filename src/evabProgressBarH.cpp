#include <evabProgressBarH.h>

using namespace evab;
// 8x8 pictogram
const uint8_t picto_hprogress_11[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7e, 0xc3, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81};

// 8x8 pictogram
const uint8_t picto_hprogress_12[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7e, 0xc3, 0x99, 0xbd, 0xbd, 0x99, 0x81, 0x81};

// 8x8 pictogram
const uint8_t picto_hprogress_13[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7e, 0xc3, 0x99, 0xbd, 0xbd, 0xbd, 0xbd, 0x99};

// 8x8 pictogram
const uint8_t picto_hprogress_14[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x7e, 0xc3, 0x99, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd};

// 8x8 pictogram
const uint8_t picto_hprogress_20[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81};

// 8x8 pictogram
const uint8_t picto_hprogress_21[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xbd, 0x99, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81};

// 8x8 pictogram
const uint8_t picto_hprogress_22[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xbd, 0xbd, 0xbd, 0xbd, 0x99, 0x81, 0x81, 0x81};

// 8x8 pictogram
const uint8_t picto_hprogress_23[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0x99};

// 8x8 pictogram
const uint8_t picto_hprogress_24[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd};

// 8x8 pictogram
const uint8_t picto_hprogress_30[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xc3, 0x7e};

// 8x8 pictogram
const uint8_t picto_hprogress_31[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xbd, 0x99, 0x81, 0x81, 0x81, 0x81, 0xc3, 0x7e};

// 8x8 pictogram
const uint8_t picto_hprogress_32[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xbd, 0xbd, 0xbd, 0x99, 0x81, 0x81, 0xc3, 0x7e};

// 8x8 pictogram
const uint8_t picto_hprogress_33[] PROGMEM = {
    8, 8, // (8x8 пикселей)
    0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0x99, 0xc3, 0x7e};

static const unsigned char *getPicto(unsigned char blockType, unsigned char fillNumber)
{
    switch ((blockType << 4) | (fillNumber))
    {
    case 0x11:
        return picto_hprogress_11;
    case 0x12:
        return picto_hprogress_12;
    case 0x13:
        return picto_hprogress_13;
    case 0x14:
        return picto_hprogress_14;
    case 0x20:
        return picto_hprogress_20;
    case 0x21:
        return picto_hprogress_21;
    case 0x22:
        return picto_hprogress_22;
    case 0x23:
        return picto_hprogress_23;
    case 0x24:
        return picto_hprogress_24;
    case 0x30:
        return picto_hprogress_30;
    case 0x31:
        return picto_hprogress_31;
    case 0x32:
        return picto_hprogress_32;
    case 0x33:
        return picto_hprogress_33;
    }
    return nullptr;
}

ProgressBarH::ProgressBarH(unsigned char aValue)
    : mValue(aValue)
{
}

void ProgressBarH::SetValue(unsigned char aValue)
{
    mValue = aValue;
}

unsigned char evab::ProgressBarH::Resolution()
{
    return 0;
}

static char fillNumber(unsigned char blockNumber, unsigned char normalizedValue)
{
    if (normalizedValue / 3 < blockNumber)
        return 0;
    if (normalizedValue / 3 > blockNumber)
        return 4;
    return normalizedValue % 3 + 1;
}

void ProgressBarH::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
    unsigned short resulution = 3 + (aSize.X - 2) * 3 + 2;
    unsigned short normalizedValue = min((int)(resulution * mValue / 95), (int)resulution);
    Serial.println(normalizedValue);
    Serial.println(resulution);
    aScreen->Picto({aPos.X, aPos.Y}, getPicto(1, fillNumber(0, normalizedValue)), aIsFocused);
    for (unsigned char i = 1; i < aSize.X - 1; i++)
        aScreen->Picto({aPos.X + i, aPos.Y}, getPicto(2, fillNumber(i, normalizedValue)), aIsFocused);
    aScreen->Picto({aPos.X + aSize.X - 1, aPos.Y}, getPicto(3, fillNumber(aSize.X - 1, normalizedValue)), aIsFocused);
}
