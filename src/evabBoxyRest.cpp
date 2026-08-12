// evabBoxyRest.cpp
#include "evabBoxyRest.h"

using namespace evab;

BoxyRest::BoxyRest(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
    : mTopLeft(aPos), mBottomRight({aPos.X + aSize.X, aPos.Y + aSize.Y}), mIsFocused(aIsFocused), mScreen(aScreen)
{
}

BoxyRest BoxyRest::CutRow(unsigned char aHeight)
{
    if (aHeight == 0)
        aHeight = mBottomRight.Y - mTopLeft.Y;

    Coor rowTopLeft = mTopLeft;
    Coor rowSize = {mBottomRight.X - mTopLeft.X, aHeight};

    mTopLeft.Y += aHeight;

    return BoxyRest(mScreen, rowTopLeft, rowSize, mIsFocused);
}

BoxyRest BoxyRest::CutCol(unsigned char aWidth)
{
    if (aWidth == 0)
        aWidth = mBottomRight.X - mTopLeft.X;

    Coor colTopLeft = mTopLeft;
    Coor colSize = {aWidth, mBottomRight.Y - mTopLeft.Y};

    mTopLeft.X += aWidth;

    return BoxyRest(mScreen, colTopLeft, colSize, mIsFocused);
}

BoxyRest &BoxyRest::Rest()
{
    return *this;
}

Coor BoxyRest::GetSize() const
{
    int width = mBottomRight.X - mTopLeft.X;
    int height = mBottomRight.Y - mTopLeft.Y;

    if (width < 0)
        width = 0;
    if (height < 0)
        height = 0;

    return Coor(width, height);
}

void BoxyRest::Draw(ElementBase &aElement, unsigned char aIsFocused)
{
    if (mScreen)
        aElement.Draw(mScreen, mTopLeft, GetSize(), mIsFocused && aIsFocused);
}

void BoxyRest::Picto(const unsigned char *aPictogram, unsigned char aIsFocused = 0)
{
    if (mScreen)
        mScreen->Picto(mTopLeft, aPictogram, mIsFocused && aIsFocused);
}

void BoxyRest::Clear(unsigned char aIsFocused)
{
    if (mScreen)
        mScreen->Clear(mTopLeft, GetSize(), aIsFocused);
}
