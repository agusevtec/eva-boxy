#include "evabTextAlign.h"

using namespace evab;

unsigned char LeftAlign::Offset(Coor aSize, unsigned char textLen)
{
    (void)aSize;
    (void)textLen;
    return 0;
}

unsigned char CenterAlign::Offset(Coor aSize, unsigned char textLen)
{
    unsigned char scale = aSize.Y;
    unsigned char textWidth = textLen * scale;
    unsigned char areaWidth = aSize.X;

    unsigned char offset = (areaWidth - textWidth) / 2 / scale;
    return (offset > 0) ? offset : 0;
}

unsigned char RightAlign::Offset(Coor aSize, unsigned char textLen)
{
    unsigned char scale = aSize.Y;
    unsigned char areaWidth = aSize.X;
    unsigned char maxSymbols = areaWidth / scale;

    unsigned char offset = maxSymbols - textLen;
    return (offset > 0) ? offset : 0;
}
