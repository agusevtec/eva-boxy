

# File evabGrid.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabGrid.h**](evab_grid_8h.md)

[Go to the documentation of this file](evab_grid_8h.md)


```C++
// evabBoxyRest.h
#pragma once

#include <evabElementBase.h>
#include <evabScreen.h>

namespace evab
{

    class BoxyRest
    {
    public:
        BoxyRest(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);

        BoxyRest CutRows(unsigned char aHeight = 0);

        BoxyRest CutCols(unsigned char aWidth = 0);

        BoxyRest &Rest();

        void Draw(ElementBase &aElement, unsigned char aIsFocused = 0);

        template <typename TAlign, typename TText>
        void Text(TText aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->Text<TAlign>(mTopLeft, GetSize(), aText, aIsFocused);
        }

        template <typename T>
        void TextLeft(T aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->TextLeft(mTopLeft, GetSize(), aText, mIsFocused && aIsFocused);
        }

        template <typename T>
        void TextCenter(T aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->TextCenter(mTopLeft, GetSize(), aText, mIsFocused && aIsFocused);
        }

        template <typename T>
        void TextRight(T aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->TextRight(mTopLeft, GetSize(), aText, mIsFocused && aIsFocused);
        }

        void Picto(const unsigned char *aPictogram, unsigned char aIsFocused = 0);


        void Clear(unsigned char aIsFocused = 0);

        Coor GetPos() const { return mTopLeft; }

        Coor GetSize() const;


    private:
        Coor mTopLeft;         
        Coor mBottomRight;     
        unsigned char mIsFocused;
        const Screen *mScreen; 
    };

}
```


