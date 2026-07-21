#pragma once
#include <evabElementBase.h>
#include <evabPictosetsStretchy.h>

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
     * @tparam TPictoset Character set class providing GetChar method
     * @tparam OrientationTextPolicy Policy for orientation (vertical/horizontal)
     */
    template <typename TPictoset, typename OrientationTextPolicy>
    class InputTextStretchBar : public ElementBase
    {
    public:
        /**
         * @brief Constructor for InputTextStretchBar
         * 
         * @param aValue Initial value (0-100)
         */
        InputTextStretchBar(unsigned char aValue = 0)
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

    private:
        /**
         * @brief Draws the text stretch bar on screen
         * 
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
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
                    TPictoset::GetChar(blockFill(i, normalizedValue)),
                    aIsFocused);
            }
        }

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

        unsigned char mValue;  ///< Current value (0-100)
    };

    // Convenience typedefs for common text stretch bar types
    using TextVerticalProgressBar = InputTextStretchBar<CharsetVerticalProgressBar, VerticalTextPolicy>;
    using TextHorizontalProgressBar = InputTextStretchBar<CharsetHorizontalProgressBar, HorizontalTextPolicy>;
    using TextVerticalScrollBar = InputTextStretchBar<CharsetVerticalScrollBar, VerticalTextPolicy>;
    using TextHorizontalScrollBar = InputTextStretchBar<CharsetHorizontalScrollBar, HorizontalTextPolicy>;
}
