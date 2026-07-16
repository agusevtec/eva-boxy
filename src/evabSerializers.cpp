#include "evabSerializers.h"

using namespace evab;

unsigned short evab::serialize_16x8(const Coor &aPos, const Coor &aSize, bool isFocused)
{
    unsigned short serialized = 0;

    // Бит 0: isVisible
    if (aSize.X > 0 || aSize.Y > 0)
        serialized |= (1 << 0);

    // Бит 1: isFocused
    if (isFocused)
        serialized |= (1 << 1);

    // Биты 2-5: aPos.X (0..15) - 4 бита
    serialized |= ((aPos.X & 0x0F) << 2);

    // Биты 6-8: aPos.Y (0..7) - 3 бита
    serialized |= ((aPos.Y & 0x07) << 6);

    // Биты 9-12: aSize.X (1..16) -> храним как (value-1) для 0..15 - 4 бита
    serialized |= (((aSize.X - 1) & 0x0F) << 9);

    // Биты 13-15: aSize.Y (1..8) -> храним как (value-1) для 0..7 - 3 бита
    serialized |= (((aSize.Y - 1) & 0x07) << 13);
    return serialized;
}

void evab::deserialize_16x8(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
      // Бит 0
  if ((aSerialized >> 0) & 1)
  {
    // Биты 9-12 (прибавляем 1 обратно)
    aSize.X = ((aSerialized >> 9) & 0x0F) + 1;

    // Биты 13-15 (прибавляем 1 обратно)
    aSize.Y = ((aSerialized >> 13) & 0x07) + 1;
  }
  else
  {
    aSize.X = 0;
    aSize.Y = 0;
  }

  // Бит 1
  isFocused = (aSerialized >> 1) & 1;

  // Биты 2-5
  aPos.X = (aSerialized >> 2) & 0x0F;

  // Биты 6-8
  aPos.Y = (aSerialized >> 6) & 0x07;
}


unsigned short evab::serialize_32x4(const Coor &aPos, const Coor &aSize, bool isFocused)
{
  return 0;
}

void evab::deserialize_32x4(unsigned short aRaw, Coor &aPos, Coor &aSize, bool &isFocused)
{
}
