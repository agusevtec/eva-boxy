#include <evabInputButtonPicto.h>

using namespace evab;

InputButtonPicto::InputButtonPicto(const unsigned char *aaPictogram) : maPictogram(aaPictogram)
{
}


void InputButtonPicto::drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
    aScreen->Picto(aPos, maPictogram, aIsFocused);
    // for (int i = 1; i < aSize.Y; i++)
    //     aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
}
