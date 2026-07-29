#include <evabInputButtonPicto.h>

using namespace evab;

InputButtonPicto::InputButtonPicto(const unsigned char *aaPictogramm) : maPictogramm(aaPictogramm)
{
}


void InputButtonPicto::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
    aScreen->Picto(aPos, maPictogramm, aIsFocused);
    // for (int i = 1; i < aSize.Y; i++)
    //     aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
}
