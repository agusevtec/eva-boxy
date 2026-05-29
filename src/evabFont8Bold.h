#pragma once

#include <Arduino.h>
#include <evabIFont.h>

namespace evab
{
    class Font8Bold: public IFont
    {
    public:
        unsigned char GetVerticalSlice(char aCharcode, unsigned char col) const override;

    private:
        static const unsigned char kCharmap[][8] PROGMEM;
    };
}
