#pragma once

#include <Arduino.h>

class Font8Bold
{
public:
    static uint8_t GetVerticalSlice(char aCharcode, uint8_t aSliceColumn);

private:
    static const uint8_t kCharmap[][8] PROGMEM;
};
