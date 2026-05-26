#pragma once

#include <Arduino.h>

class Font8Thin
{
public:
    static uint8_t getSlice(char charIndex, uint8_t column);

private:
    static const uint8_t kCharmap[][7] PROGMEM;
};
