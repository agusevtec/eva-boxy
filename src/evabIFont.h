#pragma once

namespace evab
{
    class IFont
    {
    public:
        virtual unsigned char GetVerticalSlice(char aCharcode, unsigned char col) const = 0;
    };

}