#pragma once

#include <Arduino.h>

class Font2Tile8x8
{
public:
    static uint8_t getSlice(char charIndex, uint8_t column);

private:
    static const uint8_t kCharmap[][7] PROGMEM;
};
