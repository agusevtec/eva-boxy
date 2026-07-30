// evabGrid.cpp
#include "evabGrid.h"

using namespace evab;

Grid::Grid(Screen *aScreen, Coor aPos, Coor aSize)
    : mTopLeft(aPos)
    , mBottomRight({aPos.X + aSize.X, aPos.Y + aSize.Y})
    , mScreen(aScreen)
{
}

Grid Grid::SliceRow(unsigned char aHeight)
{
    if (aHeight == 0)
        aHeight = mBottomRight.Y - mTopLeft.Y;
    
    Coor rowTopLeft = mTopLeft;
    Coor rowSize = {mBottomRight.X - mTopLeft.X, aHeight};
    
    mTopLeft.Y += aHeight;
    
    return Grid(mScreen, rowTopLeft, rowSize);
}

Grid Grid::SliceCol(unsigned char aWidth)
{
    if (aWidth == 0)
        aWidth = mBottomRight.X - mTopLeft.X;
    
    Coor colTopLeft = mTopLeft;
    Coor colSize = {aWidth, mBottomRight.Y - mTopLeft.Y};
    
    mTopLeft.X += aWidth;
    
    return Grid (mScreen, colTopLeft, colSize);
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

void Grid::Draw(ElementBase *aElement, unsigned char aIsFocused)
{
    if (aElement && mScreen)
        aElement->Draw(mScreen, mTopLeft, GetSize(), aIsFocused);
}