#pragma once

#include <evabIFont.h>
#include <Arduino.h>

namespace evab
{
    class Font8Thin: public IFont
    {
    public:
         unsigned char GetVerticalSlice(char aCharcode, unsigned char aSliceColumn) const override;

    private:
        static const unsigned char kCharmap[][7] PROGMEM;
    };
}
