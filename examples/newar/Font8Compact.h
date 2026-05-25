#pragma once

#include <Arduino.h>

class Font8Compact
{
public:
    static uint8_t getSlice(char charIndex, uint8_t column);

private:
    static const uint8_t kCharmap[][5] PROGMEM;
};
