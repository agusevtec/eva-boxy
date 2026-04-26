#include "evabGyver1306Platform.h"
#include <Arduino.h>
#include <GyverOLED.h>

namespace evab
{

  GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
#define SIZE_X 15
#define SIZE_Y 8
#define WIDTH_X 6

  Gyver1306Platform::Gyver1306Platform()
  {
    oled.init();
    oled.clear();
    oled.textMode(BUF_REPLACE);
  }

  void Gyver1306Platform::Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup)
  {
    if (aPos.X > SIZE_X || aPos.Y > SIZE_Y)
      return;
    aSize.X = min(aSize.X, (SIZE_X - aPos.X));
    memset(mLine, aGlyph, aSize.X);
    mLine[aSize.X] = 0;
    oled.setScale(1);
    oled.invertText(aMarkup == 1);
    for (int i = aPos.Y; i < aPos.Y + aSize.Y; i++)
    {
      oled.setCursor(WIDTH_X * aPos.X + 18, i);
      oled.print(mLine);
    }
  }

  void Gyver1306Platform::Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup)
  {
    if (aPos.X > SIZE_X || aPos.Y > SIZE_Y)
      return;
    unsigned char arealen = min(aSize.X, (SIZE_X - aPos.X)) / aSize.Y;
    unsigned char textlen = min(strlen(aText), arealen);
    memset(mLine, ' ', arealen);
    if (aAlign == PA_LEFT)
      memcpy(mLine, aText, textlen);
    if (aAlign == PA_CENTER)
      memcpy(mLine + max(0, (arealen - textlen) / 2), aText, textlen);
    if (aAlign == PA_RIGHT)
      memcpy(mLine + max(0, arealen - textlen), aText, textlen);
    mLine[arealen] = 0;
    if (arealen * aSize.Y != aSize.X)
      if (aMarkup)
        oled.rect(18 + WIDTH_X * (aPos.X + arealen * aSize.Y), aPos.Y * 8, 18 + WIDTH_X * (aPos.X + aSize.X) - 1, (aPos.Y + aSize.Y) * 8 - 1);
      else
        oled.clear(18 + WIDTH_X * (aPos.X + arealen * aSize.Y), aPos.Y * 8, 18 + WIDTH_X * (aPos.X + aSize.X) - 1, (aPos.Y + aSize.Y) * 8 - 1);
    oled.setScale(aSize.Y);
    oled.invertText(aMarkup);
    oled.setCursor(WIDTH_X * aPos.X + 18, aPos.Y);
    oled.print(mLine);
  }

  Coor Gyver1306Platform::Size()
  {
    return {SIZE_X, SIZE_Y};
  }

}
