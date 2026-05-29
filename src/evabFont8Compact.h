#pragma once

#include <evabIFont.h>
#include <Arduino.h>

namespace evab
{
    class Font8Compact: public IFont
    {
    public:
        unsigned char GetVerticalSlice(char aCharcode, unsigned char aSliceColumn) const override;

    private:
        static const uint8_t kCharmap[][5] PROGMEM;
    };
}
