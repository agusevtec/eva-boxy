#pragma once

#include <Arduino.h>

namespace evab
{
    class Font8Compact
    {
    public:
        static uint8_t GetVerticalSlice(char aCharcode, uint8_t aSliceColumn);

    private:
        static const uint8_t kCharmap[][5] PROGMEM;
    };
}
