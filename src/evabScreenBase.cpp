#include <evabScreenBase.h>
#include <string.h>
using namespace evab;

unsigned char ScreenBase::flashStrLen(const __FlashStringHelper *str)
{
  return strlen_P((const char *)str);
}

char ScreenBase::flashStrRead(const __FlashStringHelper *str, unsigned char index)
{
  return pgm_read_byte((const char *)str + index);
}

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

// ========== Базовый метод для обычных строк ==========
void ScreenBase::printTextInArea(Coor aPosition, Coor aSize, const char *text,
                                     unsigned char aColor, unsigned char offset)
{
  Coor displaySize = Size();
  unsigned char scale = aSize.Y;
  unsigned char maxSymbols = min((int)aSize.X, (int)(displaySize.X - aPosition.X)) / scale;
  unsigned char textLen = strlen(text);

  for (unsigned char i = 0; i < maxSymbols; i++)
  {
    Coor symbolPos(aPosition.X + i * scale, aPosition.Y);
    unsigned char textIndex = i - offset;
    if (textIndex < textLen)
    {
      DrawSymbol(symbolPos, Coor(scale, scale), text[textIndex], aColor);
    }
    else
    {
      DrawSymbol(symbolPos, Coor(scale, scale), ' ', aColor);
    }
  }
}

void ScreenBase::printTextInArea(Coor aPosition, Coor aSize, const __FlashStringHelper *text,
                                     unsigned char aColor, unsigned char offset)
{
  Coor displaySize = Size();
  unsigned char scale = aSize.Y;
  unsigned char maxSymbols = min((int)aSize.X, (int)(displaySize.X - aPosition.X)) / scale;
  unsigned char textLen = flashStrLen(text);

  for (unsigned char i = 0; i < maxSymbols; i++)
  {
    Coor symbolPos(aPosition.X + i * scale, aPosition.Y);
    unsigned char textIndex = i - offset;
    if (textIndex < textLen)
    {
      char symbol = flashStrRead(text, textIndex);
      DrawSymbol(symbolPos, Coor(scale, scale), symbol, aColor);
    }
    else
    {
      DrawSymbol(symbolPos, Coor(scale, scale), ' ', aColor);
    }
  }
}

void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                              const char *text, unsigned char aColor)
{
  unsigned char textLen = strlen(text);
  unsigned char offset = calcLeftOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                                const char *text, unsigned char aColor)
{
  unsigned char textLen = strlen(text);
  unsigned char offset = calcCenterOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                               const char *text, unsigned char aColor)
{
  unsigned char textLen = strlen(text);
  unsigned char offset = calcRightOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

// ========== Публичные методы для F-строк ==========
void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                              const __FlashStringHelper *text, unsigned char aColor)
{
  unsigned char textLen = flashStrLen(text);
  unsigned char offset = calcLeftOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                                const __FlashStringHelper *text, unsigned char aColor)
{
  unsigned char textLen = flashStrLen(text);
  unsigned char offset = calcCenterOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                               const __FlashStringHelper *text, unsigned char aColor)
{
  unsigned char textLen = flashStrLen(text);
  unsigned char offset = calcRightOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::ClearTile(Coor aPosition, unsigned char aColor)
{
  DrawSymbol(aPosition, Coor(1, 1), ' ', 0);
}

void evab::ScreenBase::Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor)
{
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
      {
        ClearTile(clearPos, aColor);
      }
    }
  }
}