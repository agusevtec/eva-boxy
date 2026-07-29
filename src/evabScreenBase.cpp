// evabScreenBase.cpp
#include <evabScreenBase.h>
#include <string.h>

using namespace evab;

unsigned char ScreenBase::calcLeftOffset(Coor aSize, unsigned char textLen)
{
    return 0;
}

unsigned char ScreenBase::calcCenterOffset(Coor aSize, unsigned char textLen)
{
    unsigned char scale = aSize.Y;
    unsigned char textWidth = textLen * scale;
    unsigned char areaWidth = aSize.X;

    int16_t offset = (areaWidth - textWidth) / 2 / scale;
    return (offset > 0) ? offset : 0;
}

unsigned char ScreenBase::calcRightOffset(Coor aSize, unsigned char textLen)
{
    unsigned char scale = aSize.Y;
    unsigned char areaWidth = aSize.X;
    unsigned char maxSymbols = areaWidth / scale;

    int16_t offset = maxSymbols - textLen;
    return (offset > 0) ? offset : 0;
}

void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                          const char *aText, unsigned char aColor)
{
    if (!aText)
        return;
    unsigned char textLen = strlen(aText);
    unsigned char offset = calcLeftOffset(aSize, textLen);
    printTextInArea(aPosition, aSize, aText, aColor, offset);
}

void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                            const char *aText, unsigned char aColor)
{
    if (!aText)
        return;
    unsigned char textLen = strlen(aText);
    unsigned char offset = calcCenterOffset(aSize, textLen);
    printTextInArea(aPosition, aSize, aText, aColor, offset);
}

void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                           const char *aText, unsigned char aColor)
{
    if (!aText)
        return;
    unsigned char textLen = strlen(aText);
    unsigned char offset = calcRightOffset(aSize, textLen);
    printTextInArea(aPosition, aSize, aText, aColor, offset);
}

void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                          const __FlashStringHelper *aText, unsigned char aColor)
{
    if (!aText)
        return;
    unsigned char textLen = TextTraits<const __FlashStringHelper*>::Length(aText);
    unsigned char offset = calcLeftOffset(aSize, textLen);
    printTextInArea(aPosition, aSize, aText, aColor, offset);
}

void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                            const __FlashStringHelper *aText, unsigned char aColor)
{
    if (!aText)
        return;
    unsigned char textLen = TextTraits<const __FlashStringHelper*>::Length(aText);
    unsigned char offset = calcCenterOffset(aSize, textLen);
    printTextInArea(aPosition, aSize, aText, aColor, offset);
}

void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                           const __FlashStringHelper *aText, unsigned char aColor)
{
    if (!aText)
        return;
    unsigned char textLen = TextTraits<const __FlashStringHelper*>::Length(aText);
    unsigned char offset = calcRightOffset(aSize, textLen);
    printTextInArea(aPosition, aSize, aText, aColor, offset);
}

void ScreenBase::ClearTile(Coor aPosition, unsigned char aColor)
{
    DrawSymbol(aPosition, Coor(1, 1), ' ', aColor);
}

void ScreenBase::Picto(Coor aPosition, const unsigned char *aPictogramm, unsigned char aColor)
{
    // Default implementation - can be overridden
}

void ScreenBase::Clear(Coor aPosition, Coor aSize, unsigned char aColor)
{
    Coor displaySize = Size();
    for (unsigned char x = 0; x < aSize.X; x++)
    {
        for (unsigned char y = 0; y < aSize.Y; y++)
        {
            Coor clearPos(aPosition.X + x, aPosition.Y + y);
            if (clearPos.X < displaySize.X && clearPos.Y < displaySize.Y)
                ClearTile(clearPos, aColor);
        }
    }
}