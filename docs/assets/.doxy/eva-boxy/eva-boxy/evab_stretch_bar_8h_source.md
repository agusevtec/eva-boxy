

# File evabStretchBar.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabStretchBar.h**](evab_stretch_bar_8h.md)

[Go to the documentation of this file](evab_stretch_bar_8h.md)


```C++
#pragma once

#include <evabElementBase.h>
#include <evabStretchBarPxResources.h>

namespace evab
{
    struct VerticalTextPolicy
    {
        static unsigned short CalculateTotalBlocks(Coor aSize)
        {
            return aSize.Y;
        }

        static unsigned short CalculateResolution(Coor aSize)
        {
            return 1 + (aSize.Y - 2) * 1 + 1;
        }

        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X, aPos.Y + aSize.Y - index - 1};
        }
    };

    struct HorizontalTextPolicy
    {
        static unsigned short CalculateTotalBlocks(Coor aSize)
        {
            return aSize.X;
        }

        static unsigned short CalculateResolution(Coor aSize)
        {
            return 1 + (aSize.X - 2) * 1 + 1;
        }

        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X + index, aPos.Y};
        }
    };

    struct VerticalProgressBarCharset
    {
        static char GetChar(unsigned char fillLevel)
        {
            switch (fillLevel)
            {
            case 0:
                return '#';
            case 1:
                return '#';
            case 2:
                return '|';
            }
            return ' ';
        }
    };

    struct HorizontalProgressBarCharset
    {
        static char GetChar(unsigned char fillLevel)
        {
            switch (fillLevel)
            {
            case 0:
                return '|';
            case 1:
                return '|';
            case 2:
                return '-';
            }
            return ' ';
        }
    };

    struct VerticalScrollBarCharset
    {
        static char GetChar(unsigned char fillLevel)
        {
            switch (fillLevel)
            {
            case 0:
                return '|';
            case 1:
                return '#';
            case 2:
                return '|';
            }
            return ' ';
        }
    };

    struct HorizontalScrollBarCharset
    {
        static char GetChar(unsigned char fillLevel)
        {
            switch (fillLevel)
            {
            case 0:
                return '-';
            case 1:
                return '|';
            case 2:
                return '-';
            }
            return ' ';
        }
    };

    template <typename TCharset, typename TOrientationTextPolicy>
    class StretchBar : public ElementBase
    {
    public:
        StretchBar(unsigned char aValue = 0, unsigned char aStep = 0)
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
            unsigned short resolution = TOrientationTextPolicy::CalculateResolution(aSize);
            if (mStep == 0 && resolution > 0)
            {
                mStep = 100 / resolution + 1;
            }
            unsigned short normalizedValue = map(mPercent, 0, 100, 0, resolution);
            unsigned char totalBlocks = TOrientationTextPolicy::CalculateTotalBlocks(aSize);

            if (totalBlocks < 2)
                return;

            for (unsigned char i = 0; i < totalBlocks; i++)
            {
                aScreen->DrawSymbol(
                    TOrientationTextPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                    {1, 1},
                    TCharset::GetChar(blockFill(i, normalizedValue)),
                    aIsFocused);
            }
        }

    private:
        char blockFill(unsigned char blockNumber, unsigned short normalizedValue)
        {
            if (normalizedValue > blockNumber)
                return 0;
            if (normalizedValue < blockNumber)
                return 2;
            return 1;
        }

    private:
        unsigned char mPercent; 
        unsigned char mStep;    
    };

    // Convenience typedefs for common text stretch bar types
    using VerticalProgressBar = StretchBar<VerticalProgressBarCharset, VerticalTextPolicy>;
    using HorizontalProgressBar = StretchBar<HorizontalProgressBarCharset, HorizontalTextPolicy>;
    using VerticalScrollBar = StretchBar<VerticalScrollBarCharset, VerticalTextPolicy>;
    using HorizontalScrollBar = StretchBar<HorizontalScrollBarCharset, HorizontalTextPolicy>;
}
```


