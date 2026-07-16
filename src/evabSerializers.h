#pragma once
#include <evabCoor.h>

namespace evab
{
    unsigned short serialize_16x8(const Coor &aPos, const Coor &aSize, bool isFocused);
    void deserialize_16x8(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    unsigned short serialize_32x4(const Coor &aPos, const Coor &aSize, bool isFocused);
    void deserialize_32x4(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);
}
