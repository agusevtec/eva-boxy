#pragma once

#include <Arduino.h>

class Font8Compact
{
public:
    static uint8_t GetVerticalSlice(char aCharcode, uint8_t aSliceColumn);

private:
    static const uint8_t kCharmap[][5] PROGMEM;
};
