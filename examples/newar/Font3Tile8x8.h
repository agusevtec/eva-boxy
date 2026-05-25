#pragma once

#include <Arduino.h>

class Font3Tile8x8
{
public:
    static uint8_t getSlice(char charIndex, uint8_t column);

private:
    static const uint8_t kCharmap[][8] PROGMEM;
};
