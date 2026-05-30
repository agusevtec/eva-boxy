#include <evabPage8ScreenBase.h>
#include <Arduino.h>

namespace evab
{

  Page8ScreenBase::Page8ScreenBase(const IFont* font)
    : mFont(font)
  {
  }

  void Page8ScreenBase::DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor)
  {
    for (uint8_t col = 0; col < 8; col++)
    {
      uint8_t slice = mFont->GetVerticalSlice(aCharcode, col);
      if (aColor == 1)
        slice = ~slice;
      uint32_t scaledSlice = (aSize.Y > 1) ? upscaleY(slice, aSize.Y) : slice;
      uint8_t colno = aSize.X * col;

      for (int j = 0; j < aSize.Y; j++)
      {
        for (int k = 0; k < aSize.X; k++)
        {
          DrawVerticalSlice({aPosition.X + (colno + k) / 8, aPosition.Y + j}, (colno + k) % 8, scaledSlice & 0xff);
        }
        scaledSlice >>= 8;
      }
    }
  }

  void Page8ScreenBase::Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor)
  {
    uint8_t tilesW = pgm_read_byte(pictoData + 0) / 8; // ширина в тайлах
    uint8_t tilesH = pgm_read_byte(pictoData + 1) / 8; // высота в тайлах
    int j = 2;
    for (uint8_t tileY = 0; tileY < tilesH; tileY++)
    {
      for (uint8_t tileX = 0; tileX < tilesW; tileX++)
      {
        for (uint8_t col = 0; col < 8; col++)
        {
          uint8_t slice = pgm_read_byte(&pictoData[j++]);
          if (aColor == 1)
            slice = ~slice;
          DrawVerticalSlice({aPosition.X + tileX, aPosition.Y + tileY}, col, slice);
        }
      }
    }
  }

  uint32_t Page8ScreenBase::upscaleY(uint8_t x, uint8_t scale)
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

}