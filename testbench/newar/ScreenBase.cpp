#include "..\..\src\evabScreenBase.h"
#include <string.h>

// ========== Вспомогательные методы для F-строк ==========
uint8_t ScreenBase::flashStrLen(const __FlashStringHelper *str)
{
  return strlen_P((const char *)str);
}

char ScreenBase::flashStrRead(const __FlashStringHelper *str, uint8_t index)
{
  return pgm_read_byte((const char *)str + index);
}

// ========== Универсальные методы расчёта смещения ==========
uint8_t ScreenBase::calcLeftOffset(Coor aSize, uint8_t textLen)
{
  (void)aSize;   // Не используется для левого выравнивания
  (void)textLen; // Не используется для левого выравнивания
  return 0;
}

uint8_t ScreenBase::calcCenterOffset(Coor aSize, uint8_t textLen)
{
  uint8_t scale = aSize.Y;
  uint8_t textWidth = textLen * scale;
  uint8_t areaWidth = aSize.X;

  int16_t offset = (areaWidth - textWidth) / 2 / scale;
  return (offset > 0) ? offset : 0;
}

uint8_t ScreenBase::calcRightOffset(Coor aSize, uint8_t textLen)
{
  uint8_t scale = aSize.Y;
  uint8_t areaWidth = aSize.X;
  uint8_t maxSymbols = areaWidth / scale;

  int16_t offset = maxSymbols - textLen;
  return (offset > 0) ? offset : 0;
}

// ========== Базовый метод для обычных строк ==========
void ScreenBase::printTextInArea(Coor aPosition, Coor aSize, const char *text,
                                     unsigned char aColor, uint8_t offset)
{
  Coor displaySize = Size();
  uint8_t scale = aSize.Y;
  uint8_t maxSymbols = min(aSize.X, displaySize.X - aPosition.X) / scale;
  uint8_t textLen = strlen(text);

  for (uint8_t i = 0; i < maxSymbols; i++)
  {
    Coor symbolPos(aPosition.X + i * scale, aPosition.Y);
    uint8_t textIndex = i - offset;
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

// ========== Базовый метод для F-строк ==========
void ScreenBase::printTextInArea(Coor aPosition, Coor aSize, const __FlashStringHelper *text,
                                     unsigned char aColor, uint8_t offset)
{
  Coor displaySize = Size();
  uint8_t scale = aSize.Y;
  uint8_t maxSymbols = min(aSize.X, displaySize.X - aPosition.X) / scale;
  uint8_t textLen = flashStrLen(text);

  for (uint8_t i = 0; i < maxSymbols; i++)
  {
    Coor symbolPos(aPosition.X + i * scale, aPosition.Y);
    uint8_t textIndex = i - offset;
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

// ========== Публичные методы для обычных строк ==========
void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                              const char *text, unsigned char aColor)
{
  uint8_t textLen = strlen(text);
  uint8_t offset = calcLeftOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                                const char *text, unsigned char aColor)
{
  uint8_t textLen = strlen(text);
  uint8_t offset = calcCenterOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                               const char *text, unsigned char aColor)
{
  uint8_t textLen = strlen(text);
  uint8_t offset = calcRightOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

// ========== Публичные методы для F-строк ==========
void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                              const __FlashStringHelper *text, unsigned char aColor)
{
  uint8_t textLen = flashStrLen(text);
  uint8_t offset = calcLeftOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                                const __FlashStringHelper *text, unsigned char aColor)
{
  uint8_t textLen = flashStrLen(text);
  uint8_t offset = calcCenterOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                               const __FlashStringHelper *text, unsigned char aColor)
{
  uint8_t textLen = flashStrLen(text);
  uint8_t offset = calcRightOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

void ScreenBase::ClearTile(Coor aPosition)
{
  DrawSymbol(aPosition, Coor(1, 1), ' ', 0);
}

// ========== Clear ==========
void ScreenBase::Clear(Coor aPosition, Coor aSize)
{
  Coor displaySize = Size();
  for (uint8_t x = 0; x < aSize.X; x++)
  {
    for (uint8_t y = 0; y < aSize.Y; y++)
    {
      Coor clearPos(aPosition.X + x, aPosition.Y + y);
      if (clearPos.X < displaySize.X && clearPos.Y < displaySize.Y)
      {
        ClearTile(clearPos);
      }
    }
  }
}