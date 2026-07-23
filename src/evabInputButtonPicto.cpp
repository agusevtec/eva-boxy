#include <evabInputButtonPicto.h>

using namespace evab;

InputButtonPicto::InputButtonPicto(const unsigned char *aPictoData) : mPictoData(aPictoData)
{
}


void InputButtonPicto::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
{
    aScreen->Picto(aPos, mPictoData, aIsFocused);
    // for (int i = 1; i < aSize.Y; i++)
    //     aScreen->Clear({aPos.X, aPos.Y + i}, aSize, aIsFocused);
}
