#pragma once
#include <evabElementBase.h>
#include <evabTilesetsStretchy.h>

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

    struct CharsetVerticalProgressBar
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

    struct CharsetHorizontalProgressBar
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

        struct CharsetVerticalScrollBar
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

    struct CharsetHorizontalScrollBar
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

    template <typename TTileset, typename OrientationTextPolicy>
    class InputTextStretchBar : public ElementBase
    {
    public:
        InputTextStretchBar(unsigned char aValue = 0)
        {
            mValue = constrain(aValue, 0, 100);
        }

        void SetValue(unsigned char aValue)
        {
            mValue = constrain(aValue, 0, 100);
            Redraw();
        }

        void Increment(signed char delta)
        {
            SetValue(mValue + delta);
        }

    private:
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            unsigned short resolution = OrientationTextPolicy::CalculateResolution(aSize);
            unsigned short normalizedValue = map(mValue, 0, 100, 0, resolution);
            unsigned char totalBlocks = OrientationTextPolicy::CalculateTotalBlocks(aSize);

            if (totalBlocks < 2)
                return;

            for (unsigned char i = 0; i < totalBlocks; i++)
            {
                aScreen->DrawSymbol(
                    OrientationTextPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                    {1, 1},
                    TTileset::GetChar(blockFill(i, normalizedValue)),
                    aIsFocused);
            }
        }

        char blockFill(unsigned char blockNumber, unsigned short normalizedValue)
        {
            if (normalizedValue > blockNumber)
                return 0;
            if (normalizedValue < blockNumber)
                return 2;
            return 1;
        }

        unsigned char mValue;
    };

    using TextVerticalProgressBar = InputTextStretchBar<CharsetVerticalProgressBar, VerticalTextPolicy>;
    using TextHorizontalProgressBar = InputTextStretchBar<CharsetHorizontalProgressBar, HorizontalTextPolicy>;
    using TextVerticalScrollBar = InputTextStretchBar<CharsetVerticalScrollBar, VerticalTextPolicy>;
    using TextHorizontalScrollBar = InputTextStretchBar<CharsetHorizontalScrollBar, HorizontalTextPolicy>;
}