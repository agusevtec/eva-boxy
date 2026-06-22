#include <evabTilesetsStretchy.h>

const uint8_t *evab::TilesetVerticalProgressBar::GetTile(unsigned char blockType, unsigned char fillNumber)
{

    const static uint8_t picto_11[] PROGMEM = {
        8, 8,
        0x7f, 0xc0, 0x80, 0x80, 0x80, 0x80, 0xc0, 0x7f};
    const static uint8_t picto_12[] PROGMEM = {
        8, 8,
        0x7f, 0xc0, 0x98, 0xbc, 0xbc, 0x98, 0xc0, 0x7f};
    const static uint8_t picto_13[] PROGMEM = {
        8, 8,
        0x7f, 0xc0, 0x9e, 0xbf, 0xbf, 0x9e, 0xc0, 0x7f};
    const static uint8_t picto_14[] PROGMEM = {
        8, 8,
        0x7f, 0xc0, 0x9f, 0xbf, 0xbf, 0x9f, 0xc0, 0x7f};
    const static uint8_t picto_20[] PROGMEM = {
        8, 8,
        0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff};
    const static uint8_t picto_21[] PROGMEM = {
        8, 8,
        0xff, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0xff};
    const static uint8_t picto_22[] PROGMEM = {
        8, 8,
        0xff, 0x00, 0xf0, 0xf8, 0xf8, 0xf0, 0x00, 0xff};
    const static uint8_t picto_23[] PROGMEM = {
        8, 8,
        0xff, 0x00, 0xfe, 0xff, 0xff, 0xfe, 0x00, 0xff};
    const static uint8_t picto_24[] PROGMEM = {
        8, 8,
        0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff};
    const static uint8_t picto_30[] PROGMEM = {
        8, 8,
        0xfe, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0xfe};
    const static uint8_t picto_31[] PROGMEM = {
        8, 8,
        0xfe, 0x03, 0x81, 0xc1, 0xc1, 0x81, 0x03, 0xfe};
    const static uint8_t picto_32[] PROGMEM = {
        8, 8,
        0xfe, 0x03, 0xe1, 0xf1, 0xf1, 0xe1, 0x03, 0xfe};
    const static uint8_t picto_33[] PROGMEM = {
        8, 8,
        0xfe, 0x03, 0xf9, 0xfd, 0xfd, 0xf9, 0x03, 0xfe};

    switch ((blockType << 4) | fillNumber)
    {
    case 0x11:
        return picto_11;
    case 0x12:
        return picto_12;
    case 0x13:
        return picto_13;
    case 0x14:
        return picto_14;
    case 0x20:
        return picto_20;
    case 0x21:
        return picto_21;
    case 0x22:
        return picto_22;
    case 0x23:
        return picto_23;
    case 0x24:
        return picto_24;
    case 0x30:
        return picto_30;
    case 0x31:
        return picto_31;
    case 0x32:
        return picto_32;
    case 0x33:
        return picto_33;
    }
    return nullptr;
}

const uint8_t *evab::TilesetHorizontalProgressBar::GetTile(unsigned char blockType, unsigned char fillNumber)
{
    const static uint8_t picto_11[] PROGMEM = {
        8, 8,
        0x7e, 0xc3, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81};
    const static uint8_t picto_12[] PROGMEM = {
        8, 8,
        0x7e, 0xc3, 0x99, 0xbd, 0xbd, 0x99, 0x81, 0x81};
    const static uint8_t picto_13[] PROGMEM = {
        8, 8,
        0x7e, 0xc3, 0x99, 0xbd, 0xbd, 0xbd, 0xbd, 0x99};
    const static uint8_t picto_14[] PROGMEM = {
        8, 8,
        0x7e, 0xc3, 0x99, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd};
    const static uint8_t picto_20[] PROGMEM = {
        8, 8,
        0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81};
    const static uint8_t picto_21[] PROGMEM = {
        8, 8,
        0xbd, 0x99, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81};
    const static uint8_t picto_22[] PROGMEM = {
        8, 8,
        0xbd, 0xbd, 0xbd, 0xbd, 0x99, 0x81, 0x81, 0x81};
    const static uint8_t picto_23[] PROGMEM = {
        8, 8,
        0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0x99};
    const static uint8_t picto_24[] PROGMEM = {
        8, 8,
        0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd};
    const static uint8_t picto_30[] PROGMEM = {
        8, 8,
        0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xc3, 0x7e};
    const static uint8_t picto_31[] PROGMEM = {
        8, 8,
        0xbd, 0x99, 0x81, 0x81, 0x81, 0x81, 0xc3, 0x7e};
    const static uint8_t picto_32[] PROGMEM = {
        8, 8,
        0xbd, 0xbd, 0xbd, 0x99, 0x81, 0x81, 0xc3, 0x7e};
    const static uint8_t picto_33[] PROGMEM = {
        8, 8,
        0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0x99, 0xc3, 0x7e};

    switch ((blockType << 4) | (fillNumber))
    {
    case 0x11:
        return picto_11;
    case 0x12:
        return picto_12;
    case 0x13:
        return picto_13;
    case 0x14:
        return picto_14;
    case 0x20:
        return picto_20;
    case 0x21:
        return picto_21;
    case 0x22:
        return picto_22;
    case 0x23:
        return picto_23;
    case 0x24:
        return picto_24;
    case 0x30:
        return picto_30;
    case 0x31:
        return picto_31;
    case 0x32:
        return picto_32;
    case 0x33:
        return picto_33;
    }
    return nullptr;
}

const uint8_t *evab::TilesetVerticalScrollBar::GetTile(unsigned char blockType, unsigned char fillNumber)
{
    static const uint8_t picto_10[] PROGMEM = {
        8, 8,  // 8x8
        0x7f, 0xc0, 0x80, 0x80, 0x80, 0x80, 0xc0, 0x7f
    };

    static const uint8_t picto_11[] PROGMEM = {
        8, 8,  // 8x8
        0x7f, 0xc0, 0xb0, 0xb0, 0xb0, 0xb0, 0xc0, 0x7f
    };

    static const uint8_t picto_12[] PROGMEM = {
        8, 8,  // 8x8
        0x7f, 0xc0, 0x8c, 0x8c, 0x8c, 0x8c, 0xc0, 0x7f
    };

    static const uint8_t picto_13[] PROGMEM = {
        8, 8,  // 8x8
        0x7f, 0xc0, 0x83, 0x83, 0x83, 0x83, 0xc0, 0x7f
    };

    static const uint8_t picto_14[] PROGMEM = {
        8, 8,  // 8x8
        0x7f, 0xc0, 0x80, 0x80, 0x80, 0x80, 0xc0, 0x7f
    };

    static const uint8_t picto_20[] PROGMEM = {
        8, 8,  // 8x8
        0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff
    };

    static const uint8_t picto_21[] PROGMEM = {
        8, 8,  // 8x8
        0xff, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0xff
    };

    static const uint8_t picto_22[] PROGMEM = {
        8, 8,  // 8x8
        0xff, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0xff
    };

    static const uint8_t picto_23[] PROGMEM = {
        8, 8,  // 8x8
        0xff, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0xff
    };

    static const uint8_t picto_24[] PROGMEM = {
        8, 8,  // 8x8
        0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff
    };

    static const uint8_t picto_30[] PROGMEM = {
        8, 8,  // 8x8
        0xfe, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0xfe
    };

    static const uint8_t picto_31[] PROGMEM = {
        8, 8,  // 8x8
        0xfe, 0x03, 0xc1, 0xc1, 0xc1, 0xc1, 0x03, 0xfe
    };

    static const uint8_t picto_32[] PROGMEM = {
        8, 8,  // 8x8
        0xfe, 0x03, 0x31, 0x31, 0x31, 0x31, 0x03, 0xfe
    };

    static const uint8_t picto_33[] PROGMEM = {
        8, 8,  // 8x8
        0xfe, 0x03, 0x0d, 0x0d, 0x0d, 0x0d, 0x03, 0xfe
    };
    switch ((blockType << 4) | (fillNumber))
    {
    case 0x11:
        return picto_11;
    case 0x12:
        return picto_12;
    case 0x13:
        return picto_13;
    case 0x14:
        return picto_14;
    case 0x20:
        return picto_20;
    case 0x21:
        return picto_21;
    case 0x22:
        return picto_22;
    case 0x23:
        return picto_23;
    case 0x24:
        return picto_24;
    case 0x30:
        return picto_30;
    case 0x31:
        return picto_31;
    case 0x32:
        return picto_32;
    case 0x33:
        return picto_33;
    }
    return nullptr;
}

const uint8_t *evab::TilesetHorizontalScrollBar::GetTile(unsigned char blockType, unsigned char fillNumber)
{
    static const uint8_t picto_10[] PROGMEM = {
        8, 8,  // 8x8
        0x7e, 0xc3, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81
    };

    static const uint8_t picto_11[] PROGMEM = {
        8, 8,  // 8x8
        0x7e, 0xc3, 0xbd, 0xbd, 0x81, 0x81, 0x81, 0x81
    };

    static const uint8_t picto_12[] PROGMEM = {
        8, 8,  // 8x8
        0x7e, 0xc3, 0x81, 0x81, 0xbd, 0xbd, 0x81, 0x81
    };

    static const uint8_t picto_13[] PROGMEM = {
        8, 8,  // 8x8
        0x7e, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xbd, 0xbd
    };

    static const uint8_t picto_14[] PROGMEM = {
        8, 8,  // 8x8
        0x7e, 0xc3, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81
    };

    static const uint8_t picto_20[] PROGMEM = {
        8, 8,  // 8x8
        0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81
    };

    static const uint8_t picto_21[] PROGMEM = {
        8, 8,  // 8x8
        0xbd, 0xbd, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81
    };

    static const uint8_t picto_22[] PROGMEM = {
        8, 8,  // 8x8
        0x81, 0x81, 0x81, 0xbd, 0xbd, 0x81, 0x81, 0x81
    };

    static const uint8_t picto_23[] PROGMEM = {
        8, 8,  // 8x8
        0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xbd, 0xbd
    };

    static const uint8_t picto_24[] PROGMEM = {
        8, 8,  // 8x8
        0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81
    };

    static const uint8_t picto_30[] PROGMEM = {
        8, 8,  // 8x8
        0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xc3, 0x7e
    };

    static const uint8_t picto_31[] PROGMEM = {
        8, 8,  // 8x8
        0xbd, 0xbd, 0x81, 0x81, 0x81, 0x81, 0xc3, 0x7e
    };

    static const uint8_t picto_32[] PROGMEM = {
        8, 8,  // 8x8
        0x81, 0x81, 0xbd, 0xbd, 0x81, 0x81, 0xc3, 0x7e
    };

    static const uint8_t picto_33[] PROGMEM = {
        8, 8,  // 8x8
        0x81, 0x81, 0x81, 0x81, 0xbd, 0xbd, 0xc3, 0x7e
    };
    switch ((blockType << 4) | (fillNumber))
    {
    case 0x11:
        return picto_11;
    case 0x12:
        return picto_12;
    case 0x13:
        return picto_13;
    case 0x14:
        return picto_14;
    case 0x20:
        return picto_20;
    case 0x21:
        return picto_21;
    case 0x22:
        return picto_22;
    case 0x23:
        return picto_23;
    case 0x24:
        return picto_24;
    case 0x30:
        return picto_30;
    case 0x31:
        return picto_31;
    case 0x32:
        return picto_32;
    case 0x33:
        return picto_33;
    }
    return nullptr;
}
