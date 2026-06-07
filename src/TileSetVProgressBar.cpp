#include <TileSetVProgressBar.h>

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


const uint8_t *evab::TileSetVProgressBar::GetTile(unsigned char blockType, unsigned char fillNumber)
        {
            switch ((blockType << 4) | fillNumber)
            {
                case 0x11: return picto_progress_11;
                case 0x12: return picto_progress_12;
                case 0x13: return picto_progress_13;
                case 0x14: return picto_progress_14;
                case 0x20: return picto_progress_20;
                case 0x21: return picto_progress_21;
                case 0x22: return picto_progress_22;
                case 0x23: return picto_progress_23;
                case 0x24: return picto_progress_24;
                case 0x30: return picto_progress_30;
                case 0x31: return picto_progress_31;
                case 0x32: return picto_progress_32;
                case 0x33: return picto_progress_33;
            }
            return nullptr;
        }