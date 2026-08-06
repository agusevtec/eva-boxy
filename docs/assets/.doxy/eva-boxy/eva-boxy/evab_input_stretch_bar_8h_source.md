

# File evabInputStretchBar.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputStretchBar.h**](evab_input_stretch_bar_8h.md)

[Go to the documentation of this file](evab_input_stretch_bar_8h.md)


```C++
#pragma once

#include <evabElementBase.h>
#include <evabAlbumsStretchy.h>

namespace evab
{
    struct VerticalAlbumPolicy
    {
        static unsigned short CalculateTotalBlocks(Coor aSize)
        {
            return aSize.Y;
        }

        static unsigned short CalculateResolution(Coor aSize)
        {
            return 3 + (aSize.Y - 2) * 3 + 2;
        }

        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X, aPos.Y + aSize.Y - index - 1};
        }
        
        static Coor GetRestPosition(Coor aPos, Coor aSize)
        {
            return {aPos.X + 1, aPos.Y};
        }

        static Coor GetRestSize(Coor aPos, Coor aSize)
        {
            return {aSize.X - 1, aSize.Y};
        }
    };

    struct HorizontalAlbumPolicy
    {
        static unsigned short CalculateTotalBlocks(Coor aSize)
        {
            return aSize.X;
        }

        static unsigned short CalculateResolution(Coor aSize)
        {
            return 3 + (aSize.X - 2) * 3 + 2;
        }

        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X + index, aPos.Y};
        }
        static Coor GetRestPosition(Coor aPos, Coor aSize)
        {
            return {aPos.X, aPos.Y + 1};
        }
        static Coor GetRestSize(Coor aPos, Coor aSize)
        {
            return {aSize.X, aSize.Y - 1};
        }
    };

    template <typename TAlbumStretchy, typename OrientationAlbumPolicy>
    class InputStretchBar : public ElementBase
    {
    public:
        InputStretchBar(unsigned char aValue = 0, unsigned char aStep = 0)
            : mPercent(constrain(aValue, 0, 100)), mStep(aStep)
        {
        }

        void SetPercent(unsigned char aPercent)
        {
            aPercent = constrain(aPercent, 0, 100);
            if (mPercent == aPercent)
                return;
            mPercent = aPercent;
            redraw();
        }

        unsigned char GetPercent()
        {
            return mPercent;
        }

        void Increment(signed char delta)
        {
            SetPercent(mPercent + mStep * delta);
        }

    protected:
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            unsigned short resolution = OrientationAlbumPolicy::CalculateResolution(aSize);

            if (mStep == 0 && resolution > 0)
            {
                mStep = 100 / resolution + 1;
            }

            unsigned short normalizedValue = map(mPercent, 0, 100, 0, resolution);
            unsigned char totalBlocks = OrientationAlbumPolicy::CalculateTotalBlocks(aSize);

            if (totalBlocks < 2)
                return;

            aScreen->Picto(
                OrientationAlbumPolicy::GetTilePosition(aPos, aSize, 0, totalBlocks),
                TAlbumStretchy::GetTile(START_BLOCK, blockFill(0, normalizedValue)),
                aIsFocused);

            for (unsigned char i = 1; i < totalBlocks - 1; i++)
            {
                aScreen->Picto(
                    OrientationAlbumPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                    TAlbumStretchy::GetTile(MIDDLE_BLOCK, blockFill(i, normalizedValue)),
                    aIsFocused);
            }

            aScreen->Picto(
                OrientationAlbumPolicy::GetTilePosition(aPos, aSize, totalBlocks - 1, totalBlocks),
                TAlbumStretchy::GetTile(END_BLOCK, blockFill(totalBlocks - 1, normalizedValue)),
                aIsFocused);
            Coor clearAreaSize = OrientationAlbumPolicy::GetRestSize(aPos, aSize);
            if (clearAreaSize.X > 0 && clearAreaSize.Y > 0)
                aScreen->Clear(OrientationAlbumPolicy::GetRestPosition(aPos, aSize), clearAreaSize, aIsFocused);
        }

    private:
        char blockFill(unsigned char blockNumber, unsigned short normalizedValue)
        {
            if (normalizedValue / 3 < blockNumber)
                return 0;
            if (normalizedValue / 3 > blockNumber)
                return 4;
            return normalizedValue % 3 + 1;
        }

    private:
        static constexpr unsigned char START_BLOCK = 1;  
        static constexpr unsigned char MIDDLE_BLOCK = 2; 
        static constexpr unsigned char END_BLOCK = 3;    

        unsigned char mPercent; 
        unsigned char mStep;    
    };

    // Convenience typedefs for common stretch bar types
    using VerticalProgressBar = InputStretchBar<AlbumStretchyVerticalProgressBar, VerticalAlbumPolicy>;
    using HorizontalProgressBar = InputStretchBar<AlbumStretchyHorizontalProgressBar, HorizontalAlbumPolicy>;
    using VerticalScrollBar = InputStretchBar<AlbumStretchyVerticalScrollBar, VerticalAlbumPolicy>;
    using HorizontalScrollBar = InputStretchBar<AlbumStretchyHorizontalScrollBar, HorizontalAlbumPolicy>;
}
```


