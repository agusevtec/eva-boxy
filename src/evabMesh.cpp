// evabMesh.cpp
#include "evabMesh.h"

using namespace evab;

Mesh::Mesh(Coor aPos, Coor aSize)
    : mTopLeft(aPos)
    , mBottomRight({aPos.X + aSize.X, aPos.Y + aSize.Y})
{
}

Mesh Mesh::NextRow(unsigned char aHeight)
{
    if (aHeight == 0)
        aHeight = mBottomRight.Y - mTopLeft.Y;
    
    Coor rowTopLeft = mTopLeft;
    Coor rowSize = {mBottomRight.X - mTopLeft.X, aHeight};
    
    mTopLeft.Y += aHeight;
    
    return Mesh(rowTopLeft, rowSize);
}

Mesh Mesh::NextCol(unsigned char aWidth)
{
    if (aWidth == 0)
        aWidth = mBottomRight.X - mTopLeft.X;
    
    Coor colTopLeft = mTopLeft;
    Coor colSize = {aWidth, mBottomRight.Y - mTopLeft.Y};
    
    mTopLeft.X += aWidth;
    
    return Mesh(colTopLeft, colSize);
}

Mesh Mesh::Rest()
{
    return Mesh(mTopLeft, GetSize());
}

Coor Mesh::GetSize() const
{
    int width = mBottomRight.X - mTopLeft.X;
    int height = mBottomRight.Y - mTopLeft.Y;
    
    if (width < 0) width = 0;
    if (height < 0) height = 0;
    
    return Coor(width, height);
}

Place Mesh::GetPlace() const
{
    return Place(mTopLeft, GetSize());
}

void Mesh::Draw(IScreen *aScreen, ElementBase *aElement, unsigned char aIsFocused)
{
    if (aElement && aScreen)
        aElement->Draw(aScreen, mTopLeft, GetSize(), aIsFocused);
}

void Mesh::Clean(IScreen *aScreen)
{
    if (aScreen)
        aScreen->Clear(mTopLeft, GetSize(), 0);
}