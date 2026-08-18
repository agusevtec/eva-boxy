#include <evabScreen.h>

using namespace evab;

void Screen::clearTile(Coor aPosition, unsigned char aColor)
{
    DrawSymbol(aPosition, Coor(1, 1), ' ', 0);
}

void Screen::Picto(Coor aPosition, const unsigned char *aPictogram, unsigned char aColor)
{
}

void Screen::Clear(Coor aPosition, Coor aSize, unsigned char aColor)
{
    Coor displaySize = Size();
    for (unsigned char x = 0; x < aSize.X; x++)
    {
        for (unsigned char y = 0; y < aSize.Y; y++)
        {
            Coor clearPos(aPosition.X + x, aPosition.Y + y);
            if (clearPos.X < displaySize.X && clearPos.Y < displaySize.Y)
                clearTile(clearPos, aColor);
        }
    }
}