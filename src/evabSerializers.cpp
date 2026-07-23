#include "evabSerializers.h"

using namespace evab;

unsigned short evab::serialize_16x8(const Coor &aPos, const Coor &aSize, bool isFocused)
{
    unsigned short serialized = 0;

    // Bit 0: isVisible
    if (aSize.X > 0 || aSize.Y > 0)
        serialized |= (1 << 0);

    // Bit 1: isFocused
    if (isFocused)
        serialized |= (1 << 1);

    // Bits 2-5: aPos.X (0..15) - 4 bits
    serialized |= ((aPos.X & 0x0F) << 2);

    // Bits 6-8: aPos.Y (0..7) - 3 bits
    serialized |= ((aPos.Y & 0x07) << 6);

    // Bits 9-12: aSize.X (1..16) -> store as (value-1) for 0..15 - 4 bits
    serialized |= (((aSize.X - 1) & 0x0F) << 9);

    // Bits 13-15: aSize.Y (1..8) -> store as (value-1) for 0..7 - 3 bits
    serialized |= (((aSize.Y - 1) & 0x07) << 13);
    return serialized;
}

void evab::deserialize_16x8(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
    // Bit 0
    if ((aSerialized >> 0) & 1)
    {
        // Bits 9-12 (add 1 back)
        aSize.X = ((aSerialized >> 9) & 0x0F) + 1;

        // Bits 13-15 (add 1 back)
        aSize.Y = ((aSerialized >> 13) & 0x07) + 1;
    }
    else
    {
        aSize.X = 0;
        aSize.Y = 0;
    }

    // Bit 1
    isFocused = (aSerialized >> 1) & 1;

    // Bits 2-5
    aPos.X = (aSerialized >> 2) & 0x0F;

    // Bits 6-8
    aPos.Y = (aSerialized >> 6) & 0x07;
}


unsigned short evab::serialize_32x4(const Coor &aPos, const Coor &aSize, bool isFocused)
{
    unsigned short serialized = 0;

    // Bit 0: Visibility (if size > 0)
    if (aSize.X > 0 && aSize.Y > 0) {
        serialized |= (1 << 0);
    }

    // Bit 1: Focus
    if (isFocused) {
        serialized |= (1 << 1);
    }

    // Bits 2-6: X position (0..31) - 5 bits
    serialized |= ((aPos.X & 0x1F) << 2);  // 0x1F = 31 (max value)

    // Bits 7-8: Y position (0..3) - 2 bits
    serialized |= ((aPos.Y & 0x03) << 7);  // 0x03 = 3 (max value)

    // Bits 9-13: X size (1..32) -> store as (value-1) for 0..31 - 5 bits
    if (aSize.X > 0 && aSize.X <= 32) {
        serialized |= (((aSize.X - 1) & 0x1F) << 9);
    }

    // Bits 14-15: Y size (1..4) -> store as (value-1) for 0..3 - 2 bits
    if (aSize.Y > 0 && aSize.Y <= 4) {
        serialized |= (((aSize.Y - 1) & 0x03) << 14);
    }

    return serialized;
}

void evab::deserialize_32x4(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
    // Bit 0: Visibility
    bool isVisible = (aSerialized >> 0) & 1;
    
    if (isVisible) {
        // Bits 9-13: X size (add 1 back)
        aSize.X = ((aSerialized >> 9) & 0x1F) + 1;
        
        // Bits 14-15: Y size (add 1 back)
        aSize.Y = ((aSerialized >> 14) & 0x03) + 1;
        
        // Validate values
        if (aSize.X > 32) aSize.X = 32;
        if (aSize.Y > 4) aSize.Y = 4;
    } else {
        aSize.X = 0;
        aSize.Y = 0;
    }

    // Bit 1: Focus
    isFocused = (aSerialized >> 1) & 1;

    // Bits 2-6: X position (0..31)
    aPos.X = (aSerialized >> 2) & 0x1F;
    if (aPos.X > 31) aPos.X = 31;  // Overflow protection

    // Bits 7-8: Y position (0..3)
    aPos.Y = (aSerialized >> 7) & 0x03;
    if (aPos.Y > 3) aPos.Y = 3;    // Overflow protection
}