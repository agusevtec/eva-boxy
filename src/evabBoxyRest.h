// evabBoxyRest.h
#pragma once

#include <evabElementBase.h>
#include <evabScreen.h>

namespace evab
{

    /**
     * @brief Layout manager for rest-based UI arrangement
     *
     * BoxyRest provides a fluent interface for organizing UI elements in a rest.
     * Each CutRows()/CutCols() returns a new BoxyRest representing the cell.
     *
     * @code
     * BoxyRest rest({0,0}, {16,8});
     * rest.CutRows(2).Draw(element1);
     * rest.CutRows(2).CutCols(2).Draw(element2);
     * rest.CutRows(2).CutCols(2).Clear();
     * rest.Clear();
     * @endcode
     */
    class BoxyRest
    {
    public:
        /**
         * @brief Constructs a BoxyRest for a specific area
         *
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the rest area
         */
        BoxyRest(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);

        /**
         * @brief Creates a new BoxyRest for the next row
         *
         * @param aHeight Height of the row (0 = use remaining height)
         * @return BoxyRest New rest representing the row
         */
        BoxyRest CutRows(unsigned char aHeight = 0);

        /**
         * @brief Creates a new BoxyRest for the next column
         *
         * @param aWidth Width of the column (0 = use remaining width)
         * @return BoxyRest New rest representing the column
         */
        BoxyRest CutCols(unsigned char aWidth = 0);

        /**
         * @brief Draws an element in the current cell
         *
         * @param aElement Element to draw
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void Draw(ElementBase &aElement, unsigned char aIsFocused = 0);

        /**
         * @brief Draws text with specified alignment
         *
         * @tparam TAlign Alignment strategy (LeftAlign, CenterAlign, RightAlign)
         * @tparam TText Text type
         * @param aText Text to draw
         * @param aIsFocused Color/inversion flag
         */
        template <typename TAlign, typename TText>
        void Text(TText aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->Text<TAlign>(mTopLeft, GetSize(), aText, aIsFocused);
        }

        /**
         * @brief Draws left-aligned text
         */
        template <typename T>
        void TextLeft(T aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->TextLeft(mTopLeft, GetSize(), aText, mIsFocused && aIsFocused);
        }

        /**
         * @brief Draws center-aligned text
         */
        template <typename T>
        void TextCenter(T aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->TextCenter(mTopLeft, GetSize(), aText, mIsFocused && aIsFocused);
        }

        /**
         * @brief Draws right-aligned text
         */
        template <typename T>
        void TextRight(T aText, unsigned char aIsFocused = 0)
        {
            if (mScreen)
                mScreen->TextRight(mTopLeft, GetSize(), aText, mIsFocused && aIsFocused);
        }

        /**
         * @brief Draws a pictogram in the current cell
         *
         * @param aPictogram Pictogram data
         * @param aIsFocused Color/inversion flag
         */
        void Picto(const unsigned char *aPictogram, unsigned char aIsFocused = 0);


        /**
         * @brief Clears the current cell area
         */
        void Clear(unsigned char aIsFocused = 0);

        /**
         * @brief Gets the current position
         *
         * @return Coor Current position
         */
        Coor GetPos() const { return mTopLeft; }

        /**
         * @brief Gets the current size
         *
         * @return Coor Current size (clamped to non-negative values)
         */
        Coor GetSize() const;


    private:
        Coor mTopLeft;         ///< Top-left corner of current cell
        Coor mBottomRight;     ///< Bottom-right corner of current cell
        unsigned char mIsFocused;
        const Screen *mScreen; ///< Screen to draw on
    };

}