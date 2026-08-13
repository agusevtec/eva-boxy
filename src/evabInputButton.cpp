#include "evabInputButton.h"
#include <evabScreen.h>

using namespace evab;

// --- InputButton (RAM) ---

InputButton::InputButton(const char *aText) : mName(aText)
{
}

const char *InputButton::GetName() const
{
  return mName;
}

void InputButton::SetName(const char *aName)
{
  mName = aName;
  redraw();
}

void InputButton::drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
  if (!mName)
    return;
  // TODO: what if aSize.Y > 1?
  aScreen->DrawSymbol(aPos, {1, 1}, '(', aIsFocused);
  aScreen->TextCenter({aPos.X + 1, aPos.Y}, {aSize.X - 2, 1}, mName, aIsFocused);
  aScreen->DrawSymbol({aPos.X + aSize.X - 1, aPos.Y}, {1, 1}, ')', aIsFocused);
  for (int i = 1; i < aSize.Y; i++)
    aScreen->Clear({aPos.X, aPos.Y + i}, {aSize.X, 1}, aIsFocused);
}

// --- InputButtonF (Flash / PROGMEM) ---

InputButtonF::InputButtonF(const __FlashStringHelper *aText) : mName(aText)
{
}

const __FlashStringHelper *InputButtonF::GetName() const
{
  return mName;
}

void InputButtonF::SetName(const __FlashStringHelper *aName)
{
  mName = aName;
  redraw();
}

void InputButtonF::drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
  if (!mName)
    return;
  // TODO: what if aSize.Y > 1?
  aScreen->DrawSymbol(aPos, {1, 1}, '(', aIsFocused);
  aScreen->TextCenter({aPos.X + 1, aPos.Y}, {aSize.X - 2, 1}, mName, aIsFocused);
  aScreen->DrawSymbol({aPos.X + aSize.X - 1, aPos.Y}, {1, 1}, ')', aIsFocused);
  for (int i = 1; i < aSize.Y; i++)
    aScreen->Clear({aPos.X, aPos.Y + i}, {aSize.X, 1}, aIsFocused);
}
