#include <evabScreenBase.h>
#include <string.h>
using namespace evab;

/**
 * @brief Gets the length of a flash string stored in PROGMEM
 * 
 * @param str Pointer to flash string
 * @return Length of the string in bytes
 */
uint8_t ScreenBase::flashStrLen(const __FlashStringHelper *str)
{
  return strlen_P((const char *)str);
}

/**
 * @brief Reads a character from a flash string at the specified index
 * 
 * @param str Pointer to flash string
 * @param index Character position to read
 * @return Character at the specified position
 */
char ScreenBase::flashStrRead(const __FlashStringHelper *str, uint8_t index)
{
  return pgm_read_byte((const char *)str + index);
}

/**
 * @brief Calculates offset for left-aligned text
 * 
 * @param aSize Size of the text area
 * @param textLen Length of the text to display
 * @return Offset value (always 0 for left alignment)
 */
uint8_t ScreenBase::calcLeftOffset(Coor aSize, uint8_t textLen)
{
  (void)aSize;
  (void)textLen;
  return 0;
}

/**
 * @brief Calculates offset for center-aligned text
 * 
 * @param aSize Size of the text area
 * @param textLen Length of the text to display
 * @return Offset value for centering
 */
uint8_t ScreenBase::calcCenterOffset(Coor aSize, uint8_t textLen)
{
  uint8_t scale = aSize.Y;
  uint8_t textWidth = textLen * scale;
  uint8_t areaWidth = aSize.X;

  int16_t offset = (areaWidth - textWidth) / 2 / scale;
  return (offset > 0) ? offset : 0;
}

/**
 * @brief Calculates offset for right-aligned text
 * 
 * @param aSize Size of the text area
 * @param textLen Length of the text to display
 * @return Offset value for right alignment
 */
uint8_t ScreenBase::calcRightOffset(Coor aSize, uint8_t textLen)
{
  uint8_t scale = aSize.Y;
  uint8_t areaWidth = aSize.X;
  uint8_t maxSymbols = areaWidth / scale;

  int16_t offset = maxSymbols - textLen;
  return (offset > 0) ? offset : 0;
}

/**
 * @brief Prints text in the specified area with offset (C-string version)
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Null-terminated C-string
 * @param aColor Color/inversion flag
 * @param offset Character offset from the left edge
 */
void ScreenBase::printTextInArea(Coor aPosition, Coor aSize, const char *text,
                                     unsigned char aColor, uint8_t offset)
{
  Coor displaySize = Size();
  uint8_t scale = aSize.Y;
  uint8_t maxSymbols = min((int)aSize.X, (int)(displaySize.X - aPosition.X)) / scale;
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

/**
 * @brief Prints text in the specified area with offset (Flash string version)
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Flash string stored in PROGMEM
 * @param aColor Color/inversion flag
 * @param offset Character offset from the left edge
 */
void ScreenBase::printTextInArea(Coor aPosition, Coor aSize, const __FlashStringHelper *text,
                                     unsigned char aColor, uint8_t offset)
{
  Coor displaySize = Size();
  uint8_t scale = aSize.Y;
  uint8_t maxSymbols = min((int)aSize.X, (int)(displaySize.X - aPosition.X)) / scale;
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

/**
 * @brief Draws left-aligned text from a C-string
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Null-terminated C-string
 * @param aColor Color/inversion flag
 */
void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                              const char *text, unsigned char aColor)
{
  uint8_t textLen = strlen(text);
  uint8_t offset = calcLeftOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

/**
 * @brief Draws center-aligned text from a C-string
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Null-terminated C-string
 * @param aColor Color/inversion flag
 */
void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                                const char *text, unsigned char aColor)
{
  uint8_t textLen = strlen(text);
  uint8_t offset = calcCenterOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

/**
 * @brief Draws right-aligned text from a C-string
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Null-terminated C-string
 * @param aColor Color/inversion flag
 */
void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                               const char *text, unsigned char aColor)
{
  uint8_t textLen = strlen(text);
  uint8_t offset = calcRightOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

/**
 * @brief Draws left-aligned text from a flash string
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Flash string stored in PROGMEM
 * @param aColor Color/inversion flag
 */
void ScreenBase::TextLeft(Coor aPosition, Coor aSize,
                              const __FlashStringHelper *text, unsigned char aColor)
{
  uint8_t textLen = flashStrLen(text);
  uint8_t offset = calcLeftOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

/**
 * @brief Draws center-aligned text from a flash string
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Flash string stored in PROGMEM
 * @param aColor Color/inversion flag
 */
void ScreenBase::TextCenter(Coor aPosition, Coor aSize,
                                const __FlashStringHelper *text, unsigned char aColor)
{
  uint8_t textLen = flashStrLen(text);
  uint8_t offset = calcCenterOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

/**
 * @brief Draws right-aligned text from a flash string
 * 
 * @param aPosition Top-left position of the text area
 * @param aSize Size of the text area
 * @param text Flash string stored in PROGMEM
 * @param aColor Color/inversion flag
 */
void ScreenBase::TextRight(Coor aPosition, Coor aSize,
                               const __FlashStringHelper *text, unsigned char aColor)
{
  uint8_t textLen = flashStrLen(text);
  uint8_t offset = calcRightOffset(aSize, textLen);
  printTextInArea(aPosition, aSize, text, aColor, offset);
}

/**
 * @brief Clears a single tile at the specified position
 * 
 * @param aPosition Position of the tile to clear
 * @param aColor Fill color (0 = clear, 1 = fill)
 */
void ScreenBase::ClearTile(Coor aPosition, unsigned char aColor)
{
  DrawSymbol(aPosition, Coor(1, 1), ' ', 0);
}

/**
 * @brief Draws a pictogram at the specified position (default implementation)
 * 
 * @param aPosition Position on screen
 * @param pictoData Pointer to pictogram data
 * @param aColor Color/inversion flag
 */
void evab::ScreenBase::Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor)
{
}

/**
 * @brief Clears a rectangular area on the screen
 * 
 * @param aPosition Top-left position of the area
 * @param aSize Size of the area to clear
 * @param aColor Fill color (0 = clear, 1 = fill)
 */
void ScreenBase::Clear(Coor aPosition, Coor aSize, unsigned char aColor)
{
  Coor displaySize = Size();
  for (uint8_t x = 0; x < aSize.X; x++)
  {
    for (uint8_t y = 0; y < aSize.Y; y++)
    {
      Coor clearPos(aPosition.X + x, aPosition.Y + y);
      if (clearPos.X < displaySize.X && clearPos.Y < displaySize.Y)
      {
        ClearTile(clearPos, aColor);
      }
    }
  }
}
