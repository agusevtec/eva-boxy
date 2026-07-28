// evabMesh.cpp
#include "evabGrid.h"

using namespace evab;

Grid::Grid(Coor aPos, Coor aSize)
    : mTopLeft(aPos)
    , mBottomRight({aPos.X + aSize.X, aPos.Y + aSize.Y})
{
}

Grid Grid::NextRow(unsigned char aHeight)
{
    if (aHeight == 0)
        aHeight = mBottomRight.Y - mTopLeft.Y;
    
    Coor rowTopLeft = mTopLeft;
    Coor rowSize = {mBottomRight.X - mTopLeft.X, aHeight};
    
    mTopLeft.Y += aHeight;
    
    return Grid(rowTopLeft, rowSize);
}

Grid Grid::NextCol(unsigned char aWidth)
{
    if (aWidth == 0)
        aWidth = mBottomRight.X - mTopLeft.X;
    
    Coor colTopLeft = mTopLeft;
    Coor colSize = {aWidth, mBottomRight.Y - mTopLeft.Y};
    
    mTopLeft.X += aWidth;
    
    return Grid(colTopLeft, colSize);
}

Grid& Grid::Rest()
{
    return *this;
}

Coor Grid::GetSize() const
{
    int width = mBottomRight.X - mTopLeft.X;
    int height = mBottomRight.Y - mTopLeft.Y;
    
    if (width < 0) width = 0;
    if (height < 0) height = 0;
    
    return Coor(width, height);
}

Place Grid::GetPlace() const
{
    return Place(mTopLeft, GetSize());
}

void Grid::Draw(IScreen *aScreen, ElementBase *aElement, unsigned char aIsFocused)
{
    if (aElement && aScreen)
        aElement->Draw(aScreen, mTopLeft, GetSize(), aIsFocused);
}

void Grid::Clean(IScreen *aScreen)
{
    if (aScreen)
        aScreen->Clear(mTopLeft, GetSize(), 0);
}