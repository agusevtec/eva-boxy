#include "evabDebugPlatform.h"
#include <Arduino.h>
#define SIZEX 15
#define SIZEY 8

namespace evab
{

  DebugPlatform::DebugPlatform() : t(2000, this)
  {
    Serial.begin(9600);
    for (int i = 0; i < SIZEY; i++)
      strcpy(mField[i], "************");
  }

  void DebugPlatform::Fill(const char aGlyph, Coor aPos, Coor aSize, unsigned char aMarkup)
  {
  //  (void)aMarkup;
    if (aPos.X >= SIZEX || aPos.Y >= SIZEY)
      return;
    aSize.X = min(aSize.X, (SIZEX - aPos.X));
    memset(&mField[aPos.Y][aPos.X], aGlyph, aSize.X);
  }

  void DebugPlatform::Display(Coor aPos, Coor aSize, const char *aText, unsigned char aAlign, unsigned char aMarkup)
  {
//    (void)aAlign;
    if (aPos.X >= SIZEX || aPos.Y >= SIZEY)
      return;
    aSize.X = min(aSize.X, (SIZEX - aPos.X));
    if (aMarkup)
      memset(&mField[aPos.Y][aPos.X], '#', aSize.X);
    else
      memset(&mField[aPos.Y][aPos.X], ' ', aSize.X);
    memcpy(&mField[aPos.Y][aPos.X], aText, min(aSize.X, strlen(aText)));
  }

  Coor DebugPlatform::Size()
  {
    return {SIZEX, SIZEY};
  }

  void DebugPlatform::invoke(void *msgSender, eva::CallbackInfo cbInfo)
  {
    (void)msgSender;
    (void)cbInfo;
    Serial.println("--------------");
    for (int i = 0; i < SIZEY; i++)
    {
      Serial.print('|');
      Serial.print(mField[i]);
      Serial.println('|');
    }
    Serial.println("--------------");
  }

}
