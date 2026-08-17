// evabBoxyRest.cpp
#include "evabGrid.h"

using namespace evab;

Grid::Grid(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
    : mTopLeft(aPos), mBottomRight({aPos.X + aSize.X, aPos.Y + aSize.Y}), mIsFocused(aIsFocused), mScreen(aScreen)
{
}

Grid Grid::CutRow(unsigned char aHeight)
{
    if (aHeight == 0)
        aHeight = mBottomRight.Y - mTopLeft.Y;

    Coor rowTopLeft = mTopLeft;
    Coor rowSize = {mBottomRight.X - mTopLeft.X, aHeight};

    mTopLeft.Y += aHeight;

    return Grid(mScreen, rowTopLeft, rowSize, mIsFocused);
}

Grid Grid::CutCol(unsigned char aWidth)
{
    if (aWidth == 0)
        aWidth = mBottomRight.X - mTopLeft.X;

    Coor colTopLeft = mTopLeft;
    Coor colSize = {aWidth, mBottomRight.Y - mTopLeft.Y};

    mTopLeft.X += aWidth;

    return Grid(mScreen, colTopLeft, colSize, mIsFocused);
}

Coor Grid::GetSize() const
{
    int width = mBottomRight.X - mTopLeft.X;
    int height = mBottomRight.Y - mTopLeft.Y;

    if (width < 0)
        width = 0;
    if (height < 0)
        height = 0;

    return Coor(width, height);
}

void Grid::Draw(ElementBase &aElement, unsigned char aIsFocused)
{
    if (mScreen)
        aElement.Draw(mScreen, mTopLeft, GetSize(), mIsFocused && aIsFocused);
}

void Grid::Picto(const unsigned char *aPictogram, unsigned char aIsFocused)
{
    if (mScreen)
        mScreen->Picto(mTopLeft, aPictogram, mIsFocused && aIsFocused);
}

void Grid::Clear(unsigned char aIsFocused)
{
    if (mScreen)
        mScreen->Clear(mTopLeft, GetSize(), aIsFocused);
}
