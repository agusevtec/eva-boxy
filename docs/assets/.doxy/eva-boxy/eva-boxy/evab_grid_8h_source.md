

# File evabGrid.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabGrid.h**](evab_grid_8h.md)

[Go to the documentation of this file](evab_grid_8h.md)


```C++
// evabMesh.h
#pragma once

#include <evabElementBase.h>
#include <evabScreen.h>

namespace evab
{

    class Grid
    {
    public:
        Grid(Coor aPos, Coor aSize);

        Grid SliceRow(unsigned char aHeight = 0);

        Grid SliceCol(unsigned char aWidth = 0);

        Grid& Rest();

        void Draw(Screen *aScreen, ElementBase *aElement, unsigned char aIsFocused = 0);

        void Blank(Screen *aScreen);

        Coor GetPos() const { return mTopLeft; }

        Coor GetSize() const;

    private:
        Coor mTopLeft;      
        Coor mBottomRight;  
    };

}
```


