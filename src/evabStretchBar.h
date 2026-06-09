#include <evabElementBase.h>
#include <evabStretchyTilesets.h>
namespace evab
{
    struct VerticalPolicy
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

    struct HorizontalPolicy
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

    template <typename TileSet, typename OrientationPolicy>
    class StretchBar : public ElementBase
    {
    public:
        StretchBar(unsigned char aValue) 
        {
            SetValue(aValue);
        }

        void SetValue(unsigned char aValue)
        {
            mValue = constrain(aValue, 0, 100);
        }

    private:
        static constexpr unsigned char START_BLOCK = 1;
        static constexpr unsigned char MIDDLE_BLOCK = 2;
        static constexpr unsigned char END_BLOCK = 3;

        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            unsigned short resolution = OrientationPolicy::CalculateResolution(aSize);
            unsigned short normalizedValue = map(mValue, 0, 100, 0, resolution);
            unsigned char totalBlocks = OrientationPolicy::CalculateTotalBlocks(aSize);

            if (totalBlocks < 2)
                return;

            aScreen->Picto(
                OrientationPolicy::GetTilePosition(aPos, aSize, 0, totalBlocks),
                TileSet::GetTile(START_BLOCK, blockFill(0, normalizedValue)),
                aIsFocused);

            for (unsigned char i = 1; i < totalBlocks - 1; i++)
            {
                aScreen->Picto(
                    OrientationPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                    TileSet::GetTile(MIDDLE_BLOCK, blockFill(i, normalizedValue)),
                    aIsFocused);
            }

            aScreen->Picto(
                OrientationPolicy::GetTilePosition(aPos, aSize, totalBlocks - 1, totalBlocks),
                TileSet::GetTile(END_BLOCK, blockFill(totalBlocks - 1, normalizedValue)),
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

    template <typename TileSet>
    using VStretchBar = StretchBar<TileSet, VerticalPolicy>;
    template <typename TileSet>
    using HStretchBar = StretchBar<TileSet, HorizontalPolicy>;

    using VProgressBar = VStretchBar<TilesetVProgressbar>;
    using HProgressBar = HStretchBar<TilesetHProgressbar>;
    using VScrollBar = VStretchBar<TilesetVScrollbar>;
    using HScrollBar = HStretchBar<TilesetHScrollbar>;
}