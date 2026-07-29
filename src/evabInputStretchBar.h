#pragma once

#include <evabElementBase.h>
#include <evabAlbumsStretchy.h>

namespace evab
{
    /**
     * @brief Policy for vertical orientation of stretch bars
     */
    struct VerticalAlbumPolicy
    {
        /**
         * @brief Calculates total number of blocks
         *
         * @param aSize Size of the element
         * @return Total number of blocks
         */
        static unsigned short CalculateTotalBlocks(Coor aSize)
        {
            return aSize.Y;
        }

        /**
         * @brief Calculates resolution (number of possible positions)
         *
         * @param aSize Size of the element
         * @return Resolution value
         */
        static unsigned short CalculateResolution(Coor aSize)
        {
            return 3 + (aSize.Y - 2) * 3 + 2;
        }

        /**
         * @brief Gets position of a block
         *
         * @param aPos Base position
         * @param aSize Size of the element
         * @param index Block index
         * @param total Total number of blocks
         * @return Position of the block
         */
        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X, aPos.Y + aSize.Y - index - 1};
        }
    };

    /**
     * @brief Policy for horizontal orientation of stretch bars
     */
    struct HorizontalAlbumPolicy
    {
        /**
         * @brief Calculates total number of blocks
         *
         * @param aSize Size of the element
         * @return Total number of blocks
         */
        static unsigned short CalculateTotalBlocks(Coor aSize)
        {
            return aSize.X;
        }

        /**
         * @brief Calculates resolution (number of possible positions)
         *
         * @param aSize Size of the element
         * @return Resolution value
         */
        static unsigned short CalculateResolution(Coor aSize)
        {
            return 3 + (aSize.X - 2) * 3 + 2;
        }

        /**
         * @brief Gets position of a block
         *
         * @param aPos Base position
         * @param aSize Size of the element
         * @param index Block index
         * @param total Total number of blocks
         * @return Position of the block
         */
        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X + index, aPos.Y};
        }
    };

    /**
     * @brief Stretch bar input element with Albumgram support
     *
     * Displays a progress/scroll bar using Albumgrams with variable fill levels.
     *
     * @tparam TAlbumStretchy Album class providing Albumgram data
     * @tparam OrientationAlbumPolicy Policy for orientation (vertical/horizontal)
     */
    template <typename TAlbumStretchy, typename OrientationAlbumPolicy>
    class InputStretchBar : public ElementBase
    {
    public:
        /**
         * @brief Constructor for InputStretchBar
         *
         * @param aValue Initial value (0-100)
         */
        InputStretchBar(unsigned char aValue = 0)
        {
            mValue = constrain(aValue, 0, 100);
        }

        /**
         * @brief Sets the value and redraws
         *
         * @param aValue New value (0-100)
         */
        void SetValue(unsigned char aValue)
        {
            if (mValue == aValue)
                 return;
            mValue = constrain(aValue, 0, 100);
            Redraw();
        }

        /**
         * @brief Increments the value by a delta
         *
         * @param delta Amount to add (positive or negative)
         */
        void Increment(signed char delta)
        {
            SetValue(mValue + delta);
        }

    protected:
        /**
         * @brief Draws the stretch bar on screen
         *
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            unsigned short resolution = OrientationAlbumPolicy::CalculateResolution(aSize);
            unsigned short normalizedValue = map(mValue, 0, 100, 0, resolution);
            unsigned char totalBlocks = OrientationAlbumPolicy::CalculateTotalBlocks(aSize);

            if (totalBlocks < 2)
                return;

            aScreen->Album(
                OrientationAlbumPolicy::GetTilePosition(aPos, aSize, 0, totalBlocks),
                TAlbumStretchy::GetTile(START_BLOCK, blockFill(0, normalizedValue)),
                aIsFocused);

            for (unsigned char i = 1; i < totalBlocks - 1; i++)
            {
                aScreen->Album(
                    OrientationAlbumPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                    TAlbumStretchy::GetTile(MIDDLE_BLOCK, blockFill(i, normalizedValue)),
                    aIsFocused);
            }

            aScreen->Album(
                OrientationAlbumPolicy::GetTilePosition(aPos, aSize, totalBlocks - 1, totalBlocks),
                TAlbumStretchy::GetTile(END_BLOCK, blockFill(totalBlocks - 1, normalizedValue)),
                aIsFocused);
        }

    private:
        /**
         * @brief Calculates fill level for a block
         *
         * @param blockNumber Block index
         * @param normalizedValue Normalized value (0 to resolution)
         * @return Fill level (0-4)
         */
        char blockFill(unsigned char blockNumber, unsigned short normalizedValue)
        {
            if (normalizedValue / 3 < blockNumber)
                return 0;
            if (normalizedValue / 3 > blockNumber)
                return 4;
            return normalizedValue % 3 + 1;
        }

    private:
        static constexpr unsigned char START_BLOCK = 1;  ///< Start block type
        static constexpr unsigned char MIDDLE_BLOCK = 2; ///< Middle block type
        static constexpr unsigned char END_BLOCK = 3;    ///< End block type

        unsigned char mValue; ///< Current value (0-100)
    };

    // Convenience typedefs for common stretch bar types
    using VerticalProgressBar = InputStretchBar<AlbumStretchyVerticalProgressBar, VerticalAlbumPolicy>;
    using HorizontalProgressBar = InputStretchBar<AlbumStretchyHorizontalProgressBar, HorizontalAlbumPolicy>;
    using VerticalScrollBar = InputStretchBar<AlbumStretchyVerticalScrollBar, VerticalAlbumPolicy>;
    using HorizontalScrollBar = InputStretchBar<AlbumStretchyHorizontalScrollBar, HorizontalAlbumPolicy>;
}
