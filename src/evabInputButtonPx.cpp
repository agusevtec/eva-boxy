#include <evabInputButtonPx.h>

using namespace evab;

InputButtonPx::InputButtonPx(const unsigned char *aPictogram) : mPictogram(aPictogram)
{
}

void InputButtonPx::drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
    aScreen->Picto(aPos, mPictogram, aIsFocused);
    // for (int i = 1; i < aSize.Y; i++)
    //     aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
}
