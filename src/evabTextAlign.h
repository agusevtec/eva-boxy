// evabTextAlign.h
#pragma once

#include <evabCoor.h>
#include <evabTextTraits.h>

namespace evab
{

    struct LeftAlign
    {
        static unsigned char Offset(Coor aSize, unsigned char textLen)
        {
            (void)aSize;
            (void)textLen;
            return 0;
        }
    };

    struct CenterAlign
    {
        static unsigned char Offset(Coor aSize, unsigned char textLen)
        {
            unsigned char scale = aSize.Y;
            unsigned char textWidth = textLen * scale;
            unsigned char areaWidth = aSize.X;

            unsigned char offset = (areaWidth - textWidth) / 2 / scale;
            return (offset > 0) ? offset : 0;
        }
    };

    struct RightAlign
    {
        static unsigned char Offset(Coor aSize, unsigned char textLen)
        {
            unsigned char scale = aSize.Y;
            unsigned char areaWidth = aSize.X;
            unsigned char maxSymbols = areaWidth / scale;

            unsigned char offset = maxSymbols - textLen;
            return (offset > 0) ? offset : 0;
        }
    };

}