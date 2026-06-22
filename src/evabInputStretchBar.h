#pragma once

#include <evabElementBase.h>
#include <evabTilesetsStretchy.h>

namespace evab
{
    struct VerticalPictoPolicy
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
    };

    struct HorizontalPictoPolicy
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
    };

    template <typename TTileset, typename OrientationPictoPolicy>
    class InputStretchBar : public ElementBase
    {
    public:
        InputStretchBar(unsigned char aValue = 0)
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
        static constexpr unsigned char START_BLOCK = 1;
        static constexpr unsigned char MIDDLE_BLOCK = 2;
        static constexpr unsigned char END_BLOCK = 3;

        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            unsigned short resolution = OrientationPictoPolicy::CalculateResolution(aSize);
            unsigned short normalizedValue = map(mValue, 0, 100, 0, resolution);
            unsigned char totalBlocks = OrientationPictoPolicy::CalculateTotalBlocks(aSize);

            if (totalBlocks < 2)
                return;

            aScreen->Picto(
                OrientationPictoPolicy::GetTilePosition(aPos, aSize, 0, totalBlocks),
                TTileset::GetTile(START_BLOCK, blockFill(0, normalizedValue)),
                aIsFocused);

            for (unsigned char i = 1; i < totalBlocks - 1; i++)
            {
                aScreen->Picto(
                    OrientationPictoPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                    TTileset::GetTile(MIDDLE_BLOCK, blockFill(i, normalizedValue)),
                    aIsFocused);
            }

            aScreen->Picto(
                OrientationPictoPolicy::GetTilePosition(aPos, aSize, totalBlocks - 1, totalBlocks),
                TTileset::GetTile(END_BLOCK, blockFill(totalBlocks - 1, normalizedValue)),
                aIsFocused);
        }

        char blockFill(unsigned char blockNumber, unsigned short normalizedValue)
        {
            if (normalizedValue / 3 < blockNumber)
                return 0;
            if (normalizedValue / 3 > blockNumber)
                return 4;
            return normalizedValue % 3 + 1;
        }

        unsigned char mValue;
    };

    using VerticalProgressBar = InputStretchBar<TilesetVerticalProgressBar, VerticalPictoPolicy>;
    using HorizontalProgressBar = InputStretchBar<TilesetHorizontalProgressBar, HorizontalPictoPolicy>;
    using VerticalScrollBar = InputStretchBar<TilesetVerticalScrollBar, VerticalPictoPolicy>;
    using HorizontalScrollBar = InputStretchBar<TilesetHorizontalScrollBar, HorizontalPictoPolicy>;
}