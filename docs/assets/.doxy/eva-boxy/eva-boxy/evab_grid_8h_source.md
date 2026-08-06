

# File evabGrid.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabGrid.h**](evab_grid_8h.md)

[Go to the documentation of this file](evab_grid_8h.md)


```C++
// evabGrid.h
#pragma once

#include <evabElementBase.h>
#include <evabScreen.h>

namespace evab
{

    class Grid
    {
    public:
        Grid(Screen *aScreen, Coor aPos, Coor aSize);

        Grid SliceRow(unsigned char aHeight = 0);

        Grid SliceCol(unsigned char aWidth = 0);

        Grid &Rest();

        void Draw(ElementBase *aElement, unsigned char aIsFocused = 0);

        template <typename TAlign, typename TText>
        void Text(TText aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->Text<TAlign>(mTopLeft, GetSize(), aText, aColor);
        }

        template <typename T>
        void TextLeft(T aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->TextLeft(mTopLeft, GetSize(), aText, aColor);
        }

        template <typename T>
        void TextCenter(T aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->TextCenter(mTopLeft, GetSize(), aText, aColor);
        }

        template <typename T>
        void TextRight(T aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->TextRight(mTopLeft, GetSize(), aText, aColor);
        }

        void Picto(const unsigned char *aPictogram, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->Picto(mTopLeft, aPictogram, aColor);
        }

        void Clear()
        {
            if (mScreen)
                mScreen->Clear(mTopLeft, GetSize(), 0);
        }

        Coor GetPos() const { return mTopLeft; }

        Coor GetSize() const;


    private:
        Coor mTopLeft;         
        Coor mBottomRight;     
        const Screen *mScreen; 
    };

}
```


