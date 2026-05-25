// Tile64PagedScreen.h
#pragma once

#include "Coor.h"
#include "ScreenBase.h"

template <class TFont>
class Page8ScreenBase: public ScreenBase
{
public:
    void DrawSymbol(Coor aPosition, Coor aSize, char aSymbol, unsigned char aColor)
    {
        for (uint8_t col = 0; col < 8; col++)
        {
            uint8_t slice = TFont::getSlice(aSymbol, col);
            uint32_t scaledSlice = (aSize.Y > 1) ? upscale(slice, aSize.Y) : slice;
            uint8_t colno = aSize.X * col;

            for (int j = 0; j < aSize.Y; j++)
            {
                for (int k = 0; k < aSize.X; k++)
                {
                    DrawVerticalSlice({aPosition.X + (colno + k) / 8, aPosition.Y + j},
                                      (colno + k) % 8, scaledSlice & 0xff);
                }
                scaledSlice >>= 8;
            }
        }
    }

    void Picto(Coor aPosition, Coor aSize, uint8_t aPictoIndex, unsigned char aColor)
    {
        // заглушка
    }

    Coor Size() { return {16, 8}; }

protected:
    virtual void DrawVerticalSlice(Coor aPosition, unsigned char aColumn, unsigned char aSlice) = 0;

private:
    uint32_t upscale(uint8_t x, uint8_t scale)
    {
        uint32_t result = 0;
        uint32_t weight = 1;
        uint32_t multiplier = (1 << scale) - 1;

        for (uint8_t i = 0; i < 8; i++)
        {
            if (x & (1 << i))
                result += multiplier * weight;
            weight <<= scale;
        }
        return result;
    }
};
