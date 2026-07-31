#pragma once
#include <evabElementBase.h>
#include <evabAlbumsStretchy.h>

namespace evab
{
    /**
     * @brief Policy for vertical text-based stretch bars
     */
    struct VerticalTextPolicy
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
            return 1 + (aSize.Y - 2) * 1 + 1;
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
     * @brief Policy for horizontal text-based stretch bars
     */
    struct HorizontalTextPolicy
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
            return 1 + (aSize.X - 2) * 1 + 1;
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
     * @brief Character set for vertical progress bar
     */
    struct CharsetVerticalProgressBar
    {
        /**
         * @brief Gets character for fill level
         *
         * @param fillLevel Fill level (0-2)
         * @return Character to display
         */
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

    /**
     * @brief Character set for horizontal progress bar
     */
    struct CharsetHorizontalProgressBar
    {
        /**
         * @brief Gets character for fill level
         *
         * @param fillLevel Fill level (0-2)
         * @return Character to display
         */
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

    /**
     * @brief Character set for vertical scroll bar
     */
    struct CharsetVerticalScrollBar
    {
        /**
         * @brief Gets character for fill level
         *
         * @param fillLevel Fill level (0-2)
         * @return Character to display
         */
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

    /**
     * @brief Character set for horizontal scroll bar
     */
    struct CharsetHorizontalScrollBar
    {
        /**
         * @brief Gets character for fill level
         *
         * @param fillLevel Fill level (0-2)
         * @return Character to display
         */
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

    /**
     * @brief Text-based stretch bar element
     *
     * Displays a progress/scroll bar using characters instead of pictograms.
     *
     * @tparam TAlbum Character set class providing GetChar method
     * @tparam OrientationTextPolicy Policy for orientation (vertical/horizontal)
     */
    template <typename TAlbum, typename OrientationTextPolicy>
    class InputTextStretchBar : public ElementBase
    {
    public:
        /**
         * @brief Constructor for InputTextStretchBar
         *
         * @param aValue Initial percent value (0-100)
         * @param aStep Increment step (0 = auto-calculate from resolution)
         */
        InputTextStretchBar(unsigned char aValue = 0, unsigned char aStep = 0)
            : mPercent(constrain(aValue, 0, 100)), mStep(aStep)
        {
        }

        /**
         * @brief Sets the value and redraws
         *
         * @param aValue New value (0-100)
         */
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

        /**
         * @brief Increments the value by a delta
         *
         * @param delta Amount to add (positive or negative)
         */
        void Increment(signed char delta)
        {
            SetPercent(mPercent + mStep * delta);
        }

    protected:
        /**
         * @brief Draws the text stretch bar on screen
         *
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            unsigned short resolution = OrientationTextPolicy::CalculateResolution(aSize);
            if (mStep == 0 && resolution > 0)
            {
                mStep = 100 / resolution;
                if (mStep == 0)
                    mStep = 1;
            }
            unsigned short normalizedValue = map(mPercent, 0, 100, 0, resolution);
            unsigned char totalBlocks = OrientationTextPolicy::CalculateTotalBlocks(aSize);

            if (totalBlocks < 2)
                return;

            for (unsigned char i = 0; i < totalBlocks; i++)
            {
                aScreen->DrawSymbol(
                    OrientationTextPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                    {1, 1},
                    TAlbum::GetChar(blockFill(i, normalizedValue)),
                    aIsFocused);
            }
        }

    private:
        /**
         * @brief Calculates fill level for a block
         *
         * @param blockNumber Block index
         * @param normalizedValue Normalized value (0 to resolution)
         * @return Fill level (0-2)
         */
        char blockFill(unsigned char blockNumber, unsigned short normalizedValue)
        {
            if (normalizedValue > blockNumber)
                return 0;
            if (normalizedValue < blockNumber)
                return 2;
            return 1;
        }

    private:
        unsigned char mPercent; ///< Current percent value (0-100)
        unsigned char mStep;    ///< Increment step (0 = auto-calculate)
    };

    // Convenience typedefs for common text stretch bar types
    using TextVerticalProgressBar = InputTextStretchBar<CharsetVerticalProgressBar, VerticalTextPolicy>;
    using TextHorizontalProgressBar = InputTextStretchBar<CharsetHorizontalProgressBar, HorizontalTextPolicy>;
    using TextVerticalScrollBar = InputTextStretchBar<CharsetVerticalScrollBar, VerticalTextPolicy>;
    using TextHorizontalScrollBar = InputTextStretchBar<CharsetHorizontalScrollBar, HorizontalTextPolicy>;
}
